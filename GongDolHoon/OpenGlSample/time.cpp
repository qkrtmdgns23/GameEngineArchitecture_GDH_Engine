#include <iostream>
#include "time.h"

namespace gdh_system {
	Time* Time::instance_ = nullptr;

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
			/ static_cast<long long>(DefinedFrame::kRender);
		logic_.per_frame = frame_info_.QuadPart 
			/ static_cast<long long>(DefinedFrame::kLogic);
	}
}	// namespace gdh_system