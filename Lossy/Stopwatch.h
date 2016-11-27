/* Copyright (c) 2016 SteamB23
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#pragma once

#include <Windows.h>
#pragma comment(lib, "Winmm.lib")

namespace SteamB23
{
	class Stopwatch
	{
	private:
		static const LONGLONG TicksPerMillisecond = 10000;
		static const LONGLONG TicksPerSecond = TicksPerMillisecond * 1000;

		LONGLONG elapsed;
		LONGLONG startTimeStamp;
		BOOL isRunning;

		// performance-counter frequency, in counts per ticks.
		// This can speed up conversion from high frequency performance-counter 
		// to ticks. 
		static DOUBLE tickFrequency;

		static LONGLONG frequency;
		static BOOL isHighResolution;

		static BOOL isInitialized;
	public:
		// "Frequency" stores the frequency of the high-resolution performance counter, 
		// if one exists. Otherwise it will store TicksPerSecond. 
		// The frequency cannot change while the system is running,
		// so we only need to initialize it once. 
		static LONGLONG Frequency();
		static BOOL IsHighResolution();
		static void Initialize();

		Stopwatch();
		
		void Start();
		void Stop();
		void Reset();
		void Restart();

		bool IsRunning()
		{
			return isRunning;
		}
		double GetElapsedTotalSeconds();
		double GetElapsedTotalMiliseconds();
		LONGLONG GetElapsedMiliseconds();
		LONGLONG GetElapsedTicks();

		

		static LONGLONG GetTimeStamp();
	private:
		LONGLONG GetElapsedDataTimeTicks();
	};
}