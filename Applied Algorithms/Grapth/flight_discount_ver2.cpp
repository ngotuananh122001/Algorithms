// https://cses.fi/problemset/task/1195/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> edge;

const int N = 1e5 + 7;
const ll INF = 2e18;
int n, m; // đỉnh, cạnh
vector<edge> edges[N];
ll d[N][2];

void input() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        ll w;
        scanf("%d %d %lld", &u, &v, &w);
        edges[u].push_back({v, w});
    }
}

struct Node {
    int u;
    int coupon;
    ll dist_u;
};

struct cmp {
    bool operator() (Node a, Node b) {
        return a.dist_u > b.dist_u;
    }
};

int main()
{
    //freopen("flight_discount.txt", "r", stdin);
    input();

    for (int u = 1; u <= n; u++) {
        d[u][true] = INF;
        d[u][false] = INF;
    }

    priority_queue<Node, vector<Node>, cmp> pq;
    d[1][true] = 0;
    d[1][false] = 0;
    pq.push({1, false, 0});

    while (!pq.empty()) {
        Node x = pq.top();
        pq.pop();
        int u = x.u;
        int coupon = x.coupon;
        ll dist_u = x.dist_u;

        if (dist_u != d[u][coupon])
            continue;

        for (auto [v, w] : edges[u]) {
            // Nếu hành trình từ 1->u, chưa sử dụng
            // mã giảm giá
            if (!coupon) {
                // Nếu có thể, cập nhật đường đi từ s tới v
                // Thông qua s->u, và cạnh u->v + dùng mã
                // giảm giá trên cạnh này
                if (d[v][true] > dist_u + w / 2) {
                    d[v][true] = dist_u + w / 2;
                    pq.push({v, true, d[v][true]});
                }

                // Cập nhật đường đi s tới v thông
                // qua u, không sử dụng
                // mã giảm giá
                if (d[v][false] > dist_u + w) {
                    d[v][false] = dist_u + w;
                    pq.push({v, false, d[v][false]});
                }
            } else {
                if (d[v][true] > dist_u + w) {
                    d[v][true] = dist_u + w;
                    pq.push({v, true, d[v][true]});
                }
            }
        }
    }

    cout << d[n][true] << endl;
	return 0;
}
