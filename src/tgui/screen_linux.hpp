#ifndef TGUI_TGUI_SCREEN_LINUX_HPP
#define TGUI_TGUI_SCREEN_LINUX_HPP

#include "config.hpp"

#ifdef TGUI_LINUX

#include "screen_base.hpp"

#include <cstdio>
#include <cunistd>
#include <sys/ioctl.h>

namespace tgui {
class screen_linux: public screen_base {
public:
	virtual position get_size();
};

typedef screen_linux screen;
}

#endif // #ifdef TGUI_LINUX

#endif // #ifndef TGUI_TGUI_SCREEN_LINUX_HPP
