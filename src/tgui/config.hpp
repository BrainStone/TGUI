/*
 * TGUI
 * Text-GUI-Library - A C++11 alternative for ncurses
 * Copyright (C) 2017 Yannick Schinko
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TGUI_TGUI_CONFIG_HPP
#define TGUI_TGUI_CONFIG_HPP

#ifdef __unix__
#	define TGUI_LINUX
#elif defined(_WIN32) || defined(WIN32)
#	define TGUI_WINDOWS
#else
#	error Unsupported System!
#endif

/**
 * A macro used for silencing unused parameter/variable warnings in release builds
 */
#if !defined(__DEBUG__) && defined(__NDEBUG__)
#	if defined(__GNUC__)
#		define TGUI_UNUSED(x) x __attribute__((unused))
#	elif defined(__LCLINT__)
#		define TGUI_UNUSED(x) /*@unused@*/ x __
#	else
#		define TGUI_UNUSED(x)
#	endif
#else
#	define TGUI_UNUSED(x) x
#endif

/**
 * The namepsace for the TGUI Library. All methods and classes will be located inside this namespace or sub-namespaces.
 */
namespace tgui {
	/**
	 * The namespace for the screen and console utilities. This is the only place where platform dependent code is located.
	 */
	namespace screen {
		/**
		 * This namespace contains platform specific implementations.\n
		 * **It is not recommended to use any methods inside this namespace!**
		 */
		namespace details {
		}
	}
}

#endif // #ifndef TGUI_TGUI_CONFIG_HPP
