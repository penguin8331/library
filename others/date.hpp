#pragma once
#include "../template/template.hpp"

vector<string> S = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
int GregorianDay(int y, int m, int d) {
    y += 4800;
    if (m < 3) {
        --y;
        m += 12;
    }
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 32083;
}
int dayWeek(int y, int m, int d) {
    return (GregorianDay(y, m, d) + 5) % 7;
}