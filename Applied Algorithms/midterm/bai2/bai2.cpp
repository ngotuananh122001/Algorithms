#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4;

int a[MAXN][MAXN];
int ans = 0;
int n, m;

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

int main() {
	// freopen("3-input.txt", "r", stdin);
    input();
    for (int j = 1; j <= m; j++) {
    	bool flag = true;
    	for (int i = 1; i <= n; i++) {
    		if (a[i][j] == 0) {
    			flag = false;
    			break;
			}
		}
		
		if (flag) 
			ans++;
		
	}
	
	cout << ans;
}

