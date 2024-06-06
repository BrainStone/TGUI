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

#include "application.hpp"

/**
 * @file tgui/application.cpp
 *
 * @brief This file contains the implementations of the tgui::application class.
 */

namespace tgui {
	void application::on_screen_resize ( screen::size new_size ) {
		old_buffer = std::make_shared<screen_buffer>( new_size );
		new_buffer = std::make_shared<screen_buffer>( new_size );

		render( true );
	}

	void application::render_loop () {
		using namespace std::chrono;

		steady_clock::duration time_step = duration_cast<steady_clock::duration>( seconds( 1 ) ) / fps;
		steady_clock::time_point next_frame = steady_clock::now();
		steady_clock::time_point now;
		std::mutex render_loop_cv_m;
		std::unique_lock<std::mutex> render_loop_cv_lock( render_loop_cv_m );

		while ( run_render_loop ) {
			render();

			now = steady_clock::now();

			do {
				next_frame += time_step;
			} while ( next_frame > now );

			render_loop_cv.wait_until( render_loop_cv_lock, next_frame, [this, &next_frame] {
				return (steady_clock::now() >= next_frame) || !run_render_loop;
			} );
		}
	}

	void application::render_objects () {
		std::scoped_lock object_guard( object_lock );

		// TODO render_objects
	}

	void application::render_to_screen () {
		std::scoped_lock render_guard( render_lock );

		new_buffer->render( *old_buffer );

		old_buffer = new_buffer;
		new_buffer = std::make_shared<screen_buffer>( size );
	}

	void application::render ( bool clear_screen ) {
		std::scoped_lock object_guard( buffer_lock );

		render_objects();

		if ( clear_screen )
			screen::clear_screen();

		render_to_screen();
	}

	application::application ( int fps, bool auto_rerender ) :
			fps( fps ), auto_rerender( auto_rerender ), run_render_loop( true ), render_thread( &application::render_loop,
					this ), size( screen::get_size() ), old_buffer( new screen_buffer( size ) ), new_buffer(
					new screen_buffer( size ) ) {
		if ( auto_rerender ) {
			screen::register_resize_callback( std::bind( &application::on_screen_resize, this, std::placeholders::_1 ) );
		}
	}

	application::~application () {
		run_render_loop = false;
		render_loop_cv.notify_all();

		render_thread.join();
	}
}
