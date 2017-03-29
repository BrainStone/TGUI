#ifndef TGUI_TGUI_SCREEN_LINUX_HPP
#define TGUI_TGUI_SCREEN_LINUX_HPP

#include "config.hpp"

#ifdef TGUI_LINUX

#include "screen_base.hpp"

#include <cstdio>
#include <iostream>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>

namespace tgui {
class screen_linux: public screen_base {
private:
	std::string csi = "\033[";

public:
	virtual position get_size();
	virtual position get_cursor_position();
};

typedef screen_linux screen;
}

#endif // #ifdef TGUI_LINUX

#endif // #ifndef TGUI_TGUI_SCREEN_LINUX_HPP
