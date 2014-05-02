#include <stdio.h>
#include <stdint.h>
#include <time.h>

#include "mytime.h"

//-----------------------------------------------------

static time_t t_start;

//-----------------------------------------------------

void e2_time_start(void)
{
  (void)time(&t_start);

  printf("TIME START: sizeof(time)=%d %s", sizeof(t_start), ctime(&t_start));
}

//-----------------------------------------------------
void e2_time_print_duration(void)
{
  int32_t days, hours, mins, secs;

  time_t t_end;
  time_t t_diff;

  (void)time(&t_end);

  printf("TIME STAMP: %s", ctime(&t_end));

  t_diff = t_end - t_start;
  days = t_diff / (3600 * 24);
  t_diff -= days * (3600 * 24);
  hours = t_diff / 3600;
  t_diff -= hours * 3600;
  mins = t_diff / 60;
  t_diff -= mins * 60;
  secs = t_diff;

  printf("TIME DURATION: %d days %d hours %d minutes %d seconds\n", days, hours, mins, secs);
}
