#include <utility>

namespace compile
{
    namespace
    {
        template <typename T, T Arg, typename U>
        struct _Repeat;

        template <typename T, T Arg, std::size_t... N>
        struct _Repeat<T, Arg, std::index_sequence<N...>>
        {
            template<std::size_t V>
            struct Argument
            {
                static constexpr T value() { return Arg; }
            };
            static constexpr T value[]{(Argument<N>::value())...};
        };

        template <typename T>
        constexpr bool _cmp(std::size_t N, T const * a, T const * b) {
            return N == 0 || (*a == *b && _strcmp(N - 1, a + 1, b + 1));
        }
    }

    template <typename T, T Arg, std::size_t N>
    struct Repeat : _Repeat<T, Arg, std::make_index_sequence<N>> {};

    template<typename T, int N>
    constexpr bool cmp(T const (&a)[N], T const (&b)[N]) {
        return _cmp(N, a, b);
    }

    template<typename T, int L, int R>
    constexpr bool cmp(T const (&a)[L], T const (&b)[R]) {
        return false;
    }
}