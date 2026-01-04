// Returns length of cycle reachable from 'start' in a functional graph (next_node),
// or 0 if no cycle reachable (i.e., hits -1).
int floyd_cycle_len(const vector<int>& next_node, int start) {
    int n = (int) next_node.size();
    auto step = [&](int v) -> int {
        if (v == -1) return -1;
        return next_node[v];
    };

    int tort = step(start);
    int hare = step(step(start));
    while (tort != -1 && hare != -1 && tort != hare) {
        tort = step(tort);
        hare = step(step(hare));
    }
    if (tort == -1 || hare == -1) return 0;

    int len = 1;
    hare = step(tort);
    while (hare != tort) {
        hare = step(hare);
        len++;
    }
    return len;
}
