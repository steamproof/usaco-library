// Maintains window [l, r) and expands r; move l to restore validity.
template <class Add, class Remove, class Good>
void two_pointers(int n, Add add, Remove remove, Good good) {
    int r = 0;
    for (int l = 0; l < n; l++) {
        while (r < n && good()) {
            add(r);
            r++;
        }
        // use current window [l, r) here (may be invalid if good() checked before add)
        remove(l);
        if (r < l + 1) {
            r = l + 1;
        }
    }
}
