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
