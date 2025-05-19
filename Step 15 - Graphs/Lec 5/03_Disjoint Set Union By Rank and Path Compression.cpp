// Disjoint Union Set (Union Find) by Rank and Path Compression

vector<int> parent;
vector<int> rank;

int find (int i) {
    if (i == parent[i]) {
        return i;
    }
    return parent[i] = find(parent[i]);
}

void Union (int x, int y) {
    int x_parent = find(x);
    int y_parent = find(y);

    if (x_parent == y_parent) {
        return;
    }
    if(rank[x_parent] > rank[y_parent]) {
        parent[y_parent] = x_parent;
    } else if(rank[x_parent] < rank[y_parent]) {
        parent[x_parent] = y_parent;
    } else {
        parent[x_parent] = y_parent;
        rank[y_parent]++;
    }
}