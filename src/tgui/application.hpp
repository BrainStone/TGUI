#ifndef TGUI_TGUI_APPLICATION_HPP
#define TGUI_TGUI_APPLICATION_HPP

#include "config.hpp"
#include "screen.hpp"

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <thread>

namespace tgui {
	class application {
	private:
		const int fps;
		const bool auto_rerender;
		std::condition_variable render_loop_cv;
		std::atomic<bool> run_render_loop;
		std::thread render_thread;

		void on_screen_resize ( screen::position new_size );
		void render_loop ();
		void render_objects ();
		void render_to_screen ();
	public:
		application ( int fps = 10, bool auto_rerender = true );
		application ( const application& cpy ) = delete;
		application ( application&& cpy ) = delete;
		~application ();
	};
}

#endif // #ifndef TGUI_TGUI_APPLICATION_HPP
