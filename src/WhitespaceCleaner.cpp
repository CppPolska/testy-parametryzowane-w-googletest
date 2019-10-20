#include "WhitespaceCleaner.hpp"

WhitespaceCleaner::WhitespaceCleaner(const std::string &input): input(input) {

}

std::string WhitespaceCleaner::getParsed() const {
    std::string input = changeWhitespacesIntoSpaces(this->input);
    input = removeMultipleSiblingSpaces(input);
    input = ltrim(input);
    input = rtrim(input);

    return input;
}

std::string WhitespaceCleaner::changeWhitespacesIntoSpaces(std::string input) const {
    std::replace(input.begin(), input.end(), '\t', ' ');
    std::replace(input.begin(), input.end(), '\n', ' ');
    return input;
}

std::string WhitespaceCleaner::removeMultipleSiblingSpaces(std::string input) const {
    std::string::iterator new_end = std::unique(input.begin(), input.end(), bothAreSpaces);
    input.erase(new_end, input.end());

    return input;
}

bool WhitespaceCleaner::bothAreSpaces(char lhs, char rhs) {
    return lhs == rhs && lhs == ' ';
}

std::string WhitespaceCleaner::ltrim(std::string input) const {
    input.erase(input.begin(), std::find_if(input.begin(), input.end(), [](int ch) {
        return !std::isspace(ch);
    }));

    return input;
}

std::string WhitespaceCleaner::rtrim(std::string input) const {
    input.erase(std::find_if(input.rbegin(), input.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), input.end());

    return input;
}
