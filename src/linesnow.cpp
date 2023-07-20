#include "linesnow.h"

#include <iostream>
#include <string>
#include <format>
#include <exception>

LineSnow::LineSnow(const std::string &prompt)
    : prompt{prompt}
{
    prompt_len = prompt.size();
}

std::string LineSnow::readLine()
{
    std::cout << std::format("\x1b[33m{} \x1b[0m", prompt);
    char c;
    std::string line{""};
    size_t cursor_pos{0};
    while (true)
    {
        std::cin.get(c);
        switch (c)
        {
        case ENTER:
            newline();
            return line;
        case BACKSPACE:
            editDelete(line, cursor_pos);
            refreshLine(line, cursor_pos);
            break;
        case ESC:
            char c1;
            char c2;
            if (!std::cin.get(c1))
                throw std::runtime_error("Failed to read this key");
            if (!std::cin.get(c2))
                throw std::runtime_error("Failed to read this key");
            editEscape(line, cursor_pos, c1, c2);
            refreshLine(line, cursor_pos);
            break;
        default:
            editInsert(line, cursor_pos, c);
            refreshLine(line, cursor_pos);
            break;
        }
    }
}

void LineSnow::newline()
{
    std::cout << "\r\n";
}

void LineSnow::refreshLine(std::string &line, size_t &cursor_pos)
{
    std::cout << "\r\x1b[0K";
    std::cout << std::format("\x1b[33m{} \x1b[0m{}", prompt, line);
    std::cout << "\r";
    std::cout << std::format("\x1b[{}C", cursor_pos + prompt_len + 1);
}

void LineSnow::editDelete(std::string &line, size_t &cursor_pos)
{
    if (cursor_pos == 0)
        return;
    line.erase(cursor_pos - 1, 1);
    cursor_pos--;
}

void LineSnow::editEscape(std::string &line, size_t &cursor_pos, char c1, char c2)
{
    if (c1 == '[')
    {
        switch (c2)
        {
        case 'C':
            editMoveRight(line, cursor_pos);
            break;
        case 'D':
            editMoveLeft(line, cursor_pos);
            break;
        default:
            break;
        }
    }
}

void LineSnow::editInsert(std::string &line, size_t &cursor_pos, char c)
{
    line.insert(cursor_pos, 1, c);
    cursor_pos++;
}

void LineSnow::editMoveRight(std::string &line, size_t &cursor_pos)
{
    cursor_pos = cursor_pos < line.size() ? (cursor_pos + 1) : line.size();
}

void LineSnow::editMoveLeft(std::string &line, size_t &cursor_pos)
{
    cursor_pos = cursor_pos > 0 ? (cursor_pos - 1) : 0;
}