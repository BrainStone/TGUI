#include "screen_windows.hpp"

#ifdef TGUI_WINDOWS

namespace tgui {
screen::position screen_windows::get_size() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	position size;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	size.rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	size.columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

	return size;
}
}

#endif // #ifdef TGUI_WINDOWS
