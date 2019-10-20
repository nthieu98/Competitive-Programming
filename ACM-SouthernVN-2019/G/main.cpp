#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;
long long S;
pair<long long, int> l[N];
int ans[10], tmp[10];

int main()
{
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  cin >> n >> S;
  long long x, y;
  for(int i = 1; i <= n; i++) {
    cin >> x;
    l[i] = make_pair(x, i);
  }
  sort(l + 1, l + n + 1);
  long long res = 0;
  int x1, x2, x3, x4;
  for(int i = 1; i <= n-3; i++) {
    long long k = S / l[i].first;
    if(l[i].first == l[i - 1].first) continue;
    if(l[i].first > k) continue;
    int pos = lower_bound(l + 1, l + n + 1, make_pair(k, 0)) - l;
    if(pos >= n){
      pos = lower_bound(l + 1, l + n + 1, make_pair(l[n - 1].first, 0)) - l;
      k = l[pos].first;
    }
    if(pos == i || pos == i + 1){
      pos = i + 2;
    }
    if(res < l[i].first * k){
      res = l[i].first * k;
      ans[1] = l[i].second;
      ans[2] = l[i + 1].second;
      ans[3] = l[pos].second;
      ans[4] = l[pos + 1].second;
      sort(ans + 1, ans + 5);
    }
    else if(res == l[i].first * k) {
      tmp[1] = l[i].second;
      tmp[2] = l[i + 1].second;
      tmp[3] = l[pos].second;
      tmp[4] = l[pos + 1].second;
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

  for(int i = 1; i <= 4; i++)
    cout << ans[i] << " ";
  return 0;
}
