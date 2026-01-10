template <typename T>
T build_mask(const string& s, char target) {
    T mask = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == target) {
            mask |= (T(1) << i);
        }
    }
    return mask;
}
