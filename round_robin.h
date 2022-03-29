#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H

#include "process.h"
#include <list>

void round_robin(std::list<Process> processes, int quantum);

#endif
