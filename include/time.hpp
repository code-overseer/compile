#ifndef COMPILE_TIME_HPP
#define COMPILE_TIME_HPP
#include <type_traits>
#include "math.hpp"
#include "array.hpp"
namespace compile
{
    namespace
    {
        template<std::size_t L>
        constexpr unsigned int strtoi(char const (&str)[L], std::size_t Exp, std::size_t Idx = 0)
        {
            return (Exp > 0 ? strtoi(str, Exp - 1, Idx)*10 : 0) + str[Idx + Exp] - '0';
        }

        template<std::size_t L>
        constexpr unsigned int Month(char const (&str)[L])
        {
            return cmp<0>(str, "Jan") ? 1u :
            cmp<0>(str, "Feb") ? 2u :
            cmp<0>(str, "Mar") ? 3u :
            cmp<0>(str, "Apr") ? 4u :
            cmp<0>(str, "May") ? 5u :
            cmp<0>(str, "Jun") ? 6u :
            cmp<0>(str, "Jul") ? 7u :
            cmp<0>(str, "Aug") ? 8u :
            cmp<0>(str, "Sep") ? 9u :
            cmp<0>(str, "Oct") ? 10u :
            cmp<0>(str, "Nov") ? 11u :
            cmp<0>(str, "Dec") ? 12u : 0u;
        }

        constexpr unsigned int SecondsMin = 60u;
        constexpr unsigned int SecondsHour = 3600u;
        constexpr unsigned int SecondsDay = 24u * 3600u;
        constexpr unsigned int SecondsYear = 24 * 3600 * 365;
        constexpr unsigned int TimeSeconds = strtoi(__TIME__,1,6);
        constexpr unsigned int TimeMinutes = strtoi(__TIME__,1,3);
        constexpr unsigned int TimeHours = strtoi(__TIME__,1,0);
        constexpr unsigned int TimeDays = strtoi(__DATE__,1,4);
        constexpr unsigned int TimeMonths = Month(__DATE__);
        constexpr unsigned int TimeYears = strtoi(__DATE__,3,7);

        constexpr unsigned int February() 
        { 
            return !(TimeYears % 400u) ? 29u : 
            !(TimeYears % 100u) ? 28u : 
            !(TimeYears % 4u) ? 29u : 28u; 
        }

        constexpr unsigned int TotalDays()
        {
            return TimeDays
            + (TimeMonths >= 2 ? 31 : 0)
            + (TimeMonths >= 3 ? February() : 0)
            + (TimeMonths >= 4 ? 31 : 0)
            + (TimeMonths >= 5 ? 30 : 0)
            + (TimeMonths >= 6 ? 31 : 0)
            + (TimeMonths >= 7 ? 30 : 0)
            + (TimeMonths >= 8 ? 31 : 0)
            + (TimeMonths >= 9 ? 31 : 0)
            + (TimeMonths >= 10 ? 30 : 0)
            + (TimeMonths >= 11 ? 31 : 0)
            + (TimeMonths >= 11 ? 30 : 0);
        }


        constexpr unsigned int _TimeStamp()
        {
            return TimeSeconds
            + TimeMinutes * SecondsMin
            + TimeHours * SecondsHour
            + (TotalDays() - 1) * SecondsDay
            + (TimeYears - 1970u) * SecondsYear
            + ((TimeYears - 1969u) / 4u) * SecondsDay
            - ((TimeYears - 1901u) / 100u) * SecondsDay
            + ((TimeYears - 1601u) / 400u) * SecondsDay;
        }
    }
    
    using TimeStamp = std::integral_constant<unsigned int, _TimeStamp()>;

}

#endif
