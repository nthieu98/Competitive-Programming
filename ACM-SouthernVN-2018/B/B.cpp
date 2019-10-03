#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 100005;

int n, m, s, f;
long long ans = 0;
vector <pair<int, int> > a[N], b[N];
priority_queue<pair<int, int> > pq;
ll d[N];
int mk[N];

void Solve(int x)
{
  for(int i = 1; i <= n; i++) d[i] = 0;
  d[s] = 0;
  mk[s] = 1;
  pq.push(make_pair(0, s));
  while(!pq.empty()){
    ll dis = pq.top().first;
    int u = pq.top().second;
    mk[u] = 1;
    pq.pop();
    if(d[u] != dis) continue;
    for(int i = 0; i < b[u].size(); i++){
      int v = b[u][i].first;
      int c = b[u][i].second;
      if(d[v] < dis + 1ll*c && !mk[v]){
        d[v] = dis + 1ll * c;
        pq.push(make_pair(d[v], v));
      }
    }
  }
}

int main()
{
  //freopen("inp.txt", "r", stdin);
  cin >> n >> m >> s >> f;
  int u, v;
  for(int i = 1; i <= m; i++){
    cin >> u >> v;
    a[u].push_back(make_pair(v, 1));
    a[v].push_back(make_pair(u, 1));
  }
  a[s].push_back(make_pair(0, 1));
  a[f].push_back(make_pair(n+1, 1));
  for(int i = 1; i <= n; i++){
    if(a[i].size() > 2){
      for(int j = 0; j < a[i].size(); j++){
        u = i;
        v = a[i][j].first;
        int c = 1;
        int w;
        while(a[v].size() == 2){
          for(int k = 0; k < a[v].size(); k++){
            if(a[v][k].first != u){
              w = a[v][k].first;
            }
          }
          u = v;
          v = w;
          c++;
        }
        b[i].push_back(make_pair(v, c));
      }
    }
  }
  Solve(s);
  cout << d[f];
  return 0;
}
