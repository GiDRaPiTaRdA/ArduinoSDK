// CommandInput.h
#ifndef COMMANDINPUT_H
#define COMMANDINPUT_H

#include "Arduino.h"
#include <functional>
#include <map>

// Subject class template
template <typename CommandParameter>

class CommandInput
{
  using CommandFunction = std::function<void()>;
  std::map<CommandParameter, CommandFunction> commandMap;

public:
  void AddCommand(const CommandParameter &cmd, const CommandFunction &func)
  {
    commandMap[cmd] = func;
  }

  // void ProcessSerialLoop()
  // {
  //   if (Serial.available() > 0)
  //   {
  //     String command = Serial.readStringUntil('\n');

  //     command.trim(); // Remove leading and trailing whitespaces, if any

  //     ProcessInputLoop(command);
  //   }
  // }

  bool ProcessInputLoop(CommandParameter command)
  {
    bool cmdRecognized = true;

    // Process the received input
    auto it = commandMap.find(command);
    if (it != commandMap.end())
    {
      // Execute the associated function for the command
      it->second();
    }
    else
    {
      Serial.print("Unknown command: ");
      Serial.println(command);

      cmdRecognized = false;
    }

    return cmdRecognized;
  }

  //     void CommandInput::ProcessInputLoop(String command)
  // {
  //     // Process the received input
  //     if (!command.isEmpty())
  //     {
  //       auto it = commandMap.find(command);
  //       if (it != commandMap.end())
  //       {
  //         // Execute the associated function for the command
  //         it->second();
  //       }
  //       else
  //       {
  //         Serial.print("Unknown command: ");
  //         Serial.println(command);
  //       }
  //     }
  // };
};

#endif