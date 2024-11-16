#include <boost/spirit/include/qi.hpp>
#include <gtest/gtest.h>
#include <inspector/inspector.hpp>

namespace qi = boost::spirit::qi;

TEST(DIGIT, MONTH) {
    inspector::date::digitp<std::string::iterator> decoder;
    for (inspector::date::Digit expected = 0; expected <= 99; expected++) {
        std::string payload = std::format("{:02}", expected);

        inspector::date::Digit actual;
        ASSERT_TRUE(qi::parse(payload.begin(), payload.end(), decoder, actual));
        EXPECT_EQ(actual, expected);
    }
}

TEST(YEAR, DECODE) {
    struct Experiment {
        std::string             payload;
        inspector::date::Year   expected;
    };

    std::vector<Experiment> experiments = {
          {"01", inspector::date::Year{ 1}}
        , {"02", inspector::date::Year{ 2}}
        , {"03", inspector::date::Year{ 3}}
        , {"04", inspector::date::Year{ 4}}
        , {"05", inspector::date::Year{ 5}}
        , {"06", inspector::date::Year{ 6}}
        , {"07", inspector::date::Year{ 7}}
        , {"08", inspector::date::Year{ 8}}
        , {"09", inspector::date::Year{ 9}}
        , {"10", inspector::date::Year{10}}

        , {"11", inspector::date::Year{11}}
        , {"12", inspector::date::Year{12}}
        , {"13", inspector::date::Year{13}}
        , {"14", inspector::date::Year{14}}
        , {"15", inspector::date::Year{15}}
        , {"16", inspector::date::Year{16}}
        , {"17", inspector::date::Year{17}}
        , {"18", inspector::date::Year{18}}
        , {"19", inspector::date::Year{19}}
        , {"20", inspector::date::Year{20}}

        , {"21", inspector::date::Year{21}}
        , {"22", inspector::date::Year{22}}
        , {"23", inspector::date::Year{23}}
        , {"24", inspector::date::Year{24}}
        , {"25", inspector::date::Year{25}}
        , {"26", inspector::date::Year{26}}
        , {"27", inspector::date::Year{27}}
        , {"28", inspector::date::Year{28}}
        , {"29", inspector::date::Year{29}}
        , {"30", inspector::date::Year{30}}
    };
    inspector::date::yearp<std::string::const_iterator> decoder;
    for (const Experiment& experiment : experiments) {
        const std::string& payload              = experiment.payload;
        const inspector::date::Year& expected   = experiment.expected;

        inspector::date::Year actual;

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

TEST(DAY, DECODE) {
    struct Experiment {
        std::string             payload;
        inspector::date::Day    expected;
    };

    std::vector<Experiment> experiments = {
          {"01", inspector::date::Day{ 1}}
        , {"02", inspector::date::Day{ 2}}
        , {"03", inspector::date::Day{ 3}}
        , {"04", inspector::date::Day{ 4}}
        , {"05", inspector::date::Day{ 5}}
        , {"06", inspector::date::Day{ 6}}
        , {"07", inspector::date::Day{ 7}}
        , {"08", inspector::date::Day{ 8}}
        , {"09", inspector::date::Day{ 9}}
        , {"10", inspector::date::Day{10}}

        , {"11", inspector::date::Day{11}}
        , {"12", inspector::date::Day{12}}
        , {"13", inspector::date::Day{13}}
        , {"14", inspector::date::Day{14}}
        , {"15", inspector::date::Day{15}}
        , {"16", inspector::date::Day{16}}
        , {"17", inspector::date::Day{17}}
        , {"18", inspector::date::Day{18}}
        , {"19", inspector::date::Day{19}}
        , {"20", inspector::date::Day{20}}

        , {"21", inspector::date::Day{21}}
        , {"22", inspector::date::Day{22}}
        , {"23", inspector::date::Day{23}}
        , {"24", inspector::date::Day{24}}
        , {"25", inspector::date::Day{25}}
        , {"26", inspector::date::Day{26}}
        , {"27", inspector::date::Day{27}}
        , {"28", inspector::date::Day{28}}
        , {"29", inspector::date::Day{29}}
        , {"30", inspector::date::Day{30}}

        , {"31", inspector::date::Day{31}}
    };
    inspector::date::dayp<std::string::const_iterator> decoder;
    for (const Experiment& experiment : experiments) {
        const std::string& payload              = experiment.payload;
        const inspector::date::Day& expected    = experiment.expected;

        inspector::date::Day actual;

        ASSERT_TRUE(qi::parse(payload.begin(), payload.end(), decoder, actual));
        EXPECT_EQ(actual, expected);
    }
}

int
main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
