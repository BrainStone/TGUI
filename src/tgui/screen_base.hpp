#ifndef TGUI_TGUI_SCREEN_BASE_HPP
#define TGUI_TGUI_SCREEN_BASE_HPP

#include "config.hpp"

#include <cstddef>

namespace tgui {
class screen_base {
public:
	typedef int coord_type;

	struct position {
		coord_type rows;
		coord_type columns;
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

	virtual ~screen_base();

	virtual position get_size() = 0;
	virtual position get_cursor_position() = 0;
	virtual bool get_cursor_visible() = 0;

	virtual void set_cursor_position(const position& pos) = 0;
	virtual void move_cursor_position(const position& pos) = 0;
	virtual void set_color(const color& foreground, const color& background) = 0;
	virtual void set_foreground_color(const color& foreground) = 0;
	virtual void set_background_color(const color& background) = 0;
	virtual void get_cursor_visible(bool visibility) = 0;
};
}

#endif // #ifndef TGUI_TGUI_SCREEN_BASE_HPP
