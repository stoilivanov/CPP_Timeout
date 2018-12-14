#pragma once

#include <ctime>          // std::time_t, std::tm, std::localtime, std::mktime
#include <vector>
#include <thread>
#include <functional>

namespace sivanov {

	/**
	 * Class Timeout
	 *
	 * This class executes anonymous functions with a delay
	 *
	 */
	class Timeout
	{
		bool run_thread = true;
		std::thread timerThread;
		std::vector<std::pair<std::time_t, std::function<void()>>> lambdas;

		/**
		 * This function spins during the life-cycle of the class in order to
		 * execute lambdas whose timers have expired
		 */
		void threadCore()
		{
			while (run_thread) {
				std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

				for (int i = 0; i < lambdas.size(); i++) {
					int x = lambdas.at(i).first - now;
					if (x <= 0) {
						lambdas.at(i).second();		// execute lambda
						lambdas.erase(lambdas.begin() + i);	// delete lambda
						i--;
					}
				}

				std::this_thread::sleep_for(std::chrono::milliseconds(500));
			}
		}

	public:
		/**
		 * Class Constructor
		 *
		 * Spin a thread that will wait for lambdas to time out and execute them
		 */
		Timeout()
		{
			timerThread = std::thread([this] { this->threadCore(); });
		};

		/**
		 * Class Destructor
		 */
		~Timeout()
		{
			run_thread = false;
			if (timerThread.joinable())
				timerThread.join();
		};

		/**
		 * Run from main thread to make it wait for all of the timeouts to finish
		 * before potentionally ending the program
		 */
		void wait()
		{
			while (lambdas.size() > 0) {
				// hold destruction until we have executed all of our lambdas
			}
		}

		/**
		 * Overload the () operator for easier use of the class
		 */
		void operator()(std::function<void()> lambda, int seconds)
		{
			std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) + seconds;
			lambdas.push_back(std::make_pair(now, lambda));
		}
	};

}
