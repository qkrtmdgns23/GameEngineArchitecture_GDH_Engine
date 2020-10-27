#ifndef GDH_ENGINE_ERROR_MANAGER
#define GDH_ENGINE_ERROR_MANAGER

namespace system_2 {
	enum class ErrorType
	{
		kGameInitFailed = 1,
		kWindowInitFailed = 2,
		kGlewInitFailed = 4,
		kGlfwInitFailed = 8,

	};
}	// namespace system

#endif // GDH_ENGINE_ERROR_MANAGER