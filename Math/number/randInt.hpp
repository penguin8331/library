unsigned int randInt() {
    static unsigned int tx = 123456789, ty = 362436069, tz = 521288629, tw = 88675123;
    unsigned int tt = (tx ^ (tx << 11));
    tx = ty;
    ty = tz;
    tz = tw;
    return (tw = (tw ^ (tw >> 19)) ^ (tt ^ (tt >> 8)));
}