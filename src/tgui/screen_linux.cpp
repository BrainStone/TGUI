#include "screen_linux.hpp"

#ifdef TGUI_LINUX

namespace tgui {
namespace screen {
position get_size() {
	winsize w;
	position size;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	size.row = w.ws_row;
	size.column = w.ws_col;

	return size;
}

position get_cursor_position() {
	position size;

	std::cout << details::csi << "6n" << std::flush;

	std::cin.ignore(2);
	std::cin >> size.row;
	std::cin.ignore(1);
	std::cin >> size.column;
	std::cin.ignore(1);

	return size;
}
}
}

#endif // #ifdef TGUI_LINUX
