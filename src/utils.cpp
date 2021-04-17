#include "utils.h"

std::pair<char, char> GetBrackets(std::true_type) {
  return std::make_pair('{', '}');
}

std::pair<char, char> GetBrackets(std::false_type) {
  return std::make_pair('[', ']');
}

