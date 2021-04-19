#include <string>
#include <vector>

#include <cassert>

std::vector<std::string> StringSplit(const std::string& str, const std::string& delimiter = " ") {
  std::vector<std::string> strings;
  int first = str.find_first_not_of(delimiter, 0);
  while (first != std::string::npos) {
    int pos = str.find_first_of(delimiter, first);
    strings.emplace_back(str.substr(first, pos - first));
    first = str.find_first_not_of(delimiter, pos);
  }
  return strings;
}

int main() {
  std::vector<std::string> strings = StringSplit(" hello  world Baby~  ");
  assert(strings.size() == 3);
}
