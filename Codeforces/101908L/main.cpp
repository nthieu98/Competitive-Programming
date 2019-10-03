#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, q;
vector<int> a[N];
int p[20][N], mk[N], l[N];

void DFS(int x, int dp)
{
  mk[x] = 1;
  l[x] = dp;
  for(int i = 0; i < a[x].size(); i++){
    int v = a[x][i];
    if(!mk[v]) DFS(v, dp+1);
    p[0][v] = x;
  }
}

int LCA(int x, int y)
{
    if(l[x] < l[y]) swap(x, y);
    int abc = log2(l[x]);
    for(int i = abc; i >= 0; i--)
      if(l[x] - (1 << i) >= l[y]) x = p[i][x];
    if(x == y) return x;
    for(int i = abc; i >= 0; i--)
        if(p[i][x] != p[i][y])
        {
            x = p[i][x];
            y = p[i][y];
        }
    return p[0][x];
}

int cal(int u, int v, int r)
{
  int puv = LCA(u, v);
  int pur = LCA(u, r);
  int pvr = LCA(v, r);
  if(puv == pur){
    return l[u] - l[puv] + 1 + l[pvr] - l[puv];
  }
  if(puv == pvr){
    return l[u] - l[pur] + 1;
  }
  return l[u] - l[puv] + 1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> n >> q;
  int u, v, r, t;
  for(int i = 1; i < n; i++){
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  l[0] = 0;
  DFS(1, 1);
  for(int i = 1; i <= log2(n); i++){
    for(int j = 1; j <= n; j++){
      p[i][j] = p[i-1][p[i-1][j]];
    }
  }
  for(int i = 1; i <= q; i++){
    cin >> u >> v >> r >> t;
    int puv = LCA(u, v);
    int prt = LCA(r, t);
    int pur = LCA(u, r);
    int put = LCA(u, t);
    int pvr = LCA(v, r);
    int pvt = LCA(v, t);
    if((puv == pur && puv == pvr && ((pvt == put && pvt != puv) || (puv == put && puv == pvt))) ||
       (puv == put && puv == pvt && ((pvr == pur && pvr != puv) || (puv == pur && puv == pvr))) ||
       (prt == pur && prt == put && ((pvt == pvr && pvt != prt) || (prt == pvr && prt == pvt))) ||
       (prt == pvr && prt == pvt && ((put == pur && put != prt) || (prt == pvr && prt == pvt)))){
        cout << 1 << endl;
        continue;
       }
    int ans = abs(cal(u, v, r) - cal(u, v, t));
    cout << ans + (ans?1:0) << endl;
  }
  return 0;
}
