#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m, p;
long long S;
long long val[N];
pair<long long, int> l[N], c[N];
int ans[10], tmp[10];

int main()
{
  //freopen("inp.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
  cin >> n >> S;
  long long x, y;
  for(int i = 1; i <= n; i++) {
    cin >> x;
    l[i] = make_pair(x, i);
  }
  sort(l + 1, l + n + 1);
  m = 0;
  int cur = 0;
  for(int i = 1; i <= n; i++){
    if(l[i].first != l[i+1].first){
      c[++m] = make_pair(l[i].first, i - cur);
      cur = i;
    }
  }
  p = 0;
  for(int i = 1; i <= m; i++){
    if(c[i].second >= 2){
      val[++p] = c[i].first;
    }
  }

  long long res = 0;
  for(int i = 1; i <= p; i++){
    long long k = (S-1) / val[i];
    int posval = lower_bound(val + 1, val + p + 1, k) - val;
    if(val[posval] != k){
      posval --;
    }
    if(val[posval] < val[i]) continue;
    int pos = lower_bound(l + 1, l + n + 1, make_pair(val[i], 0)) - l;
    int pos2 = lower_bound(l + pos + 2, l + n + 1, make_pair(val[posval], 0)) - l;
    if(val[posval] != l[pos2].first) continue;
    if(l[pos2].first != l[pos2 + 1].first) continue;
    if(val[i]* val[posval] >= S) continue;
    if(res < val[i]* val[posval]){
      res = val[i]* val[posval];
      ans[1] = l[pos].second;
      ans[2] = l[pos + 1].second;
      ans[3] = l[pos2].second;
      ans[4] = l[pos2 + 1].second;
      sort(ans + 1, ans + 5);
    }
    else if(res == val[i]* val[posval]) {
      tmp[1] = l[pos].second;
      tmp[2] = l[pos + 1].second;
      tmp[3] = l[pos2].second;
      tmp[4] = l[pos2 + 1].second;
      sort(tmp + 1, tmp + 5);
      int flag = 0;
      for(int i = 1; i <= 4; i++){
        if(ans[i] < tmp[i]) break;
        if(ans[i] > tmp[i]){
          flag = 1;
          break;
        }
      }
      if(flag){
        ans[1] = tmp[1];
        ans[2] = tmp[2];
        ans[3] = tmp[3];
        ans[4] = tmp[4];
      }
    }
  }
  if(res == 0) cout << -1;
  else{
    for(int i = 1; i <= 4; i++) cout << ans[i] << " ";
  }
  return 0;
}
