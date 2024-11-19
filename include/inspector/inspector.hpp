#ifndef INSPECTOR_HPP__
#define INSPECTOR_HPP__

#include <boost/spirit/include/qi.hpp>
#include <chrono>

namespace inspector {
    namespace qi = boost::spirit::qi;
namespace date {
    using Digit = std::uint16_t;
    using Year  = std::chrono::year;
    using Month = std::chrono::month;
    using Day   = std::chrono::day;

    using Hours     = std::chrono::hours;
    using Minutes   = std::chrono::minutes;
    using Seconds   = std::chrono::seconds;
} // namespace date
    struct Date {
        date::Year  year;
        date::Month month;
        date::Day   day;

        date::Hours     hours;
        date::Minutes   minutes;

        friend std::strong_ordering
        operator<=>(const Date& lhs, const Date& rhs) noexcept {
            if (lhs.year > rhs.year) {
                return std::strong_ordering::greater;
            } else if (lhs.year < rhs.year) {
                return std::strong_ordering::less;
            } else if (lhs.month > rhs.month) {
                return std::strong_ordering::greater;
            } else if (lhs.month < rhs.month) {
                return std::strong_ordering::less;
            } else if (lhs.day > rhs.day) {
                return std::strong_ordering::greater;
            } else if (lhs.day < rhs.day) {
                return std::strong_ordering::less;
            } else if (lhs.hours > rhs.hours) {
                return std::strong_ordering::greater;
            } else if (lhs.hours < rhs.hours) {
                return std::strong_ordering::less;
            } else if (lhs.minutes > rhs.minutes) {
                return std::strong_ordering::greater;
            } else if (lhs.minutes < rhs.minutes) {
                return std::strong_ordering::less;
            } else {
                return std::strong_ordering::equal;
            }
        }

        friend bool
        operator==(const Date& lhs, const Date& rhs) noexcept {
            return (lhs <=> rhs) == std::strong_ordering::equal;
        }

        friend bool
        operator!=(const Date& lhs, const Date& rhs) noexcept {
            return (lhs <=> rhs) != std::strong_ordering::equal;
        }
    };
} // namespace inspector

BOOST_FUSION_ADAPT_STRUCT(
        inspector::Date,
        (inspector::date::Day,      day)
        (inspector::date::Month,    month)
        (inspector::date::Year,     year)
        (inspector::date::Hours,    hours)
        (inspector::date::Minutes,  minutes)
        );

namespace inspector {
namespace date {
    template <typename Iterator, int N>
    struct digitp : qi::grammar<Iterator, Digit> {
        digitp() : digitp::base_type(rule) {
            rule = qi::int_parser<Digit, 10, N, N>();
        }

        qi::rule<Iterator, Digit> rule;
    };

    template <typename Iterator>
    struct yearp : qi::grammar<Iterator, Year> {
        yearp() : yearp::base_type(rule) {
            rule = digit;
        }

        digitp<Iterator, 4>         digit;
        qi::rule<Iterator, Year>    rule;
    };

    template <typename Iterator>
    struct monthp : qi::grammar<Iterator, Month> {
        monthp() : monthp::base_type(rule) {
            rule = digit;
        }

        digitp<Iterator, 2>         digit;
        qi::rule<Iterator, Month>   rule;
    };

    template <typename Iterator>
    struct dayp : qi::grammar<Iterator, Day> {
        dayp() : dayp::base_type(rule) {
            rule = digit;
        }

        digitp<Iterator, 2>     digit;
        qi::rule<Iterator, Day> rule;
    };

    template <typename Iterator>
    struct hoursp : qi::grammar<Iterator, Hours> {
        hoursp() : hoursp::base_type(rule) {
            rule = digit;
        }

        digitp<Iterator, 2>         digit;
        qi::rule<Iterator, Hours>   rule;
    };

    template <typename Iterator>
    struct minutesp : qi::grammar<Iterator, Minutes> {
        minutesp() : minutesp::base_type(rule) {
            rule = digit;
        }

        digitp<Iterator, 2>         digit;
        qi::rule<Iterator, Minutes> rule;
    };

    template <typename Iterator>
    struct secondsp : qi::grammar<Iterator, Seconds> {
        secondsp() : secondsp::base_type(rule) {
            rule = digit;
        }

        digitp<Iterator, 2>         digit;
        qi::rule<Iterator, Seconds> rule;
    };

    template <typename Iterator>
    struct datep : qi::grammar<Iterator, Date> {
        datep() : datep::base_type(rule) {
            rule = day
                >> "/"
                >> month
                >> "/"
                >> year
                >> " "
                >> hours
                >> ":"
                >> minutes
                ;
        }

        date::dayp<Iterator>    day;
        date::monthp<Iterator>  month;
        date::yearp<Iterator>   year;

        date::hoursp<Iterator>      hours;
        date::minutesp<Iterator>    minutes;

        qi::rule<Iterator, Date>    rule;
    };
 } // namespace date
 } // namespace inspector

 #endif // INSPECTOR_HPP__
