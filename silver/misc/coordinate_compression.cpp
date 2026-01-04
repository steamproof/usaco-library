template <typename T>
vector<int> compress(const vector<T>& a, vector<T>& vals_out) {
    vals_out = a;
    sort(vals_out.begin(), vals_out.end());
    vals_out.erase(unique(vals_out.begin(), vals_out.end()), vals_out.end());
    vector<int> id(a.size());
    for (int i = 0; i < (int) a.size(); i++) {
        id[i] = (int) (lower_bound(vals_out.begin(), vals_out.end(), a[i]) - vals_out.begin());
    }
    return id;
}
