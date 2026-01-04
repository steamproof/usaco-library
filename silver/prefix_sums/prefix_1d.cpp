template <typename T>
vector<T> prefix_sums_1d(const vector<T>& a) {
    int n = (int) a.size();
    vector<T> p(n + 1);
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i] + a[i];
    }
    return p;
}

// sum on [l, r) using prefix array p
template <typename T>
T range_sum_1d(const vector<T>& p, int l, int r) {
    return p[r] - p[l];
}
