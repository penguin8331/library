long long extGcd(long long a, long long b, long long &p, long long &q) {
    if (b == 0) { 
        p = 1, q = 0; 
        return a; 
    }
    long long d = extGcd(b, a % b, q, p);
    q -= a / b * p;
    return d;
}