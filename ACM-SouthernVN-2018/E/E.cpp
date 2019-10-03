#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 5005;

int n, s, f;
long long ans = 0;
vector <int> a[N];

int main()
{
  cin >> n;
  int u, v;
  for(int i = 1; i < n; i++){
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  for(int i = 1; i <= n; i++){
    if(a[i].size() < 3) continue;
    memset(mk, 0, sizeof(mk));
    memset(d, 0, sizeof(d));
    BFS(i);
  }
  cout << ans;
  return 0;
}
