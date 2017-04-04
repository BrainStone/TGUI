#ifndef TGUI_TGUI_APPLICATION_HPP
#define TGUI_TGUI_APPLICATION_HPP

/**
 * @file tgui/application.hpp
 *
 * @brief This file contains the tgui::application class.
 */

#include "config.hpp"
#include "screen_buffer.hpp"
#include "screen.hpp"

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <thread>

namespace tgui {
	class application {
	protected:
		const int fps;
		const bool auto_rerender;
		std::condition_variable render_loop_cv;
		std::atomic<bool> run_render_loop;
		std::thread render_thread;
		std::shared_ptr<screen_buffer> old_buffer;
		std::shared_ptr<screen_buffer> new_buffer;

		virtual void on_screen_resize ( screen::position new_size );
		virtual void render_loop ();
		virtual void render_objects ();
		virtual void render_to_screen ();
	public:
		application ( int fps = 10, bool auto_rerender = true );
		application ( const application& cpy ) = delete;
		application ( application&& cpy ) = delete;
		virtual ~application ();
	};
}

#endif // #ifndef TGUI_TGUI_APPLICATION_HPP
