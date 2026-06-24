#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include <iostream>

class SecurityTest : public ::testing::TestWithParam<std::string> {};

TEST_P(SecurityTest, BufferReadsNeverExceedDeclaredLength) {
    // Invariant: Buffer reads never exceed the declared length
    std::string payload = GetParam();
    
    // Create a test file with the payload
    std::ofstream test_file("test_gps_input.txt");
    test_file << payload;
    test_file.close();
    
    // Execute the actual production code with the payload
    std::string command = "./display_controller test_gps_input.txt";
    FILE* pipe = popen(command.c_str(), "r");
    ASSERT_TRUE(pipe != nullptr) << "Failed to execute production code";
    
    // Read output safely
    char buffer[256];
    std::string result;
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }
    
    int return_code = pclose(pipe);
    
    // Clean up test file
    remove("test_gps_input.txt");
    
    // Assert no crash occurred (return code should indicate normal termination)
    EXPECT_TRUE(WIFEXITED(return_code)) << "Program crashed with payload: " << payload;
    if (WIFEXITED(return_code)) {
        EXPECT_EQ(WEXITSTATUS(return_code), 0) << "Program exited abnormally with payload: " << payload;
    }
}

INSTANTIATE_TEST_SUITE_P(
    AdversarialInputs,
    SecurityTest,
    ::testing::Values(
        // Valid input (boundary case)
        "2023-12-31 23:59:59",
        // Exact exploit case - oversized year/month/day
        "99999-99-99 99:99:99",
        // 10x oversized input
        "2023-12-31 23:59:59 2023-12-31 23:59:59 2023-12-31 23:59:59 2023-12-31 23:59:59 2023-12-31 23:59:59",
        // Malformed input with special characters
        "%%%%-%%-%% %%:%%:%%"
    )
);

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}