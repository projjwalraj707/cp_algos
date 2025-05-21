class BinLift {
    vector<vector<int>> hier;
    vector<int> dist;
public:
    BinLift(vector<int>& par, vector<int>& dist, vector<int>& cumWeight) {
        int n = par.size();
        this->dist = dist;
        this->cumWeight = cumWeight;
        hier.resize(n, vector<int>(18));
        for (int i=0; i<n; i++) hier[i][0] = par[i];
        for (int j=1; j<18; j++) for (int i=0; i<n; i++) hier[i][j] = hier[hier[i][j-1]][j-1];
    }
    int findKthPar(int node, int k) {
        if (k == 0) return node;
        for (int i=0; (1<<i) <= k; i++) if (k & (1<<i)) node = hier[node][i];
        return node;
    }
    int findLCA(int node1, int node2) {
        if (dist[node1] > dist[node2]) swap(node1, node2);
        node2 = findKthPar(node2, dist[node2]-dist[node1]);
        if (node1 == node2) return node1;
        for (int i=17; i>=0; i--) {
            if (hier[node1][i] == hier[node2][i]) continue;
            node1 = hier[node1][i];
            node2 = hier[node2][i];
        }
        return hier[node1][0];
    }
    int findDist(int node1, int node2) {
        int lca = findLCA(node1, node2);
        return (dist[node1]+dist[node2]-2*dist[lca]);
    }
    bool isPar(int par, int node) {
        int currDist = dist[node] - dist[par];
        if (currDist < 0) return 0;
        return findKthPar(node, currDist) == par;
    }
    int findCumWeight(int node1, int node2) {
        int lca = findLCA(node1, node2);
        return cumWeight[node1]+cumWeight[node2] - 2*cumWeight[lca];
    }
};
