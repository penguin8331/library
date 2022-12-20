long double dis(pair<int, int> a, pair<int, int> b) {
    return sqrt(pow(abs(b.first - a.first), 2) + pow(abs(b.second - a.second), 2));
}