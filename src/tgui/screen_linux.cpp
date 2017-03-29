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
}

#endif // #ifdef TGUI_LINUX
