#include "screen_windows.hpp"

#ifdef TGUI_WINDOWS

namespace tgui {
namespace screen {
CONSOLE_SCREEN_BUFFER_INFO details::get_console_screen_buffer_info() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(hStdout, &csbi);

	return csbi;
}

position get_size() {
	CONSOLE_SCREEN_BUFFER_INFO csbi = details::get_console_screen_buffer_info();
	position size;

	size.row = csbi.dwMaximumWindowSize.X;
	size.column = csbi.dwMaximumWindowSize.X;

	return size;
}

position get_cursor_position() {
	CONSOLE_SCREEN_BUFFER_INFO csbi = details::get_console_screen_buffer_info();
	position size;

	size.row = csbi.dwCursorPosition.X;
	size.column = csbi.dwCursorPosition.Y;

	return size;
}

void set_cursor_position(const position& pos) {
	COORD cursor( { pos.row, pos.column });

	SetConsoleCursorPosition(details::hStdout, cursor);
}
}
}

#endif // #ifdef TGUI_WINDOWS
