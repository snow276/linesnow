#include "terminal_mode.h"
#include <unistd.h>

void TerminalMode::set_raw_mode()
{
    // 获取终端属性
    struct termios new_settings;
    tcgetattr(STDIN_FILENO, &old_settings);
    new_settings = old_settings;

    // 设置终端为原始模式
    new_settings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
}

void TerminalMode::restore_original_mode()
{
    // 恢复终端到初始模式
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);
}