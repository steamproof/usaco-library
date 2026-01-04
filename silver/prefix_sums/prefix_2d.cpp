template <typename T>
vector<vector<T>> prefix_sums_2d(const vector<vector<T>>& a) {
    int n = (int) a.size();
    int m = (n ? (int) a[0].size() : 0);
    vector<vector<T>> p(n + 1, vector<T>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            p[i + 1][j + 1] = p[i + 1][j] + p[i][j + 1] - p[i][j] + a[i][j];
        }
    }
    return p;
}

// sum on rectangle [r1,r2) x [c1,c2) using prefix p
template <typename T>
T range_sum_2d(const vector<vector<T>>& p, int r1, int c1, int r2, int c2) {
    return p[r2][c2] - p[r1][c2] - p[r2][c1] + p[r1][c1];
}
