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
namespace screen {
namespace details {
const std::string csi = "\033[";
}
}
}

#endif // #ifdef TGUI_LINUX

#endif // #ifndef TGUI_TGUI_SCREEN_LINUX_HPP
