#include <gtest/gtest.h>

#include <WhitespaceCleaner.hpp>

struct TestParameters {
    std::string input;
    std::string result;
};

class WhitespaceCleaner_After : public ::testing::TestWithParam<TestParameters> {

};

TEST_P(WhitespaceCleaner_After, test_clearing_whitespaces) {
    TestParameters const& parameters = GetParam();
    WhitespaceCleaner cleaner(parameters.input);
    ASSERT_EQ(parameters.result, cleaner.getParsed());
}

INSTANTIATE_TEST_CASE_P(TestSpaces, WhitespaceCleaner_After, ::testing::Values(
        TestParameters{"    hello", "hello"},
        TestParameters{"hello    ", "hello"},
        TestParameters{"hello  world", "hello world"}
));

INSTANTIATE_TEST_CASE_P(TestTabs, WhitespaceCleaner_After, ::testing::Values(
        TestParameters{"hello\tworld", "hello world"},
        TestParameters{"hello\t\tworld", "hello world"}
));

INSTANTIATE_TEST_CASE_P(TestNewLines, WhitespaceCleaner_After, ::testing::Values(
        TestParameters{"hello\nworld", "hello world"},
        TestParameters{"hello\n\nworld", "hello world"}
));