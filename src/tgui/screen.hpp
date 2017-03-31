#ifndef TGUI_TGUI_SCREEN_HPP
#define TGUI_TGUI_SCREEN_HPP

#include "config.hpp"

#include <iostream>

#if defined(TGUI_LINUX)

#include <cstdio>
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
	coord_type column;
	coord_type row;
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
void set_cursor_position(coord_type column, coord_type row);
void move_cursor_position(const position& pos);
void move_cursor_position(coord_type column, coord_type row);
void set_color(const color& foreground, const color& background);
void set_foreground_color(const color& foreground);
void set_background_color(const color& background);
void set_cursor_visible(bool visible);

void clear_screen();
void flash_screen();
void ring_bell();
void flush_screen();

#if defined(TGUI_LINUX)

namespace details {
const std::string csi = "\033[";
}

#elif defined(TGUI_WINDOWS)

namespace details {
const HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

CONSOLE_SCREEN_BUFFER_INFO get_console_screen_buffer_info();
position get_cursor_position();
}

#endif

}
}

#endif // #ifndef TGUI_TGUI_SCREEN_HPP
