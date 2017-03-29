#ifndef TGUI_TGUI_SCREEN_HPP
#define TGUI_TGUI_SCREEN_HPP

#include "config.hpp"

#if defined(TGUI_LINUX)

#include <cstdio>
#include <iostream>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>

#elif defined(TGUI_WINDOWS)

#include <windows.h>

#endif

namespace tgui {
namespace screen {
typedef short coord_type;

struct position {
	coord_type row;
	coord_type column;
};

enum class color {
	BLACK,
	DARK_RED,
	DARK_GREEN,
	DARK_YELLOW,
	DARK_BLUE,
	DARK_MAGENTA,
	DARK_CYAN,
	GRAY,
	DARK_GRAY,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE
};

position get_size();
bool get_cursor_visible();

void set_cursor_position(const position& pos);
void move_cursor_position(const position& pos);
void set_color(const color& foreground, const color& background);
void set_foreground_color(const color& foreground);
void set_background_color(const color& background);
void get_cursor_visible(bool visibility);

void clear_screen();
void ring_bell();
void flash_screen();

#if defined(TGUI_LINUX)

namespace details {
const std::string csi = "\033[";
}

#elif defined(TGUI_WINDOWS)

namespace details {
const HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

CONSOLE_SCREEN_BUFFER_INFO get_console_screen_buffer_info();
}

#endif

}
}

#endif // #ifndef TGUI_TGUI_SCREEN_HPP
