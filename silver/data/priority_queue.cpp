// max-heap (default):
// priority_queue<int> pq;

// min-heap:
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
