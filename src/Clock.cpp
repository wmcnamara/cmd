#include "Clock.h"

void Clock::Tick()
{
	//Set the frameDetlta, runningTime, and call OnTick.
	runningTime = SDL_GetPerformanceCounter();
	frameDelta = static_cast<double>(runningTime - previousFrameDelta) * 1000 / static_cast<double>(SDL_GetPerformanceFrequency());
	OnTick();
}

void Clock::Timer::Stop()
{
	//Get the current time, and convert it.
	auto endPoint = std::chrono::high_resolution_clock::now();

	auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startPoint).time_since_epoch().count();
	auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endPoint).time_since_epoch().count();

	auto duration = end - start;

	Debug::Log(std::cout, "Time elapsed: " + duration, LOG_PERFORMANCE);
}
