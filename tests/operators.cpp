#include <gtest/gtest.h>
#include <inspector/inspector.hpp>

using namespace inspector::date;

struct Comparison {
    inspector::Date left;
    inspector::Date right;
};

TEST(YEAR, LESSER) {
    using namespace inspector::date;

    std::vector<Comparison> comparisons {
          {{Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}, {Year{2024}, Month{1}, Day{1}, Hours{0}, Minutes{0}}}
        , {{Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}, {Year{2023}, Month{2}, Day{1}, Hours{0}, Minutes{0}}}
        , {{Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}, {Year{2023}, Month{1}, Day{2}, Hours{0}, Minutes{0}}}
        , {{Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}, {Year{2023}, Month{1}, Day{1}, Hours{1}, Minutes{0}}}
        , {{Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}, {Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{1}}}
    };
    for (const Comparison& comparison : comparisons) {
        EXPECT_LT(comparison.left, comparison.right);
    }
}

TEST(YEAR, GREATER) {
    using namespace inspector::date;

    std::vector<Comparison> comparisons {
          {{Year{2024}, Month{1}, Day{1}, Hours{0}, Minutes{0}}, {Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}}
        , {{Year{2023}, Month{2}, Day{1}, Hours{0}, Minutes{0}}, {Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}}
        , {{Year{2023}, Month{1}, Day{2}, Hours{0}, Minutes{0}}, {Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}}
        , {{Year{2023}, Month{1}, Day{1}, Hours{1}, Minutes{0}}, {Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}}
        , {{Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{1}}, {Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}}
    };
    for (const Comparison& comparison : comparisons) {
        EXPECT_GT(comparison.left, comparison.right);
    }
}

TEST(YEAR, LESSER_OR_EQUAL) {
    using namespace inspector::date;

    std::vector<Comparison> comparisons {
          {{Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}, {Year{2024}, Month{1}, Day{1}, Hours{0}, Minutes{0}}}
        , {{Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}, {Year{2023}, Month{2}, Day{1}, Hours{0}, Minutes{0}}}
        , {{Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}, {Year{2023}, Month{1}, Day{2}, Hours{0}, Minutes{0}}}
        , {{Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}, {Year{2023}, Month{1}, Day{1}, Hours{1}, Minutes{0}}}
        , {{Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}, {Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{1}}}

        , {{Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}, {Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}}
    };
    for (const Comparison& comparison : comparisons) {
        EXPECT_LE(comparison.left, comparison.right);
    }
}

TEST(YEAR, GREATER_OR_EQUAL) {
    using namespace inspector::date;

    std::vector<Comparison> comparisons {
          {{Year{2024}, Month{1}, Day{1}, Hours{0}, Minutes{0}}, {Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}}
        , {{Year{2023}, Month{2}, Day{1}, Hours{0}, Minutes{0}}, {Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}}
        , {{Year{2023}, Month{1}, Day{2}, Hours{0}, Minutes{0}}, {Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}}
        , {{Year{2023}, Month{1}, Day{1}, Hours{1}, Minutes{0}}, {Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}}
        , {{Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{1}}, {Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}}

        , {{Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}, {Year{2023}, Month{1}, Day{1}, Hours{0}, Minutes{0}}}
    };
    for (const Comparison& comparison : comparisons) {
        EXPECT_GE(comparison.left, comparison.right);
    }
}

int
main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
