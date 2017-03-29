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

	size.rows = csbi.dwMaximumWindowSize.X;
	size.columns = csbi.dwMaximumWindowSize.X;

	return size;
}

position get_cursor_position() {
	CONSOLE_SCREEN_BUFFER_INFO csbi = details::get_console_screen_buffer_info();
	position size;

	size.rows = csbi.dwCursorPosition.X;
	size.columns = csbi.dwCursorPosition.Y;

	return size;
}
}
}

#endif // #ifdef TGUI_WINDOWS
