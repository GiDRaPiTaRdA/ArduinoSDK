// CommandInput.h
#ifndef COMMANDINPUT_H
#define COMMANDINPUT_H

#include "Arduino.h"
#include <functional>
#include <map>

class CommandInput {
  using CommandFunction = std::function<void()>;
  std::map<String, CommandFunction> commandMap;

public:
  CommandInput();
  void Loop();
  void AddCommand(const String& cmd, const CommandFunction& func);
};

#endif