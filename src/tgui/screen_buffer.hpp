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

#ifndef TGUI_TGUI_SCREEN_BUFFER_HPP
#define TGUI_TGUI_SCREEN_BUFFER_HPP

#include "config.hpp"
#include "screen.hpp"

#include <iostream>
#include <vector>

namespace tgui {
	class screen_buffer {
	public:
		class cell {
		protected:
			wchar_t character;
			screen::color foreground;
			screen::color background;

		public:
			cell ();
			virtual ~cell () = default;

			virtual void render ( screen::color& last_foreground, screen::color& last_background ) const;

			virtual bool operator == ( const cell& rhs ) const;
			virtual bool operator != ( const cell& rhs ) const;
		};

	protected:
		std::vector<std::vector<cell>> cells;
		screen::size size;

	public:
		screen_buffer ( const screen::size& size );
		virtual ~screen_buffer () = default;

		virtual void render ( const screen_buffer& old_buffer ) const;

		virtual bool operator == ( const screen_buffer& rhs ) const;
		virtual bool operator != ( const screen_buffer& rhs ) const;
	};
}

#endif // #ifndef TGUI_TGUI_SCREEN_BUFFER_HPP
