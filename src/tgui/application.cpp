#include "application.hpp"

namespace tgui {
	void application::on_screen_resize(screen::position new_size) {
		;
	}

	application::application ( bool auto_rerender ) :
			auto_rerender( auto_rerender ) {
		if ( auto_rerender ) {
			screen::register_resize_callback( std::bind( &on_screen_resize, *this, std::placeholders::_1 ) );
		}
	}
}
