string A = "01";
long long DectoN(string dec) {
    int n = A.size();
    long long ans = 0;
    long long now = 1;
    for (int i = dec.size() - 1; i >= 0; i--) {
        ans += (long long)distance(A.begin(), find(A.begin(), A.end(), dec[i])) * now;
        now *= n;
    }
    return ans;
}