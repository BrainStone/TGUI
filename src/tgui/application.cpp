/**
 * @file tgui/application.cpp
 *
 * @brief This file contains the implementations of the tgui::application class.
 */

#include "application.hpp"

namespace tgui {
	void application::on_screen_resize ( screen::position TGUI_UNUSED(new_size) ) {
		// TODO on_screen_resize
	}

	void application::render_loop () {
		using namespace std::chrono;

		steady_clock::duration time_step = duration_cast<steady_clock::duration>( seconds( 1 ) ) / fps;
		steady_clock::time_point next_frame = steady_clock::now();
		steady_clock::time_point now;
		std::mutex render_loop_cv_m;
		std::unique_lock<std::mutex> render_loop_cv_lock( render_loop_cv_m );

		while ( run_render_loop ) {
			render_objects();
			render_to_screen();

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
		// TODO render_objects
	}

	void application::render_to_screen () {
		// TODO render_to_screen
	}

	application::application ( int fps, bool auto_rerender ) :
			fps { fps }, auto_rerender { auto_rerender }, run_render_loop { true }, render_thread {
					&application::render_loop, this }, old_buffer { new screen_buffer() }, new_buffer { new screen_buffer() } {
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
