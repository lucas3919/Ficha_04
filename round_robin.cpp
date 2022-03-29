#include "round_robin.h"
#include <iostream>
#include <queue>

void round_robin(std::list<Process> processes, int quantum) {
	double finish_time_average = 0.0, wait_time_average = 0.0, response_time_average = 0.0;
	int finish_time = 0, wait_time = 0, response_time = 0, i = quantum;
	int quantity = processes.size();

	std::list<Process>::iterator it = processes.begin();
	Process running;
	std::queue<Process> processes;
	bool process_running = false;

	for (int clock = 0; true; clock++) {

		while (it != processes.end() && clock == (*it).arrival_time) {
			processes.push_back((*it));
			it++;
		}

		if (!process_running) {

			if (!processes.empty()) {

				running = processes.front();
				processes.pop_front();
				process_running = true;
				i = quantum;

				if (running.duration == running.remaining_burst) {
					response_time = clock - running.arrival_time;
				}
			}

		}

		else {
			while (i > 0) {
				running.remaining_burst--;
				i--;

				if (running.remaining_burst == 0) {
					finish_time = wait_time + running.duration;
					process_running = false;
					finish_time_average += finish_time;
					response_time_average += response_time;
					wait_time_average += wait_time;

					finish_time = 0;
					response_time = 0;
					wait_time = 0;
					continue;
				}

				else if(i == 0) {
					processes.push_back(running);
					process_running = false;
				}
    		}
		}
		std::cout << "RR" << finish_time_average << " " << response_time_average << " " << wait_time_average << std::endl;
	}
}
