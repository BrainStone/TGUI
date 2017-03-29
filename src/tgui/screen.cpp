#include "screen.hpp"

namespace tgui {
namespace screen {

#if defined(TGUI_LINUX)

// Details

// Actual Implementation
position get_size() {
	winsize w;
	position size;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	size.row = w.ws_row;
	size.column = w.ws_col;

	return size;
}

void set_cursor_position(const position& pos) {
	std::cout << details::csi << pos.row << ';' << pos.column << 'H';
}

#elif defined(TGUI_WINDOWS)

// Details
CONSOLE_SCREEN_BUFFER_INFO details::get_console_screen_buffer_info() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(hStdout, &csbi);

	return csbi;
}

// Actual Implementation
position get_size() {
	CONSOLE_SCREEN_BUFFER_INFO csbi = details::get_console_screen_buffer_info();
	position size;

	size.row = csbi.dwMaximumWindowSize.X;
	size.column = csbi.dwMaximumWindowSize.X;

	return size;
}

void set_cursor_position(const position& pos) {
	COORD cursor( {  pos.row, pos.column });

	SetConsoleCursorPosition(details::hStdout, cursor);
}

#endif

}
}
