#include <stdio.h>

struct Process {
	int arrival_time;
	int duration_time;
};

int main() {

	int proccesses = 0, quantum_time = 0, process = 0;
	int finish_execution = 0, check = 0, check_2 = 0, response = 0;
	int finish_time = 0, response_time = 0, wait_time = 0;
	float average_finish_time = 0, average_response_time = 0, average_wait_time = 0;

    // Cria o processo Main e armazena os Tempos
	scanf("%d %d", &proccesses, &quantum_time);
	struct Process main_process[proccesses+1];
	int time[proccesses+1];

    // Lê o Tempo da execução do Processo e da Chegada
	for (int index = 0; index < proccesses; index++) {
		scanf("%d %d", &main_process[index].arrival_time, &main_process[index].duration_time);
		time[index] = main_process[index].duration_time;
	}
	process = proccesses;

	for (int index = 0, finish_execution = 0; process != 0;) {

		if (time[index] > 0 && time[index] <= quantum_time) {
			finish_execution = finish_execution + time[index];
			time[index] = 0;
			check_2 = 1;
		}
        
        else if (time[index] > 0) {
			time[index] = time[index] - quantum_time;
			finish_execution = finish_execution + quantum_time;
            
			if (check == 1) {
				response++;
				check = 0;
			}
		}

		if (check_2 == 1 && time[index] == 0) {
			process--;
            wait_time += finish_execution - main_process[index].duration_time - main_process[index].arrival_time;
            finish_time += finish_execution - main_process[index].arrival_time;
			check_2 = 0;
		}

		if (index == proccesses - 1) {
			index = 0;
			check = 1;
		}

        else if (main_process[index+1].arrival_time <= finish_execution) {
			index++;
        }

		else {
			index = 0;
        }
    }

    	average_finish_time = finish_time * 1.0 / proccesses;
    	average_response_time = response * 1.0 / proccesses;
	average_wait_time = wait_time * 1.0 / proccesses;
	printf("RR %.1f %.1f %.1f\n", average_finish_time+1, average_response_time, average_wait_time+1);
	return 0;
}
