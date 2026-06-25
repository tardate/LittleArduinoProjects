#include <gtest/gtest.h>
#include <cstdio>
#include <cstring>

// Must match the buffer size declared in display_controller.cpp
static const int DISPLAY_BUFFER_SIZE = 32;

// ---------------------------------------------------------------------------
// Date format: "%02d-%02d-%02d"
// TinyGPS++ returns year as uint16_t (0-65535), month/day as uint8_t (0-255).
// Maximum possible output: "65535-255-255" = 13 chars + NUL  -> well within 32.
// ---------------------------------------------------------------------------
TEST(BufferSafetyTest, DateFormatNeverOverflowsBuffer) {
    struct { unsigned int year; unsigned int month; unsigned int day; const char* label; } cases[] = {
        { 2023,  12,  31, "normal date"          },
        { 9999,  12,  31, "max realistic year"   },
        {65535, 255, 255, "max uint16/uint8 vals" },
        {    0,   0,   0, "zero values"           },
    };

    for (auto& c : cases) {
        char sz[DISPLAY_BUFFER_SIZE];
        int written = snprintf(sz, sizeof(sz), "%02d-%02d-%02d",
                               c.year, c.month, c.day);
        EXPECT_GE(written, 0)
            << "snprintf returned error for " << c.label;
        // snprintf returns the number of chars that *would* have been written;
        // if >= buffer size the output was truncated (overflow prevented but
        // the invariant - full value fits - is violated).
        EXPECT_LT(written, DISPLAY_BUFFER_SIZE)
            << "Output would be truncated for " << c.label
            << " (year=" << c.year
            << " month=" << c.month
            << " day=" << c.day << ")";
    }
}

// ---------------------------------------------------------------------------
// Time format: "%02d:%02d:%02d"
// TinyGPS++ returns hour/minute/second as uint8_t (0-255).
// Maximum possible output: "255:255:255" = 11 chars + NUL -> well within 32.
// ---------------------------------------------------------------------------
TEST(BufferSafetyTest, TimeFormatNeverOverflowsBuffer) {
    struct { unsigned int hour; unsigned int minute; unsigned int second; const char* label; } cases[] = {
        { 23, 59, 59,  "max normal time"      },
        {255, 255, 255, "max uint8 values"     },
        {  0,  0,  0,  "zero values"           },
    };

    for (auto& c : cases) {
        char sz[DISPLAY_BUFFER_SIZE];
        int written = snprintf(sz, sizeof(sz), "%02d:%02d:%02d",
                               c.hour, c.minute, c.second);
        EXPECT_GE(written, 0)
            << "snprintf returned error for " << c.label;
        EXPECT_LT(written, DISPLAY_BUFFER_SIZE)
            << "Output would be truncated for " << c.label
            << " (hour=" << c.hour
            << " minute=" << c.minute
            << " second=" << c.second << ")";
    }
}

// ---------------------------------------------------------------------------
// Regression guard: the source file must use snprintf, not sprintf.
// Reads ../display_controller.cpp (relative to the tests/ directory) and
// checks that no bare sprintf() calls remain.
// ---------------------------------------------------------------------------
TEST(BufferSafetyTest, SourceFileUsesSnprintfNotSprintf) {
    FILE* f = fopen("../display_controller.cpp", "r");
    ASSERT_NE(f, nullptr)
        << "Could not open ../display_controller.cpp - run tests from the "
           "playground/GpsBasics/tests/ directory";

    char line[512];
    int line_no = 0;
    bool violation_found = false;

    while (fgets(line, sizeof(line), f)) {
        ++line_no;
        // Flag any bare sprintf( that is not snprintf(
        if (strstr(line, "sprintf(") && !strstr(line, "snprintf(")) {
            ADD_FAILURE() << "Unsafe sprintf() on line " << line_no
                          << ": " << line;
            violation_found = true;
        }
    }
    fclose(f);

    EXPECT_FALSE(violation_found)
        << "display_controller.cpp contains unsafe sprintf() calls. "
           "Replace with snprintf() to prevent buffer overflows.";
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
