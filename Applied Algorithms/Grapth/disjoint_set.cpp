#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int p[N];
int r[N];

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



int main()
{
	return 0;
}
