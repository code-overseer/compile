#include <utility>
#include <type_traits>

namespace compile
{
    template <class F, std::size_t... Is>
    void for_(F func, std::index_sequence<Is...>)
    {
      (func(std::integral_constant<std::size_t, Is>{}), ...);
    }

    template <std::size_t N, typename F>
    void for_(F func)
    {
        for_(func, std::make_index_sequence<N>());
    }
}
