#ifndef GDH_ENGINE_TIME_H
#define GDH_ENGINE_TIME_H
#include <Windows.h>
// include glfw to prevent redefinition error.
// https://stackoverflow.com/questions/3927810/how-to-prevent-macro-redefinition
#include "include/GLFW/glfw3.h" 

namespace gdh_system {
	namespace frame {
		enum class DefinedFrame {
			kRender = 60,
			kLogic = 120,
		};

		struct Frame {
			long long time_distance;
			long long per_frame;
			LARGE_INTEGER current_frame_counter;
			LARGE_INTEGER previous_frame_counter;
		};
	}	// namespace frame

	using namespace frame;

	class Time
	{
	#pragma region SINGLETON_PATTERN
	public:
		~Time() {}
		static Time* get_instance() {
			if (instance_ == nullptr)
			{
				instance_ = new Time();
				return instance_;
			}
			return instance_;
		}
	private:
		Time();
		static Time* instance_;
	#pragma endregion
	public:
		inline bool IsRenderUpdatePossible();
		inline bool IsLogicUpdatePossible();

		inline long long get_delta_time() const;
	private:
		inline bool IsFrameUpdate(Frame& target);

		long long delta_time_;

		LARGE_INTEGER frame_info_;

		Frame render_;
		Frame logic_;
	};

	long long Time::get_delta_time() const
	{
		return delta_time_;
	}
	
	bool Time::IsRenderUpdatePossible()
	{
		return IsFrameUpdate(render_);
	}

	bool Time::IsLogicUpdatePossible()
	{
		return IsFrameUpdate(logic_);
	}

	bool Time::IsFrameUpdate(Frame& target)
	{
		QueryPerformanceCounter(&target.current_frame_counter);

		target.time_distance = target.current_frame_counter.QuadPart - target.previous_frame_counter.QuadPart;
		if (target.time_distance > target.per_frame)
		{
			if (target.per_frame == logic_.per_frame)
			{
				delta_time_ = target.time_distance;
			}

			target.previous_frame_counter = target.current_frame_counter;
			return true;
		}
		return false;
	}
}	// namespace gdh_system
#endif // GDH_ENGINE_TIME_H
