#include <string>

int resolve(std::string::iterator begin, std::string::iterator end)
{
  auto current = begin;
  while (std::distance(current, end) != 1) {
    if (*current == '+') {
      return resolve(begin, current) + resolve(std::next(current), end);
    /*} else if (*current == '-') {
      //TODO: keep '-' to a digit and resolve as '+' case
      return resolve(begin, current) - resolve(std::next(current), end);
    }*/ else
      ++current;
  }

  current = begin;
  int result = atoi(&*current++);
  while (current != end) {
    if (*current == '*') {
      int right = atoi(&*++current);
      result *= right;
    } else if (*current == '/') {
      int right = atoi(&*++current);
      result /= right;
    }
    ++current;
  }
  return result;
}

