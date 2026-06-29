#include "../Include/shell.hpp"
#include <string>
#include <vector>

Shell::Shell() { m_running = true; }

std::vector<std::string> Shell::parseString(const std::string &input)
{
  std::vector<std::string> tokens;
  std::stringstream ss(input);
  std::string token;

  while (ss >> token)
  {
    tokens.push_back(token);
  }

  return tokens;
}

void Shell::run(const std::string &name, const std::vector<std::string> &data)
{
  std::vector<std::string> arguments;

  for (size_t i = 2; i < data.size(); i++)
    arguments.push_back(data[i]);
  if (m_manager.create(name, name, arguments))
    std::cout << name << " spawn Succesfully\n";
  else
    printError(name, "cannot spawn!!\n");
}

void Shell::send(const std::string &name,
                 const std::vector<std::string> &data)
{

  std::string message;

  for (size_t i = 2; i < data.size(); i++)
  {
    if (i > 2)
      message += " ";
    message += data[i];
  }
  if (!m_manager.sendInput(name, message))
    printError(name, " data can't be send!!\n");
}

void Shell::listAll()
{
  auto list = m_manager.listAll();
  if (list.empty())
  {
    printError("listAll", " no Running Process\n");
  }
  else
  {
    std::cout << "Running Processes : \n";
    for (const auto &name : list)
      std::cout << name << " -> " << m_manager.status(name) << "\n";
  }
  return;
}

void Shell::output(const std::string &name)
{
  auto result = m_manager.getOutput(name);
  if (result.has_value())
  {
    std::cout << result.value() << "\n";
  }
  else
  {
    std::cout << "No output from '" << name << "'\n";
  }
  return;
}

void Shell::execute(const std::string &input)
{
  if (input.empty())
    return;

  auto data = parseString(input);

  if (data.empty())
    return;

  std::string cmd = data[0];

  if (cmd == "exit")
  {
    std::cout << "exiting...\n";
    m_running = false;
    return;
  }
  else if (cmd == "list")
  {
    listAll();
    return;
  }

  if (data.size() < 2)
  {
    printError(cmd, "Missing argument.\n");
    return;
  }

  std::string path = data[1];

  if (cmd == "run")
  {
    if (data.size() < 3 || data.empty())
    {
      printError("run", " Error!!\n");
      return;
    }
    run(path, data);
    return;
  }
  else if (cmd == "stop")
    m_manager.stop(path);
  else if (cmd == "list")
  {
    listAll();
    return;
  }
  else if (cmd == "output")
  {
    if (!data.empty())
      output(path);
    return;
  }

  else
  {
    std::cout << "Unknown command!!\n";
    return;
  }
  return;
}

void Shell::printError(const std::string &name, const std::string &msg) const
{
  std::cerr << "Error!\n " << name << " : " << msg << "\n";
}
