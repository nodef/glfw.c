// Core/Common files (always included)
#include "context.c"
#include "egl_context.c"
#include "init.c"
#include "input.c"
#include "monitor.c"
#include "osmesa_context.c"
#include "platform.c"
#include "vulkan.c"
#include "window.c"

// Null platform (always included)
#include "null_init.c"
#include "null_joystick.c"
#include "null_monitor.c"
#include "null_window.c"

// Windows platform
#if defined(_GLFW_WIN32)
#include "wgl_context.c"
#include "win32_init.c"
#include "win32_joystick.c"
#include "win32_module.c"
#include "win32_monitor.c"
#include "win32_thread.c"
#include "win32_time.c"
#include "win32_window.c"

#endif

// macOS platform
#if defined(_GLFW_COCOA)
#include "cocoa_init.m"
#include "cocoa_joystick.m"
#include "cocoa_monitor.m"
#include "cocoa_time.c"
#include "cocoa_window.m"
#include "nsgl_context.m"

#endif

// X11 platform
#if defined(_GLFW_X11)
#include "glx_context.c"
#include "linux_joystick.c"
#include "x11_init.c"
#include "x11_monitor.c"
#include "x11_window.c"
#include "xkb_unicode.c"

#endif

// Wayland platform
#if defined(_GLFW_WAYLAND)
#include "linux_joystick.c"
#include "wl_init.c"
#include "wl_monitor.c"
#include "wl_window.c"
#include "xkb_unicode.c"

#endif

// POSIX threading (used on non-Windows platforms)
#if !defined(_WIN32)
#include "posix_module.c"
#include "posix_thread.c"

#endif

// POSIX time (used on POSIX platforms that aren't macOS)
#if !defined(_WIN32) && !defined(__APPLE__)
#include "posix_time.c"
#endif

// POSIX poll (used on Wayland and X11)
#if defined(_GLFW_WAYLAND) || defined(_GLFW_X11)
#include "posix_poll.c"
#endif
