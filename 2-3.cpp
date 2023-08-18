//3.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 1000000000 + 7;
int w0[100005];
int w1[100005];
int w2[100005];
int n, m, k, f[100005], d[100005], id[100005];
vector <int> e[100005];
void dfs(int u, int fa){
    d[u] = d[fa] + 1;
    f[u] = fa;

    for(auto &v : e[u]) if(v != fa){
        dfs(v, u);
    }
}

bool cmp(int a, int b){
    return d[a] < d[b];
}

int main(){
    cin >> n >> m >> k;
    for(int i = 2; i <= n; i++){
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);              //①
    for(int i = 1; i <= m; i++){
        int x, w;
        cin >> x >> w;
        w1[x] = (w1[x] + w) % mod;
        w2[x] = (w2[x] + w) % mod;
    }
    for(int i = 1; i <= n; i++){
        id[i] = i;
    }
    sort(id + 1, id + 1 + n, cmp);
    for(int i = 1; i <= k; i++){
        for(int j = n; j >= 1; j--){
            int x = id[j];
            for(auto &y : e[x]) if(y != f[x]){
                w1[y] = (w1[y] + w1[x]) % mod;
            }
            w1[x] = 0;
        }
    }
    for(int x = 1; x <= n; x++)
        w1[x] = (w1[x] - w0[x] + mod) % mod, w0[x] = 0;
    for(int j = 1; j <= n; j++){    //②
        int x = id[j];
        if(f[x]){
            w1[f[x]] = (w1[f[x]] + w2[x]) % mod;
            w2[f[x]] = (w2[f[x]] + w2[x]) % mod;
            w0[x] = (w0[x] + w2[x]) % mod;
            w2[x] = 0;
        }
    }
    for(int i = 1; i <= n; i++)
        cout << w1[i] << " ";
    return 0;
}
/*
32.
输入
5 2 1
1 2
2 3
3 4
3 5
1 5
3 2
输出
0 7 0 2 2
*/
/*
33.
输入
9 9 2
1 2
1 7
2 3
2 4
7 8
4 5
4 6
8 9
1 1
2 10
3 100
4 1000
5 10000
6 100000
7 1000000
8 10000000
9 100000000
输出
1000010 1100 1 110001 10 10 10000000 100000001 1000000
*/