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
