#pragma once
#include "SDL.h"
#include <iostream>
#include "sigslot.h"
#include "Debug.h"
#include <chrono>

using namespace sigslot;

class Clock
{
public:
	//Updates all clock variables. This should only ever be ran once every frame.
	void Tick();

	/* Getters */
	//Time it took for the last frame to complete.
	const double& FrameDelta() { return frameDelta; }
	//Total amount of time elapsed since the program started.
	const Uint64& RunningTime() { return runningTime; }

	//Sigslot event implementation.
	//https://github.com/palacaze/sigslot
	signal<> OnTick;

	class Timer
	{
	public:
		Timer() { m_startPoint = std::chrono::high_resolution_clock::now(); }
		~Timer() { Stop(); }

		void Stop();
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_startPoint;
	};
private:
	//Total amount of time elapsed since the program started.
	Uint64 runningTime = 0;

	//SDL tick of the last frame.
	Uint64 previousFrameDelta = 0;

	//Time it took for the last frame to complete.
	double frameDelta = 0;
};