#include <gtest/gtest.h>
#include <string>

// Stub headers must be resolved before the real headers are pulled in.
#include "display_controller.h"
#include "display_controller.cpp"

class DisplayControllerTest : public ::testing::Test {
protected:
    Adafruit_PCD8544 display;
    TinyGPSPlus      gps;
    DisplayController *controller;

    void SetUp() override {
        controller = new DisplayController(&display, &gps);
        // location must be valid for update() to do anything
        gps.location._valid = true;
        gps.location._lat   = 1.0;
        gps.location._lng   = 1.0;
    }

    void TearDown() override {
        delete controller;
    }
};

TEST_F(DisplayControllerTest, UpdateFormatsDateCorrectly) {
    gps.date._valid = true;
    gps.date._year  = 2024;
    gps.date._month = 3;
    gps.date._day   = 5;

    controller->update();

    EXPECT_NE(display.output.find("2024-03-05"), std::string::npos)
        << "Expected formatted date '2024-03-05' in display output.\nActual output: " << display.output;
}

TEST_F(DisplayControllerTest, UpdateFormatsTimeCorrectly) {
    gps.time._valid  = true;
    gps.time._hour   = 8;
    gps.time._minute = 7;
    gps.time._second = 6;

    controller->update();

    EXPECT_NE(display.output.find("08:07:06"), std::string::npos)
        << "Expected formatted time '08:07:06' in display output.\nActual output: " << display.output;
}

TEST_F(DisplayControllerTest, UpdateSkipsDateWhenInvalid) {
    gps.date._valid = false;

    controller->update();

    // A date-shaped token contains '-'; confirm no YYYY-MM-DD pattern appears.
    // We check that none of the date fields (set to zero-default) produce output.
    EXPECT_EQ(display.output.find("00-00-00"), std::string::npos)
        << "Date should not be printed when gps.date is invalid.\nActual output: " << display.output;
}

TEST_F(DisplayControllerTest, UpdateSkipsTimeWhenInvalid) {
    gps.time._valid = false;

    controller->update();

    EXPECT_EQ(display.output.find("00:00:00"), std::string::npos)
        << "Time should not be printed when gps.time is invalid.\nActual output: " << display.output;
}

TEST_F(DisplayControllerTest, DateFormatFitsIn32ByteBuffer) {
    // TinyGPS++ year is uint16_t (max 65535), month/day are uint8_t (max 255).
    // Verify the actual application code handles worst-case values without truncation.
    gps.date._valid = true;
    gps.date._year  = 65535;
    gps.date._month = 255;
    gps.date._day   = 255;

    controller->update();

    EXPECT_NE(display.output.find("65535-255-255"), std::string::npos)
        << "Worst-case date '65535-255-255' should appear untruncated in display output.\nActual output: " << display.output;
}

TEST_F(DisplayControllerTest, TimeFormatFitsIn32ByteBuffer) {
    // TinyGPS++ hour/minute/second are uint8_t (max 255).
    // Verify the actual application code handles worst-case values without truncation.
    gps.time._valid  = true;
    gps.time._hour   = 255;
    gps.time._minute = 255;
    gps.time._second = 255;

    controller->update();

    EXPECT_NE(display.output.find("255:255:255"), std::string::npos)
        << "Worst-case time '255:255:255' should appear untruncated in display output.\nActual output: " << display.output;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
