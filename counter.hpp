#ifndef COMPILE_COUNTER_HPP
#define COMPILE_COUNTER_HPP

namespace compile
{
    namespace
    {
        template <typename T> 
        class Flag
        {
            struct Trigger
            {
                friend constexpr void get(Trigger);
            };

            template <bool> 
            struct Writer
            {
                friend constexpr void get(Trigger) {}
            };

            template <class U, int = (get(Trigger{}),0)>
            static constexpr bool exists(int)
            {
                return true;
            }

            template <class U>
            static constexpr bool exists(short)
            {
                return false;
            }

          public:
            template <class U = Trigger, bool Value = exists<U>(0), int = sizeof(Writer<Value && 0>)>
            static constexpr int ReadSet()
            {
                return Value;
            }

            template <class U = Trigger, bool Value = exists<U>(0)>
            static constexpr int Read()
            {
                return Value;
            }
        };
        
        template <typename T,int I> struct Tag {};

        template<typename T,int N,bool B>
        struct Checker{
            static constexpr int currentval() noexcept{
                return N;
            }
        };

        template<typename T,int N>
        struct CheckerWrapper{
            template<bool B=Flag<Tag<T,N>>{}.Read(),int M=Checker<T,N,B>{}.currentval()>
            static constexpr int currentval(){
                return M;
            }
        };

        template<typename T,int N>
        struct Checker<T,N,true>{
            template<int M=CheckerWrapper<T,N+1>{}.currentval()>
            static constexpr int currentval() noexcept{
                return M;
            }
        };

        template<typename T,int N,bool B=Flag<Tag<T,N>>{}.ReadSet()>
        struct Next{
            static constexpr int value() noexcept{
                return N;
            }
        };
    }

    template <typename T> 
    struct Counter
    {
        template <int N=CheckerWrapper<T,0>{}.currentval()> 
        static constexpr int current()
        {
            return N;
        }
        
        template <int N=CheckerWrapper<T,0>{}.currentval()> 
        static constexpr int increment()
        {
            return Next<T,N>{}.value();
        }
    };
}

#endif
