#include <gtest/gtest.h>

#include <WhitespaceCleaner.hpp>

TEST(WhitespaceCleaner_Before, test_trim_text_on_left) {
    std::string input = "    hello";

    WhitespaceCleaner cleaner(input);
    ASSERT_EQ("hello", cleaner.getParsed());
}

TEST(WhitespaceCleaner_Before, test_trim_text_on_right) {
    std::string input = "hello    ";

    WhitespaceCleaner cleaner(input);
    ASSERT_EQ("hello", cleaner.getParsed());
}

TEST(WhitespaceCleaner_Before, test_remove_two_spaces_in_middle) {
    std::string input = "hello  world";

    WhitespaceCleaner cleaner(input);
    ASSERT_EQ("hello world", cleaner.getParsed());
}

TEST(WhitespaceCleaner_Before, test_change_tab_into_space) {
    std::string input = "hello\tworld";

    WhitespaceCleaner cleaner(input);
    ASSERT_EQ("hello world", cleaner.getParsed());
}

TEST(WhitespaceCleaner_Before, test_change_two_tabs_into_single_space) {
    std::string input = "hello\t\tworld";

    WhitespaceCleaner cleaner(input);
    ASSERT_EQ("hello world", cleaner.getParsed());
}

TEST(WhitespaceCleaner_Before, test_change_new_line_into_space) {
    std::string input = "hello\nworld";

    WhitespaceCleaner cleaner(input);
    ASSERT_EQ("hello world", cleaner.getParsed());
}

TEST(WhitespaceCleaner_Before, test_change_two_new_lines_into_single_space) {
    std::string input = "hello\n\nworld";

    WhitespaceCleaner cleaner(input);
    ASSERT_EQ("hello world", cleaner.getParsed());
}