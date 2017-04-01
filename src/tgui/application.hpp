#ifndef TGUI_TGUI_APPLICATION_HPP
#define TGUI_TGUI_APPLICATION_HPP

#include "config.hpp"
#include "screen.hpp"

#include <thread>

namespace tgui {
	class application {
	private:
		const bool auto_rerender;

		void on_screen_resize ( screen::position new_size );

	public:
		application ( bool auto_rerender = true );
	};
}

#endif // #ifndef TGUI_TGUI_APPLICATION_HPP
