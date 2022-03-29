#ifndef PROCESS_H
#define PROCESS_H

struct Process {
  int arrival_time;
  int burst_time;
  int remaining_burst;
  int duration;
};

Process process_maker(int arrival_time, int burst_time);

#endif
