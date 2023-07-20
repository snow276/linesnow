#ifndef TERMINAL_MODE_H
#define TERMINAL_MODE_H

#include <termios.h>

class TerminalMode
{
private:
    struct termios old_settings;

public:
    void set_raw_mode();
    void restore_original_mode();
};

#endif