#include <bits/stdc++.h>
using namespace std;

#define N 100

int x[N];
bool visited[N]; // mang danh dau
int load; // number of passengers on the bus
int f; // accumulated distance (quang duong tich luy)
int f_min; // min distance (cua lan truoc do)
int n, Q;
int c[N][N];

void input(){
  cin >> n >> Q;
  for(int i=0; i <= 2*n; i++)
    for(int j=0; j<= 2*n; j++)
    cin >> c[i][j];
}

bool check(int v, int k) {
    if (visited[v]) return false;
    if (v > n) {// diem xuong xe cua khach hang v - n
        if (!visited[v-n]) return false;
    } else { // v is a pickup point of passenger v
        if (visited[v+n]) return false; // the corresponsding drop-off point has been visited
        if (load+1>Q) return false;
    }

    return true;
}


void solution() {
    // accept a solution
    if (f+c(x[2*n]x[0]) < f_min) {
        f_min = f+c(x[2*n]x[0]);
        cout << "Update f_min = " << f_min << endl;
    }
}
void Try(k){
  for(int v=1; v <= 2*n; v++) {
    if (check(v, k)) {
        x[k] = v;

        // update data struct
        visited[v] = true;
        if (v > n) {
            load--;
        } else load++;

        f += c(x[k-1]x[k]);
        if (k == 2*n) solution();
        else {
            Try(k+1);
        }

        // recover datastructure
        visited[v] = false;
        if (v > n) load++;
        else load--;

        f -= c[x[k-1]][x[k]];
    }
  }
}

int main()
{
    for (int v=1; v<=2*n;v++) visited[v]=false;
    load = 0;
    f=0;
    f_min=1e9;
    x[0] = 0;
    Try(1);

	return 0;
}
