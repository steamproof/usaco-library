int count_cycles_functional(const vector<int>& next_node) {
    int n = (int) next_node.size();
    vector<char> visited(n, 0), on_stack(n, 0);
    int cycles = 0;

    function<void(int)> dfs = [&](int v) {
        visited[v] = on_stack[v] = 1;
        int u = next_node[v];
        if (u != -1) {
            if (on_stack[u]) {
                cycles++;
            } else if (!visited[u]) {
                dfs(u);
            }
        }
        on_stack[v] = 0;
    };

    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i);
    }
    return cycles;
}
