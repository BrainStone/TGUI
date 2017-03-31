#include "screen.hpp"

namespace tgui {
namespace screen {

void set_cursor_position(coord_type column, coord_type row) {
	set_cursor_position( { column, row });
}

void move_cursor_position(coord_type column, coord_type row) {
	move_cursor_position( { column, row });
}

#if defined(TGUI_LINUX)

// Details

// Actual Implementation
position get_size() {
	winsize w;
	position size;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	size.column = w.ws_col;
	size.row = w.ws_row;

	return size;
}

void set_cursor_position(const position& pos) {
	std::cout << details::csi << pos.row << ';' << pos.column << 'H';
}

void move_cursor_position(const position& pos) {
	std::cout << details::csi;

	if(pos.column < 0) {
		std::cout << pos.column << 'D';
	} else if(pos.column > 0) {
		std::cout << pos.column << 'C';
	}

	std::cout << details::csi;

	if(pos.row < 0) {
		std::cout << pos.row << 'A';
	} else if(pos.row > 0) {
		std::cout << pos.row << 'B';
	}
}

#elif defined(TGUI_WINDOWS)

// Details
CONSOLE_SCREEN_BUFFER_INFO details::get_console_screen_buffer_info() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(hStdout, &csbi);

	return csbi;
}

position details::get_cursor_position() {
	CONSOLE_SCREEN_BUFFER_INFO csbi = details::get_console_screen_buffer_info();
	position size;

	size.column = csbi.dwCursorPosition.X;
	size.row = csbi.dwCursorPosition.Y;

	return size;
}

// Actual Implementation
position get_size() {
	CONSOLE_SCREEN_BUFFER_INFO csbi = details::get_console_screen_buffer_info();
	position size;

	size.column = csbi.dwMaximumWindowSize.X;
	size.row = csbi.dwMaximumWindowSize.Y;

	return size;
}

void set_cursor_position(const position& pos) {
	COORD cursor( { pos.row, pos.column });

	SetConsoleCursorPosition(details::hStdout, cursor);
}

void move_cursor_position(const position& pos) {
	position cur_pos = details::get_cursor_position();

	set_cursor_position(cur_pos.row + pos.row, cur_pos.column + pos.column);
}

#endif

void ring_bell() {
	std::cout << '\a';
}

void flush_screen() {
	std::cout.flush();
}

}
}
