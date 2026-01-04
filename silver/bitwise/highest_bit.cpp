inline int highest_bit(int x) {
    if (x <= 0) {
        return -1;
    }
    return 31 - __builtin_clz(x);
}

inline int highest_bit(long long x) {
    if (x <= 0) {
        return -1;
    }
    return 63 - __builtin_clzll(x);
}
