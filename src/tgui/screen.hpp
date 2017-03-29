#ifndef TGUI_TGUI_SCREEN_HPP
#define TGUI_TGUI_SCREEN_HPP

#include "config.hpp"
#include "screen_base.hpp"

#if defined(TGUI_LINUX)
#include "screen_linux.hpp"
#elif defined(TGUI_WINDOWS)
#include "screen_windows.hpp"
#endif

#endif // #ifndef TGUI_TGUI_SCREEN_HPP
