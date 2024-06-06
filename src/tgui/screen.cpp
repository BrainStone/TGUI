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

#include "screen.hpp"

/**
 * @file tgui/screen.cpp
 *
 * @brief This file contains the implementations of the tgui::screen methods.
 */

namespace tgui {
	namespace screen {
		std::vector<resize_callback> details::resize_callbacks;

		bool position::operator == ( const position& rhs ) const {
			return (column == rhs.column) && (row == rhs.row);
		}

		bool position::operator != ( const position& rhs ) const {
			return !(*this == rhs);
		}

		void set_cursor_position ( coord_type column, coord_type row ) {
			set_cursor_position( { column, row } );
		}

		void move_cursor_position ( coord_type column, coord_type row ) {
			move_cursor_position( { column, row } );
		}

#if defined(TGUI_LINUX)

		// Details
		void details::call_resize_callbacks ( int ) {
			position size = get_size();

			for ( const resize_callback& callback : resize_callbacks ) {
				callback( size );
			}
		}

		// Actual Implementation
		position get_size () {
			winsize w;
			position size;

			ioctl( STDOUT_FILENO, TIOCGWINSZ, &w );

			size.column = w.ws_col;
			size.row = w.ws_row;

			return size;
		}

		void set_cursor_position ( const position& pos ) {
			std::cout << details::csi << pos.row << ';' << pos.column << 'H';
		}

		void move_cursor_position ( const position& pos ) {
			std::cout << details::csi;

			if ( pos.column < 0 ) {
				std::cout << pos.column << 'D';
			} else if ( pos.column > 0 ) {
				std::cout << pos.column << 'C';
			}

			std::cout << details::csi;

			if ( pos.row < 0 ) {
				std::cout << pos.row << 'A';
			} else if ( pos.row > 0 ) {
				std::cout << pos.row << 'B';
			}
		}

		void set_color ( const color& foreground, const color& background ) {
			set_background_color( background );
			set_foreground_color( foreground );
		}

		void set_foreground_color ( const color& foreground ) {
			int intensity = (static_cast<int>( foreground ) & 8)? 1 : 22;
			int color = (static_cast<int>( foreground ) & 7) + 30;

			std::cout << details::csi << intensity << ';' << color << 'm';
		}

		void set_background_color ( const color& background ) {
			int intensity = (static_cast<int>( background ) & 8)? 1 : 22;
			int color = (static_cast<int>( background ) & 7) + 40;

			std::cout << details::csi << intensity << ';' << color << 'm';
		}

		void set_cursor_visible ( bool visible ) {
			std::cout << details::csi << "?25" << (visible? 'h' : 'l');
		}

		void clear_screen () {
			std::cout << details::csi << "2J";
		}

		void register_resize_callback ( std::function<void ( position )> callback ) {
			if ( details::resize_callbacks.empty() ) {
				std::signal( SIGWINCH, details::call_resize_callbacks );
			}

			details::resize_callbacks.push_back( callback );
		}

#elif defined(TGUI_WINDOWS)

		// Details
		CONSOLE_SCREEN_BUFFER_INFO details::get_console_screen_buffer_info () {
			CONSOLE_SCREEN_BUFFER_INFO csbi;

			GetConsoleScreenBufferInfo( hStdout, &csbi );

			return csbi;
		}

		position details::get_cursor_position () {
			CONSOLE_SCREEN_BUFFER_INFO csbi = details::get_console_screen_buffer_info();
			position size { csbi.dwCursorPosition.X, csbi.dwCursorPosition.Y };

			return size;
		}

		// Actual Implementation
		position get_size () {
			CONSOLE_SCREEN_BUFFER_INFO csbi = details::get_console_screen_buffer_info();
			position size { csbi.dwSize.X, csbi.dwSize.Y };

			return size;
		}

		void set_cursor_position ( const position& pos ) {
			COORD cursor( { pos.row, pos.column } );

			SetConsoleCursorPosition( details::hStdout, cursor );
		}

		void move_cursor_position ( const position& pos ) {
			position cur_pos = details::get_cursor_position();

			set_cursor_position( cur_pos.row + pos.row, cur_pos.column + pos.column );
		}

		void set_color ( const color& foreground, const color& background ) {
			SetConsoleTextAttribute( details::hStdout,
					details::foreground_colors.at( foreground ) | details::background_colors.at( background ) );
		}

		void set_foreground_color ( const color& foreground ) {
			SetConsoleTextAttribute( details::hStdout,
					(details::get_console_screen_buffer_info().wAttributes & 0xf0)
							| details::foreground_colors.at( foreground ) );
		}

		void set_background_color ( const color& background ) {
			SetConsoleTextAttribute( details::hStdout,
					(details::get_console_screen_buffer_info().wAttributes & 0x0f)
							| details::background_colors.at( background ) );
		}

		void set_cursor_visible ( bool visible ) {
			CONSOLE_CURSOR_INFO lpCursor;
			GetConsoleCursorInfo( details::hStdout, &lpCursor );

			lpCursor.bVisible = visible;

			SetConsoleCursorInfo( details::hStdout, &lpCursor );
		}

		void clear_screen () {
			COORD coordScreen = { 0, 0 };

			DWORD cCharsWritten;
			CONSOLE_SCREEN_BUFFER_INFO csbi;
			DWORD dwConSize;

			// get the number of character cells in the current buffer
			GetConsoleScreenBufferInfo( details::hStdout, &csbi );
			dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

			// fill the entire screen with blanks
			FillConsoleOutputCharacter( details::hStdout, (TCHAR) ' ', dwConSize, coordScreen, &cCharsWritten );

			// get the current text attribute
			GetConsoleScreenBufferInfo( details::hStdout, &csbi );

			// now set the buffer's attributes accordingly
			FillConsoleOutputAttribute( details::hStdout, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten );

			// put the cursor at (0, 0)
			SetConsoleCursorPosition( details::hStdout, coordScreen );
		}

		void register_resize_callback ( std::function<void ( position )> callback ) {
			if ( details::resize_callbacks.empty() ) {
				std::async(std::launch::async, [] {
					INPUT_RECORD event;
					DWORD num_events;

					while (true) {
						ReadConsoleInput(details::hStdout, &event, 1, &num_events);

						if (event.EventType == WINDOW_BUFFER_SIZE_EVENT) {
							position size{event.Event.WindowBufferSizeEvent.dwSize.X, event.Event.WindowBufferSizeEvent.dwSize.Y};

							for (const resize_callback& callback : details::resize_callbacks) {
								callback(size);
							}
						}
					}
				});
			}

			details::resize_callbacks.push_back( callback );
		}

#endif

		void ring_bell () {
			std::cout << '\a';
		}

		void flush_screen () {
			std::cout.flush();
		}
	}
}
