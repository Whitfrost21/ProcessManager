#include "../../Shell/Include/shell.hpp"
#include <iostream>
#include <string>

int main()
{
  Shell myshell;
  std::string input;
  std::cout << "\033[2J\033[1;1H";
  std::cout << "\tPROCESS MANAGER SHELL v1.0\n";
  std::cout << "\tType 'help' for commands, 'exit' to quit\n\n";
  while (myshell.isRunning())
  {
    std::cout << "pShell > ";
    std::getline(std::cin, input);
    myshell.execute(input);
    std::cout << "\n";
  }
}
