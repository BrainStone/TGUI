#include "application.hpp"

namespace tgui {
	void application::on_screen_resize ( screen::position TGUI_UNUSED(new_size) ) {
		// TODO on_screen_resize
	}

	void application::render_loop () {
		std::chrono::steady_clock::duration time_step = std::chrono::duration_cast<std::chrono::steady_clock::duration>( std::chrono::seconds( 1 ) ) / fps;
		std::chrono::steady_clock::time_point next_frame = std::chrono::steady_clock::now();
		std::mutex render_loop_cv_m;
		std::unique_lock<std::mutex> render_loop_cv_lock( render_loop_cv_m );

		while ( run_render_loop ) {
			render_objects();
			render_to_screen();

			next_frame += time_step;
			render_loop_cv.wait_until( render_loop_cv_lock, next_frame, [this, &next_frame] {
				return (std::chrono::steady_clock::now() >= next_frame) || !run_render_loop;
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
			fps { fps }, auto_rerender { auto_rerender }, run_render_loop { true }, render_thread { application::render_loop, this } {
		if ( auto_rerender ) {
			screen::register_resize_callback( std::bind( application::on_screen_resize, this, std::placeholders::_1 ) );
		}
	}

	application::~application () {
		run_render_loop = false;
		render_loop_cv.notify_all();

		render_thread.join();
	}
}
