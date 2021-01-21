#include "SystemDateTime.h"

const char *SystemDateTime::monthName[12] = {
    "Jan",
    "Feb",
    "Mar",
    "Apr",
    "May",
    "Jun",
    "Jul",
    "Aug",
    "Sep",
    "Oct",
    "Nov",
    "Dec"};

SystemDateTime::SystemDateTime(uint16_t y,
               uint8_t mon,
               uint8_t d,
               uint8_t hour,
               uint8_t min,
               uint8_t sec) {
    year=y;
    month=mon;
    day=d;
    hours=hour;
    minutes=min;
    seconds=sec;
    week = 0;
};

SystemDateTime SystemDateTime::getCurrentDateTimeFromPC() {
  int hour, minute, second;
    
  SystemDateTime empty = SystemDateTime(0, 0, 0, 0, 0, 0);
  
  // fill time
  if (sscanf(__TIME__, "%d:%d:%d", &hour, &minute, &second) != 3) return empty;

  char month[12];
  int day, year;
  uint8_t monthIndex;
  
  // fill date
  if(sscanf(__DATE__, "%s %d %d", month, &day, &year) != 3) return empty;
  for (monthIndex = 0; monthIndex < 12; monthIndex++) {
    if (strcmp(month, monthName[monthIndex]) == 0) break;
  }
  if (monthIndex >= 12) return empty;
  
  return SystemDateTime(year, monthIndex+1, day, hour, minute, second);
};
