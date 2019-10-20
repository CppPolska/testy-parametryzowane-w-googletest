#pragma once

#include <string>

class WhitespaceCleaner {

public:

    explicit WhitespaceCleaner(const std::string &input);

    std::string getParsed() const;

private:

    std::string input;

    static bool bothAreSpaces(char lhs, char rhs);

    std::string changeWhitespacesIntoSpaces(std::string input) const;
    std::string removeMultipleSiblingSpaces(std::string input) const;
    std::string ltrim(std::string input) const;
    std::string rtrim(std::string input) const;
};


