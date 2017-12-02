#ifndef __MY_SHELL_H__
#define __MY_SHELL_H__
#include <map>
#include <vector>
#include <string>

class MyShell {
private:
  bool error; // if any error occurs in previous steps
  bool exitting; // if the shell will exit in the next step
  std::string input; // initial one-line user input
  std::vector<std::string> piped_commands; // piped commands in user input
  std::vector<std::string> commands; // one command and its arguments
  int * pipefd; // an array of pipe fd used to run piped commands
  std::size_t curr_command_index;
  std::size_t num_child_processes; // number of child processes forked
  std::map<std::string, std::string> vars; // internal map of Shell variables and values
  void setVar(std::string key, std::string value);
  void parsePipedInput();
  void parseCommand();
  void evaluateVars();
  bool searchCommand();
  void runExitCommands();
  void runCdCommand();
  void runSetCommand();
  void runExportCommand();
  void configCommandRedirect();
  void configCommandPipe();
  void runCommand();
  void createPipes();
  void closePipes();
  void waitForChildProcesses();
  void runPipedCommands();
  void refresh();
public:
  MyShell();
  void execute();
  bool isExitting();
};

#endif
