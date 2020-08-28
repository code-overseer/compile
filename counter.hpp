#ifndef COMPILE_COUNTER_HPP
#define COMPILE_COUNTER_HPP

// counter only works on (non macOS) gcc afaik

namespace compile 
{
    class Counter 
    {
    private:
        template <int N>
        struct Flag
        {
            friend constexpr int get(Counter::Flag<N>);
            static constexpr int value = N;
        };
        
        template <int N>
        struct Write
        {
            friend constexpr int get(Counter::Flag<N>) { return N; }
            static constexpr int value = N;
        };
        
        template <int N, int = get(Counter::Flag<N>{})>
        static constexpr int read(int, Counter::Flag<N>, int R = read(0, Counter::Flag<N + 1>{})) { 
            return R; 
        }
        
        template <int N>
        static constexpr int read(float, Counter::Flag<N>) { return N; }
        
        template <int M = 0, int N = read(M, Counter::Flag<M>{}) + M>
        static constexpr int current() { return N; }
    public:    
        template <int N = 0>
        static constexpr int increment(int R = Write<read(0, Counter::Flag<0>{}) + N>::value) {
            return R;
        }
    };
}

#endif
