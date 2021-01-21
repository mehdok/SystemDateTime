#ifndef SystemDateTime_h
#define SystemDateTime_h

#include "Arduino.h"

class SystemDateTime {
  public:
    uint8_t seconds;
    uint8_t minutes;
    uint8_t hours;
    uint8_t day;
    uint8_t week;
    uint8_t month;
    uint16_t year;

    static const char *monthName[12];

    SystemDateTime(uint16_t y,
                   uint8_t mon,
                   uint8_t d,
                   uint8_t hour,
                   uint8_t min,
                   uint8_t sec);
    
    static SystemDateTime getCurrentDateTimeFromPC();
};

#endif
