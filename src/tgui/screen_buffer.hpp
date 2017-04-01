#ifndef TGUI_TGUI_SCREEN_BUFFER_HPP
#define TGUI_TGUI_SCREEN_BUFFER_HPP

#include "config.hpp"
#include "screen.hpp"

#include <vector>

namespace tgui {
	class screen_buffer {
	public:
		class cell {
		private:
			wchar_t character;
			screen::color foreground;
			screen::color background;
		};

	private:
		std::vector<std::vector<cell>> cells;
	};
}

#endif // #ifndef TGUI_TGUI_SCREEN_BUFFER_HPP
