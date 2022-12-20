vector<pair<char, int>> rle(string s) {
    vector<pair<char, int>> ret;
    int cnt = 1;
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] != s[i - 1]) {
            ret.push_back({s[i - 1], cnt});
            cnt = 0;
        }
        cnt++;
    }
    ret.push_back({s.back(), cnt});
    return ret;
}