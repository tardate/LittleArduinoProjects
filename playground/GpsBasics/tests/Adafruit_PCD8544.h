#pragma once
#include <cstdint>
#include <string>
#include <cstdio>

class Adafruit_PCD8544 {
public:
    std::string output;

    void begin() {}
    void setContrast(uint8_t) {}
    void clearDisplay() { output.clear(); }
    void setTextSize(uint8_t) {}
    void setTextColor(uint8_t) {}
    void setCursor(int16_t, int16_t) {}
    void display() {}

    void print(const char *s)   { output += s; }
    void println(const char *s) { output += s; output += '\n'; }
    void print(double v)        { char buf[32]; snprintf(buf, sizeof(buf), "%f", v); output += buf; }
    void println(double v)      { print(v); output += '\n'; }
    void print(long v)          { char buf[32]; snprintf(buf, sizeof(buf), "%ld", v); output += buf; }
    void println(long v)        { print(v); output += '\n'; }
    void print(unsigned long v)  { char buf[32]; snprintf(buf, sizeof(buf), "%lu", v); output += buf; }
    void println(unsigned long v){ print(v); output += '\n'; }
    void print(uint32_t v)       { print(static_cast<unsigned long>(v)); }
    void println(uint32_t v)     { println(static_cast<unsigned long>(v)); }
    void print(int v)            { char buf[32]; snprintf(buf, sizeof(buf), "%d", v); output += buf; }
    void println(int v)          { print(v); output += '\n'; }
};
