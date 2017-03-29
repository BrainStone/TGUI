#include "screen_linux.hpp"

#ifdef TGUI_LINUX

namespace tgui {
screen::position screen_linux::get_size() {
	winsize w;
	position size;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	size.rows = w.ws_row;
	size.columns = w.ws_col;

	return size;
}

screen::position screen_linux::get_cursor_position() {
	position size;

	std::cout << csi << "6n" << std::flush;

	std::cin.ignore(2);
	std::cin >> size.rows;
	std::cin.ignore(1);
	std::cin >> size.columns;
	std::cin.ignore(1);

	return size;
}
}

#endif // #ifdef TGUI_LINUX
