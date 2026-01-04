// 'good(r,c)' decides whether a cell is fillable.
// 'visit(r,c)' is called when a cell is taken.
template <class Good, class Visit>
void flood_fill(int sr, int sc, int R, int C, Good good, Visit visit) {
    static int dr[4] = {1, -1, 0, 0};
    static int dc[4] = {0, 0, 1, -1};
    queue<pair<int,int>> q;
    q.push({sr, sc});
    visit(sr, sc);
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (0 <= nr && nr < R && 0 <= nc && nc < C && good(nr, nc)) {
                visit(nr, nc);
                q.push({nr, nc});
            }
        }
    }
}
