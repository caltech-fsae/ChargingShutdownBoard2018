#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <stdlib.h>
#include <stdint.h>

typedef struct {
  void (* func_)(void);
  uint16_t period_;
} Task;

typedef struct {
  Task* schedule_;
  uint8_t schedule_size_;
  uint8_t max_schedule_size_;
  uint32_t counter_;
} Schedule;

void MakeSchedule(Schedule *schedule, uint8_t max_schedule_size);
int AddTask(Schedule *schedule, void (*function)(void), uint16_t period);
void RunSchedule(Schedule *schedule);
void DeleteSchedule(Schedule schedule);

#endif //SCHEDULER_H_
