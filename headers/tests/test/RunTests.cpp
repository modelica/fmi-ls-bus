#include <gtest/gtest.h>

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    std::cout << "TEST_DIR '" << TEST_DIR << "'" << std::endl;
    for (int i = 1; i < argc; ++i) {
        std::cout << "Input[" << i+2 << "]: " << argv[i] << std::endl;
    }

    return RUN_ALL_TESTS();
}