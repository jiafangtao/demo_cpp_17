#include <iostream>
#include <string>
#include <optional>

int main() {
  std::string s = "hello, world";
  std::cout << "first " << s << std::endl;

  
  std::string_view sv (s);
  std::cout << "second " << sv << std::endl;

  return 0;
}
