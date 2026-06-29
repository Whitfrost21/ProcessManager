#include "../../Manager/include/Manager.hpp"
#include <iostream>
#include <string>
class Shell {
public:
  Shell();
  void execute(const std::string &input);
  void stop();
  bool isRunning() const;

private:
  Manager m_manager{};
  bool m_running{false};

  void printError(const std::string &name, const std::string &msg) const;
  void printHelp() const;
  std::vector<std::string> parseString(const std::string &input);
  void run(const std::string &name, const std::vector<std::string> &data);
  void send(const std::string &name, const std::vector<std::string> &data);
  void output(const std::string &name);
  void listAll();
};
