#ifndef TGUI_TGUI_SCREEN_WINDOWS_HPP
#define TGUI_TGUI_SCREEN_WINDOWS_HPP

#include "config.hpp"

#ifdef TGUI_WINDOWS

#include "screen_base.hpp"

#include <windows.h>

namespace tgui {
class screen_windows: public screen_base {
public:
	virtual position get_size();
};

typedef screen_windows screen;
}

#endif // #ifdef TGUI_WINDOWS

#endif // #ifndef TGUI_TGUI_SCREEN_WINDOWS_HPP
