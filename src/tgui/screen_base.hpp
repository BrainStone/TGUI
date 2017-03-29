#ifndef TGUI_TGUI_SCREEN_BASE_HPP
#define TGUI_TGUI_SCREEN_BASE_HPP

#include "config.hpp"

#include <cstddef>

namespace tgui {
namespace screen {
	typedef int coord_type;

	struct position {
		coord_type row;
		coord_type column;
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
	position get_cursor_position();
	bool get_cursor_visible();

	void set_cursor_position(const position& pos);
	void move_cursor_position(const position& pos);
	void set_color(const color& foreground, const color& background);
	void set_foreground_color(const color& foreground);
	void set_background_color(const color& background);
	void get_cursor_visible(bool visibility);

	void clear_screen();
	void ring_bell();
	void flash_screen();
}
}

#endif // #ifndef TGUI_TGUI_SCREEN_BASE_HPP
