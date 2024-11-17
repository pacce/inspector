#include <boost/spirit/include/qi.hpp>
#include <gtest/gtest.h>
#include <inspector/inspector.hpp>

namespace qi = boost::spirit::qi;

TEST(DIGIT, DECODE) {
    inspector::date::digitp<std::string::iterator, 2> decoder;
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
          {"2001", inspector::date::Year{2001}}
        , {"2002", inspector::date::Year{2002}}
        , {"2003", inspector::date::Year{2003}}
        , {"2004", inspector::date::Year{2004}}
        , {"2005", inspector::date::Year{2005}}
        , {"2006", inspector::date::Year{2006}}
        , {"2007", inspector::date::Year{2007}}
        , {"2008", inspector::date::Year{2008}}
        , {"2009", inspector::date::Year{2009}}
        , {"2010", inspector::date::Year{2010}}

        , {"2011", inspector::date::Year{2011}}
        , {"2012", inspector::date::Year{2012}}
        , {"2013", inspector::date::Year{2013}}
        , {"2014", inspector::date::Year{2014}}
        , {"2015", inspector::date::Year{2015}}
        , {"2016", inspector::date::Year{2016}}
        , {"2017", inspector::date::Year{2017}}
        , {"2018", inspector::date::Year{2018}}
        , {"2019", inspector::date::Year{2019}}
        , {"2020", inspector::date::Year{2020}}

        , {"2021", inspector::date::Year{2021}}
        , {"2022", inspector::date::Year{2022}}
        , {"2023", inspector::date::Year{2023}}
        , {"2024", inspector::date::Year{2024}}
        , {"2025", inspector::date::Year{2025}}
        , {"2026", inspector::date::Year{2026}}
        , {"2027", inspector::date::Year{2027}}
        , {"2028", inspector::date::Year{2028}}
        , {"2029", inspector::date::Year{2029}}
        , {"2030", inspector::date::Year{2030}}
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

TEST(HOURS, DECODE) {
    inspector::date::hoursp<std::string::iterator> decoder;
    for (inspector::date::Digit i = 0; i < 24; i++) {
        std::string payload = std::format("{:02}", i);

        inspector::date::Hours actual;
        inspector::date::Hours expected{i};

        ASSERT_TRUE(qi::parse(payload.begin(), payload.end(), decoder, actual));
        EXPECT_EQ(actual, expected);
    }
}

TEST(MINUTES, DECODE) {
    inspector::date::minutesp<std::string::iterator> decoder;
    for (inspector::date::Digit i = 0; i < 60; i++) {
        std::string payload = std::format("{:02}", i);

        inspector::date::Minutes actual;
        inspector::date::Minutes expected{i};

        ASSERT_TRUE(qi::parse(payload.begin(), payload.end(), decoder, actual));
        EXPECT_EQ(actual, expected);
    }
}

TEST(SECONDS, DECODE) {
    inspector::date::secondsp<std::string::iterator> decoder;
    for (inspector::date::Digit i = 0; i < 60; i++) {
        std::string payload = std::format("{:02}", i);

        inspector::date::Seconds actual;
        inspector::date::Seconds expected{i};

        ASSERT_TRUE(qi::parse(payload.begin(), payload.end(), decoder, actual));
        EXPECT_EQ(actual, expected);
    }
}

TEST(DATE, DECODE) {
    using namespace inspector::date;
    struct Experiment {
        std::string     payload;
        inspector::Date expected;
    };
    std::vector<Experiment> experiments = {
          {"19/03/2023 22:11", {Day{19}, Month{3}, Year{2023}, Hours{22}, Minutes{11}}}
        , {"20/03/2023 13:10", {Day{20}, Month{3}, Year{2023}, Hours{13}, Minutes{10}}}
        , {"05/06/2023 01:04", {Day{05}, Month{6}, Year{2023}, Hours{01}, Minutes{04}}}
    };

    inspector::date::datep<std::string::const_iterator> decoder;
    for (const Experiment& experiment : experiments) {
        const std::string& payload      = experiment.payload;
        const inspector::Date& expected = experiment.expected;

        inspector::Date actual;

        ASSERT_TRUE(qi::parse(payload.begin(), payload.end(), decoder, actual));

        EXPECT_EQ(    actual.day,     expected.day);
        EXPECT_EQ(  actual.month,   expected.month);
        EXPECT_EQ(   actual.year,    expected.year);
        EXPECT_EQ(  actual.hours,   expected.hours);
        EXPECT_EQ(actual.minutes, expected.minutes);
    }
}

int
main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
