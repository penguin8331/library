string A = "01";
string DectoN(long long dec) {
    int n = A.size();
    string ans;
    while (dec > 0) {
        // A[0]が1なら入れる
        // dec--;
        ans += A[(dec) % n];
        dec = dec / n;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}