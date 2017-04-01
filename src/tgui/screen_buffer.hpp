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
		private:
			wchar_t character;
			screen::color foreground;
			screen::color background;

		public:
			cell ();

			bool operator == ( const cell& rhs ) const;
			bool operator != ( const cell& rhs ) const;
		};

	private:
		std::vector<std::vector<cell>> cells;

	public:
		void render () const;

		bool operator == ( const screen_buffer& rhs ) const;
		bool operator != ( const screen_buffer& rhs ) const;
	};
}

#endif // #ifndef TGUI_TGUI_SCREEN_BUFFER_HPP
