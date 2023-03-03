#pragma once
#include "template.hpp"

struct IOSetup {
    IOSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout.tie(0);
        cout << std::fixed << std::setprecision(12);
        cerr << std::fixed << std::setprecision(12);
    }
};