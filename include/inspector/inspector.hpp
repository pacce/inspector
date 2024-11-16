#ifndef INSPECTOR_HPP__
#define INSPECTOR_HPP__

#include <boost/spirit/include/qi.hpp>
#include <chrono>

namespace inspector {
    namespace qi = boost::spirit::qi;
namespace date {
    using Digit = std::uint8_t;
    using Year  = std::chrono::year;
    using Month = std::chrono::month;
    using Day   = std::chrono::day;

    using Hours     = std::chrono::hours;
    using Minutes   = std::chrono::minutes;
    using Seconds   = std::chrono::seconds;

    template <typename Iterator>
    struct digitp : qi::grammar<Iterator, Digit> {
        digitp() : digitp::base_type(rule) {
            rule = qi::int_parser<Digit, 10, 2, 2>();
        }

        qi::rule<Iterator, Digit> rule;
    };

    // template <typename Iterator>
    // struct yearp : qi::grammar<Iterator, Year> {
    //     yearp() : yearp::base_type(rule) {
    //     }

    //     qi::rule<Iterator, Year> rule;
    // };

    template <typename Iterator>
    struct monthp : qi::grammar<Iterator, Month> {
        monthp() : monthp::base_type(rule) {
            rule = digit;
        }

        digitp<Iterator>            digit;
        qi::rule<Iterator, Month>   rule;
    };
} // namespace date
    struct Date {};
    struct Name {};
} // namespace inspector

#endif // INSPECTOR_HPP__
