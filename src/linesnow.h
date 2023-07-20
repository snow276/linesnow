#ifndef LINESNOW_H
#define LINESNOW_H

#include <string>

class LineSnow
{
private:
    enum ASCII
    {
        ENTER = 10,     /* Enter */
        ESC = 27,       /* Escape */
        BACKSPACE = 127 /* Backspace */
    };
    const std::string prompt;
    size_t prompt_len;

public:
    LineSnow(const std::string &prompt);
    std::string readLine();
    void newline();
    void refreshLine(std::string &line, size_t &cursor_pos);
    void editDelete(std::string &line, size_t &cursor_pos);
    void editEscape(std::string &line, size_t &cursor_pos, char c1, char c2);
    void editInsert(std::string &line, size_t &cursor_pos, char c);
    void editMoveRight(std::string &line, size_t &cursor_pos);
    void editMoveLeft(std::string &line, size_t &cursor_pos);
};

#endif