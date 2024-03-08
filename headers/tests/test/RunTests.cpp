#include <gtest/gtest.h>

int main(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        std::cout << "Input" << i << "]: " << argv[i] << std::endl;
    }
}