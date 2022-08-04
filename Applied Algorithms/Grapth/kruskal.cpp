// https://codeforces.com/group/Ir5CI6f3FD/contest/279102/problem/M

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 7;

struct Edge {
    int u, v, w;

    Edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        w = _w;
    }
};

int n; // số đỉnh
int m; // số cạnh
vector<Edge> g;
int p[MAX]; // p[u] = root of u in set which contains it
int r[MAX]; // r[u] = height of tree begins at u

void Input() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g.push_back({u, v, w});
    }
}

void MakeSet(int x) {
    p[x] = x;
    r[x] = 0;
}

// Return root of set which contains x
// Cập nhật cha của tất cả nót trên đường đi này
// thành nốt gốc
int Find(int x) {
    if (x != p[x]) p[x] = Find(p[x]);
    return p[x];
}

void Unify(int x, int y) {
    if (r[x] > r[y]) p[y] = x;
    else {
        p[x] = y;
        if (r[x] == r[y]) r[y]++;
    }
}

long long rs = 0; // Tổng trọng số của cây khung nhỏ nhất

int main()
{
    Input();

    // Init, mỗi đỉnh là 1 tập con rời nhau
    for (int i = 1; i <= n; i++) MakeSet(i);

    // Sắp xếp các cạnh theo trọng số tăng dần
    sort(g.begin(), g.end(), [](Edge &x, Edge &y) {
        return x.w < y.w;
    });

    // Duyệt qua các cạnh theo thứ tự đã sắp xếp
    for (auto e : g) {
        int u = e.u, v = e.v, w = e.w;
        int ru = Find(u);
        int rv = Find(v);

        // Thêm cạnh u, v vào tập cây khung, nếu
        // không tạo ra chu trình
        // Nếu 2 đỉnh cùng thuộc 1 tập, nối chúng lại
        // sẽ tạo ra chu trình
        if (ru != rv) {
            Unify(ru, rv);
            rs += w;
        }
    }

    if (!rs) {
        cout << -1;
    } else {
        cout << rs;
    }
	return 0;
}
