// https://cses.fi/problemset/task/1195/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> Edge;

const int N = 1e5 + 7;
const ll INF = 2e18;
int n; // so dinh
int m; // so canh
vector<Edge> neighbors[N];
vector<Edge> reverseNeighbors[N];

struct Node {
    int u;
    ll dist_u;
};

struct cmp {
    bool operator() (Node a, Node b) {
        return a.dist_u > b.dist_u;
    }
};

vector<ll> dijkstra(int s, vector<Edge> edges[]) {
    vector<ll> d (n + 1, INF);
    priority_queue<Node, vector<Node>, cmp> pq;
    d[s] = 0;
    pq.push({s, d[s]});
    while (!pq.empty()) {
        Node x = pq.top();
        pq.pop();

        int u = x.u;

        // Điều này là bởi vì mỗi lần push d[v] mới vào queue
        // (đường đi được tối ưu hơn)
        // ta không thực sự xóa bỏ d[v] cũ vẫn nằm trong queue
        if (x.dist_u != d[u])
            continue;

        for (auto e : edges[u]) {
            int v = e.first;
            ll w = e.second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push({v, d[v]});
            }
        }
    }

    return d;
}

void input() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        ll w;
        scanf("%d %d %lld", &u, &v, &w);
        neighbors[u].push_back({v, w});
        reverseNeighbors[v].push_back({u, w});
    }
}

int main()
{
    freopen("flight_discount.txt", "r", stdin);
    input();

    vector<ll> startCost = dijkstra(1, neighbors);
    vector<ll> endCost = dijkstra(n, reverseNeighbors);

    ll priceBest = INF;
    for (int u = 1; u <= n; u++) {
        for (auto e : neighbors[u]) {
            int v = e.first;
            ll w = e.second;
            if (startCost[u] == INF || endCost[v] == INF) {
                continue;
            }
            priceBest = min(priceBest, startCost[u] + (w / 2) + endCost[v]);
        }
    }

    cout << priceBest;
	return 0;
}
