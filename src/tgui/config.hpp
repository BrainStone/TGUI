#ifndef TGUI_TGUI_CONFIG_HPP
#define TGUI_TGUI_CONFIG_HPP

#ifdef __unix__
#define TGUI_LINUX
#elif defined(_WIN32) || defined(WIN32)
#define TGUI_WINDOWS
#else
#error Unsupported System!
#endif

#endif // #ifndef TGUI_TGUI_CONFIG_HPP
