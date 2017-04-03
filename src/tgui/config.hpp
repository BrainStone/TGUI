#ifndef TGUI_TGUI_CONFIG_HPP
#define TGUI_TGUI_CONFIG_HPP

#ifdef __unix__
#define TGUI_LINUX
#elif defined(_WIN32) || defined(WIN32)
#define TGUI_WINDOWS
#else
#error Unsupported System!
#endif

/**
 * The namepsace for the TGUI Library. All methods and classes will be located inside this namespace or sub-namespaces.
 */
namespace tgui {
	/**
	 * The namespace for the screen and console utilities. This is the only place where platform dependend code is located.
	 */
	namespace screen {
		/**
		 * This namespace contains platform specific implementations.<br />
		 * <b>It is not recommended to use any methods inside this namespace!</b>
		 */
		namespace details {
		}
	}
}

#endif // #ifndef TGUI_TGUI_CONFIG_HPP
