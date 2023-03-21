#pragma once
#include "../template/template.hpp"

struct IOSetup {
    IOSetup() {
        std::cin.tie(nullptr);
        std::ios::sync_with_stdio(false);
        std::cout.tie(0);
        std::cout << std::fixed << std::setprecision(12);
        std::cerr << std::fixed << std::setprecision(12);
    }
} IOSetup;