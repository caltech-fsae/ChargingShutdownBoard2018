//TODO(@bgberr): should probably profile this on the boards and make sure it's not crazy slow
#include "scheduler.h"

void MakeSchedule(Schedule *schedule, uint8_t schedule_size) {
  schedule->schedule_ = malloc(sizeof(Schedule) * schedule_size);
  schedule->max_schedule_size_ = schedule_size;
  schedule->schedule_size_ = 0;
  schedule->counter_ = 0;
}

int AddTask(Schedule *schedule, void (*function)(void), uint16_t period) {
  if(schedule->schedule_size_ >= schedule->max_schedule_size_) {
    return 0;
  }

  Task *task = &schedule->schedule_[schedule->schedule_size_];
  task->func_ = function;
  task->period_ = period;
  schedule->schedule_size_++;
  return 1;
}

void RunSchedule(Schedule *schedule) {
  schedule->counter_++;
  for(uint8_t i = 0; i < schedule->schedule_size_; i++) {
    schedule->counter_ % schedule->schedule_[i].period_ ? 0 : schedule->schedule_[i].func_();
  }
}

void DeleteSchedule(Schedule schedule) {
  free(schedule.schedule_);
}

