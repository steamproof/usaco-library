template <typename T, int B = 60>
class xor_basis {
public:
    array<T, B> b{};
    int n;

    xor_basis() : n(0) {}

    inline T reduce_min(T x) const {
        for (int i = 0; i < n; i++) {
            x = min(x, x ^ b[i]);
        }
        return x;
    }

    inline T reduce_max(T x = 0) const {
        for (int i = 0; i < n; i++) {
            x = max(x, x ^ b[i]);
        }
        return x;
    }

    inline bool add(T x) {
        x = reduce_min(x);
        if (x == 0) {
            return false;
        }
        b[n++] = x;
        int k = n - 1;
        while (k > 0 && b[k] > b[k - 1]) {
            swap(b[k], b[k - 1]);
            k--;
        }
        for (int i = k - 1; i >= 0; i--) {
            b[i] = min(b[i], b[i] ^ x);
        }
        return true;
    }

    inline void merge(const xor_basis& other) {
        for (int i = 0; i < other.n && n < B; i++) {
            add(other.b[i]);
        }
    }
};
