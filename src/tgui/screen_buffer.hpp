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

			virtual bool operator == ( const cell& rhs ) const;
			virtual bool operator != ( const cell& rhs ) const;
		};

	protected:
		std::vector<std::vector<cell>> cells;

	public:
		virtual ~screen_buffer () = default;

		virtual void render () const;

		virtual bool operator == ( const screen_buffer& rhs ) const;
		virtual bool operator != ( const screen_buffer& rhs ) const;
	};
}

#endif // #ifndef TGUI_TGUI_SCREEN_BUFFER_HPP
