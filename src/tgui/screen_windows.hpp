#ifndef TGUI_TGUI_SCREEN_WINDOWS_HPP
#define TGUI_TGUI_SCREEN_WINDOWS_HPP

#include "config.hpp"

#ifdef TGUI_WINDOWS

#include "screen_base.hpp"

#include <windows.h>

namespace tgui {
namespace screen {
namespace details {
const HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

CONSOLE_SCREEN_BUFFER_INFO get_console_screen_buffer_info();
}
}
}

#endif // #ifdef TGUI_WINDOWS

#endif // #ifndef TGUI_TGUI_SCREEN_WINDOWS_HPP
