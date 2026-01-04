template <class F>
int first_true(int lo, int hi, F pred) { // [lo,hi)
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (pred(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

template <class F>
int last_true(int lo, int hi, F pred) { // [lo,hi]
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (pred(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

inline int lower_bound_idx(const vector<int>& a, int x) {
    int n = (int) a.size();
    return first_true(0, n, [&](int i) { return a[i] >= x; });
}

inline int upper_bound_idx(const vector<int>& a, int x) {
    int n = (int) a.size();
    return first_true(0, n, [&](int i) { return a[i] > x; });
}

inline int last_le(const vector<int>& a, int x) { // upper_bound_idx(a, x) - 1
    int n = (int) a.size();
    if (n == 0) return -1;
    auto pred = [&](int i) { return a[i] <= x; };
    if (!pred(0)) return -1;
    return last_true(0, n - 1, pred);
}

inline int last_lt(const vector<int>& a, int x) { // lower_bound_idx(a, x) - 1
    int n = (int) a.size();
    if (n == 0) return -1;
    auto pred = [&](int i) { return a[i] < x; };
    if (!pred(0)) return -1;
    return last_true(0, n - 1, pred);
}
