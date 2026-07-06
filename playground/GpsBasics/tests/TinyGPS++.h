#pragma once
#include <cstdint>

struct TinyGPSLocation {
    bool _valid = false;
    double _lat = 0.0, _lng = 0.0;
    bool isValid() const { return _valid; }
    double lat()   const { return _lat; }
    double lng()   const { return _lng; }
};

struct TinyGPSAltitude {
    bool _valid = false;
    double _meters = 0.0;
    bool isValid()    const { return _valid; }
    double meters()   const { return _meters; }
};

struct TinyGPSDate {
    bool _valid = false;
    uint16_t _year = 0;
    uint8_t  _month = 0, _day = 0;
    bool    isValid() const { return _valid; }
    uint16_t year()   const { return _year; }
    uint8_t  month()  const { return _month; }
    uint8_t  day()    const { return _day; }
};

struct TinyGPSTime {
    bool _valid = false;
    uint8_t _hour = 0, _minute = 0, _second = 0;
    bool   isValid() const { return _valid; }
    uint8_t hour()   const { return _hour; }
    uint8_t minute() const { return _minute; }
    uint8_t second() const { return _second; }
};

struct TinyGPSInteger {
    bool _valid = false;
    uint32_t _value = 0;
    bool     isValid() const { return _valid; }
    uint32_t value()   const { return _value; }
};

class TinyGPSPlus {
public:
    TinyGPSLocation location;
    TinyGPSAltitude altitude;
    TinyGPSDate     date;
    TinyGPSTime     time;
    TinyGPSInteger  satellites;
};
