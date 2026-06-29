#include "../../Shell/Include/shell.hpp"
#include <iostream>
#include <string>

int main() {
  Shell myshell;
  std::string input;
  while (myshell.isRunning()) {
    std::cout << "pshell > ";
    std::getline(std::cin, input);
    myshell.execute(input);
  }
}
