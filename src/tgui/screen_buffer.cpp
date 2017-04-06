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

#include "screen_buffer.hpp"

namespace tgui {
	screen_buffer::cell::cell () :
			character( L' ' ), foreground( screen::color::WHITE ), background( screen::color::BLACK ) {
	}

	bool screen_buffer::cell::operator == ( const cell& rhs ) const {
		return (character == rhs.character) && (foreground == rhs.foreground) && (background == rhs.background);
	}

	bool screen_buffer::cell::operator != ( const cell& rhs ) const {
		return !(*this == rhs);
	}

	screen_buffer::screen_buffer ( const screen::size& size ) :
			cells( size.column, std::vector<cell>( size.row ) ), size( size ) {
	}

	void screen_buffer::render ( const screen_buffer& old_buffer ) const {
		std::function<bool ( const screen::position& )> cell_changed;

		if ( size == old_buffer.size ) {
			cell_changed = [this, &old_buffer](const screen::position& pos) {
				return cells[pos.column][pos.row] != old_buffer.cells[pos.column][pos.row];
			};
		} else {
			cell_changed = [](const screen::position&) {return true;};
		}

		screen::set_cursor_position( 0, 0 );

		// TODO actual rendering
	}

	bool screen_buffer::operator == ( const screen_buffer& rhs ) const {
		return cells == rhs.cells;
	}

	bool screen_buffer::operator != ( const screen_buffer& rhs ) const {
		return !(*this == rhs);
	}
}
