#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

long long n, m;
pair<long long, int> l[100005];
long long ans;
long long res[10], tmp[10];

int main()
{
  freopen("inp.txt", "r", stdin);
  freopen("ans.txt", "w", stdout);
  cin >> n >> m;
  long long x, y;
  for(int i = 1; i <= n; i++) {
    cin >> x;
    l[i] = make_pair(x, i);
  }
  sort(l + 1, l + n + 1);
  for(int i = 1; i <= n; i++){
    for(int u = i + 2; u < n; u++) {
      if(l[i].f != l[i + 1].f || l[u].f != l[u + 1].f) continue;
      long long r = l[i].f * l[u].f;
      if(r >= m) continue;
      if(ans < r){
        ans = r;
        res[1] = l[i].s;
        res[2] = l[i + 1].s;
        res[3] = l[u].s;
        res[4] = l[u + 1].s;
        sort(res + 1, res + 5);
      }
      else if(ans == r) {
        tmp[1] = l[i].s;
        tmp[2] = l[i + 1].s;
        tmp[3] = l[u].s;
        tmp[4] = l[u + 1].s ;
        sort(tmp + 1, tmp + 5);
        int flag = 0;
        for(int i = 1; i <= 4; i++){
          if(res[i] < tmp[i]) break;
          if(res[i] > tmp[i]){
            flag = 1;
            break;
          }
        }
        if(flag){
          res[1] = tmp[1];
          res[2] = tmp[2];
          res[3] = tmp[3];
          res[4] = tmp[4];
        }
      }
    }
  }
  if(ans == 0) cout << -1;
  else for(int i = 1; i <= 4; i++) cout << res[i] << " ";
  return 0;
}
