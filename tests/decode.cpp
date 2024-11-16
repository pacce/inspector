#include <boost/spirit/include/qi.hpp>
#include <gtest/gtest.h>
#include <inspector/inspector.hpp>

namespace qi = boost::spirit::qi;

TEST(DIGIT, MONTH) {
    struct Experiment {
        std::string             payload;
        inspector::date::Digit  expected;
    };

    std::vector<Experiment> experiments = {
          {"01",  1}, {"02",  2}, {"03",  3}, {"04",  4}, {"05",  5}, {"06",  6}, {"07",  7}
        , {"08",  8}, {"09",  9}, {"10", 10}, {"11", 11}, {"12", 12}, {"13", 13}, {"14", 14}
        , {"15", 15}, {"16", 16}, {"17", 17}, {"18", 18}, {"19", 19}, {"20", 20}, {"21", 21}
        , {"22", 22}, {"23", 23}, {"24", 24}, {"25", 25}, {"26", 26}, {"27", 27}, {"28", 28}
        , {"29", 29}, {"30", 30}, {"31", 31}
    };
    inspector::date::digitp<std::string::const_iterator> decoder;
    for (const Experiment& experiment : experiments) {
        const std::string& payload              = experiment.payload;
        const inspector::date::Digit& expected  = experiment.expected;

        inspector::date::Digit actual;
        ASSERT_TRUE(qi::parse(payload.begin(), payload.end(), decoder, actual));
        EXPECT_EQ(actual, expected);
    }
}

TEST(MONTH, DECODE) {
    struct Experiment {
        std::string             payload;
        inspector::date::Month  expected;
    };

    std::vector<Experiment> experiments = {
          {"01", std::chrono::January}
        , {"02", std::chrono::February}
        , {"03", std::chrono::March}
        , {"04", std::chrono::April}
        , {"05", std::chrono::May}
        , {"06", std::chrono::June}
        , {"07", std::chrono::July}
        , {"08", std::chrono::August}
        , {"09", std::chrono::September}
        , {"10", std::chrono::October}
        , {"11", std::chrono::November}
        , {"12", std::chrono::December}
    };
    inspector::date::monthp<std::string::const_iterator> decoder;
    for (const Experiment& experiment : experiments) {
        const std::string& payload              = experiment.payload;
        const inspector::date::Month& expected  = experiment.expected;

        inspector::date::Month actual;

        ASSERT_TRUE(qi::parse(payload.begin(), payload.end(), decoder, actual));
        EXPECT_EQ(actual, expected);
    }
}

int
main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
