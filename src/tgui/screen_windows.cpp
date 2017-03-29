#include "screen_windows.hpp"

#ifdef TGUI_WINDOWS

namespace tgui {
HANDLE screen_windows::hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

CONSOLE_SCREEN_BUFFER_INFO screen_windows::get_console_screen_buffer_info() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(hStdout, &csbi);

	return csbi;
}

screen::position screen_windows::get_size() {
	CONSOLE_SCREEN_BUFFER_INFO csbi = get_console_screen_buffer_info();
	position size;

	size.rows = csbi.dwMaximumWindowSize.X;
	size.columns = csbi.dwMaximumWindowSize.X;

	return size;
}

screen::position screen_windows::get_cursor_position() {
	CONSOLE_SCREEN_BUFFER_INFO csbi = get_console_screen_buffer_info();
	position size;

	size.rows = csbi.dwCursorPosition.X;
	size.columns = csbi.dwCursorPosition.Y;

	return size;
}
}

#endif // #ifdef TGUI_WINDOWS
