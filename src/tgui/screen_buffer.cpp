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

	void screen_buffer::render () const {
		// TODO render
	}

	bool screen_buffer::operator == ( const screen_buffer& rhs ) const {
		return cells == rhs.cells;
	}

	bool screen_buffer::operator != ( const screen_buffer& rhs ) const {
		return !(*this == rhs);
	}
}
