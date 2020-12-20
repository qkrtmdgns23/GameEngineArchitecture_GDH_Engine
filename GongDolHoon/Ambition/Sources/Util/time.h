#ifndef __AMBITION_TIME__
#define __AMBITION_TIME__

#include "framework.h"
#include "pch.h"
#include "singleton.h"

namespace ambition
{
	namespace util
	{
		AMBITION_ENUM FramePerSecond: int8_t
		{
			kPhysics	= 30,
			kRender		= 144,
			kLogic		= 60
		};

		AMBITION_STRUCT Frame
		{
			int64_t			time_distance;
			int64_t			per_frame;
			LARGE_INTEGER	current_frame_counter;
			LARGE_INTEGER	previous_frame_counter;
		};

		AMBITION_CLASS Time: public Singleton<Time>
		{
		public:
			Time();
			Time(const Time& other) = delete;
			~Time() = default;
		public:
			inline bool		UpdateRenderPossible();
			inline bool		UpdateLogicPossible();
			inline bool		UpdatePhysicsPossible();
			inline int64_t	GetDeltaTime() const;
		private:
			inline bool		UpdatePossible(Frame& target);

		private:
			LARGE_INTEGER	frame_info_;
			int64_t			delta_time_;
			Frame			render_;
			Frame			logic_;
			Frame			physics_;
		};

		Time::Time(): delta_time_(0)
		{
			QueryPerformanceFrequency(&frame_info_);
			QueryPerformanceCounter(&render_.current_frame_counter);
			QueryPerformanceCounter(&logic_.current_frame_counter);
			QueryPerformanceCounter(&render_.previous_frame_counter);
			QueryPerformanceCounter(&logic_.previous_frame_counter);

			render_.time_distance = 0;
			logic_.time_distance = 0;
			render_.per_frame = 0;
			logic_.per_frame = 0;

			render_.per_frame = frame_info_.QuadPart
				/ static_cast<int64_t>(FramePerSecond::kRender);
			logic_.per_frame = frame_info_.QuadPart
				/ static_cast<int64_t>(FramePerSecond::kLogic);
		}

		inline bool		Time::UpdateRenderPossible()
		{
			return UpdatePossible(render_);
		}
		inline bool		Time::UpdateLogicPossible()
		{
			return UpdatePossible(logic_);
		}
		inline bool		Time::UpdatePhysicsPossible()
		{
			return UpdatePossible(physics_);
		}
		int64_t Time::GetDeltaTime() const
		{
			return delta_time_;
		}
		
		bool Time::UpdatePossible(Frame& target)
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
	}		// namespace util
}			// namespace ambition

#endif		// __AMBITION_TIME__