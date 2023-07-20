#include <iostream>
#include <string>
#include <format>
#include <exception>
#include "terminal_mode.h"
#include "linesnow.h"

int main()
{
    TerminalMode terminal_mode;
    terminal_mode.set_raw_mode();

    LineSnow linesnow("sn>>>");
    while (true)
    {
        try
        {
            std::string line = linesnow.readLine();
            std::string output = std::format("\x1b[32mecho: \x1b[0m{}", line);
            std::cout << output << std::endl;
        }
        catch (const std::runtime_error &e)
        {
            std::cout << std::format("\x1b[31mError: \x1b[0m{}", e.what()) << std::endl;
            break;
        }
    }

    terminal_mode.restore_original_mode();

    return 0;
}
