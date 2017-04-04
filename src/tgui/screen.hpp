#ifndef TGUI_TGUI_SCREEN_HPP
#define TGUI_TGUI_SCREEN_HPP

/**
 * @file tgui/screen.hpp
 *
 * @brief This file contains the tgui::screen methods.
 */

#include "config.hpp"

#include <functional>
#include <iostream>
#include <list>

#if defined(TGUI_LINUX)

#include <csignal>
#include <cstdio>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>

#elif defined(TGUI_WINDOWS)

#include <map>
#include <thread>
#include <windows.h>

#endif

namespace tgui {
	namespace screen {
		struct position;

		typedef short coord_type;
		typedef std::function<void ( position )> resize_callback;

		struct position {
			coord_type column;
			coord_type row;
		};

		/**
		 * @brief All available colors
		 *
		 * This enum contains all color available for display. They can be applied for the foreground as well as the background!\n
		 * *Colors may vary depending on the used environment!!! See https://en.wikipedia.org/wiki/ANSI_escape_code#Colors for more details*
		 */
		enum class color {
			/// #000000
			BLACK,
			/// #800000
			DARK_RED,
			/// #008000
			DARK_GREEN,
			/// #808000
			DARK_YELLOW,
			/// #000080
			DARK_BLUE,
			/// #800080
			DARK_MAGENTA,
			/// #008080
			DARK_CYAN,
			/// #C0C0C0
			GRAY,
			/// #808080
			DARK_GRAY,
			/// #FF0000
			RED,
			/// #00FF00
			GREEN,
			/// #FFFF00
			YELLOW,
			/// #0000FF
			BLUE,
			/// #FF00FF
			MAGENTA,
			/// #00FFFF
			CYAN,
			/// #FFFFFF
			WHITE
		};

		position get_size ();

		void set_cursor_position ( const position& pos );
		void set_cursor_position ( coord_type column, coord_type row );
		void move_cursor_position ( const position& pos );
		void move_cursor_position ( coord_type column, coord_type row );
		void set_color ( const color& foreground, const color& background );
		void set_foreground_color ( const color& foreground );
		void set_background_color ( const color& background );
		void set_cursor_visible ( bool visible );

		void clear_screen ();
		void register_resize_callback ( resize_callback callback );
		void ring_bell ();
		void flush_screen ();

		namespace details {
			extern std::list<resize_callback> resize_callbacks;

#if defined(TGUI_LINUX)

			const std::string csi = "\033[";

			void call_resize_callbacks(int);

#elif defined(TGUI_WINDOWS)

			const HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
			const std::map<color, WORD> foreground_colors(
					{	{ color::BLACK, 0 },
						{ color::DARK_RED, FOREGROUND_RED },
						{ color::DARK_GREEN, FOREGROUND_GREEN },
						{ color::DARK_YELLOW, FOREGROUND_RED | FOREGROUND_GREEN },
						{ color::DARK_BLUE, FOREGROUND_BLUE },
						{ color::DARK_MAGENTA, FOREGROUND_RED | FOREGROUND_BLUE },
						{ color::DARK_CYAN, FOREGROUND_GREEN | FOREGROUND_BLUE },
						{ color::GRAY, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE },
						{ color::DARK_GRAY, FOREGROUND_INTENSITY },
						{ color::RED, FOREGROUND_RED | FOREGROUND_INTENSITY },
						{ color::GREEN, FOREGROUND_GREEN | FOREGROUND_INTENSITY },
						{ color::YELLOW, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY },
						{ color::BLUE, FOREGROUND_BLUE | FOREGROUND_INTENSITY },
						{ color::MAGENTA, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY },
						{ color::CYAN, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY },
						{ color::WHITE, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY } } );
			const std::map<color, WORD> background_colors(
					{	{ color::BLACK, 0 },
						{ color::DARK_RED, BACKGROUND_RED },
						{ color::DARK_GREEN, BACKGROUND_GREEN },
						{ color::DARK_YELLOW, BACKGROUND_RED | BACKGROUND_GREEN },
						{ color::DARK_BLUE, BACKGROUND_BLUE },
						{ color::DARK_MAGENTA, BACKGROUND_RED | BACKGROUND_BLUE },
						{ color::DARK_CYAN, BACKGROUND_GREEN | BACKGROUND_BLUE },
						{ color::GRAY, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE },
						{ color::DARK_GRAY, BACKGROUND_INTENSITY },
						{ color::RED, BACKGROUND_RED | BACKGROUND_INTENSITY },
						{ color::GREEN, BACKGROUND_GREEN | BACKGROUND_INTENSITY },
						{ color::YELLOW, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY },
						{ color::BLUE, BACKGROUND_BLUE | BACKGROUND_INTENSITY },
						{ color::MAGENTA, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY },
						{ color::CYAN, BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY },
						{ color::WHITE, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY } } );

			CONSOLE_SCREEN_BUFFER_INFO get_console_screen_buffer_info ();
			position get_cursor_position ();

#endif

		}
	}
}

#endif // #ifndef TGUI_TGUI_SCREEN_HPP
