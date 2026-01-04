struct Rect {
    long long x1, y1, x2, y2; // assume x1<=x2, y1<=y2
};

inline long long area(const Rect& r) {
    return max(0LL, r.x2 - r.x1) * max(0LL, r.y2 - r.y1);
}

inline bool intersects(const Rect& a, const Rect& b) {
    return max(a.x1, b.x1) < min(a.x2, b.x2) && max(a.y1, b.y1) < min(a.y2, b.y2);
}

inline Rect intersection_rect(const Rect& a, const Rect& b) {
    Rect r{max(a.x1, b.x1), max(a.y1, b.y1), min(a.x2, b.x2), min(a.y2, b.y2)};
    if (r.x1 > r.x2) r.x1 = r.x2;
    if (r.y1 > r.y2) r.y1 = r.y2;
    return r;
}

inline long long intersection_area(const Rect& a, const Rect& b) {
    return area(intersection_rect(a, b));
}
