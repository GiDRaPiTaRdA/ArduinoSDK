// CommandInput.cpp

#include "CommandInput.h"

CommandInput::CommandInput() {}

void CommandInput::AddCommand(const String &cmd, const CommandFunction &func)
{
  commandMap[cmd] = func;
}

void CommandInput::Loop()
{
  if (Serial.available() > 0)
  {
    String command = Serial.readStringUntil('\n');

    command.trim(); // Remove leading and trailing whitespaces, if any

    // Process the received input
    if (!command.isEmpty())
    {
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
      }
    }
  }
}