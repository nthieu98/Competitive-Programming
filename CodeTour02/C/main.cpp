#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m;
long long d[N];
pair<long long, long long> L[N];

int main()
{
  cin >> n >> m;
  for(int i = 1; i < n; i++){
    cin >> d[i];
  }
  long long x, y;
  for(int i = 1; i <= m; i++){
    cin >> x >> y;
    L[i] = make_pair(y + y, x);
  }
  sort(L + 1, L + m + 1);
  L[++m] = make_pair(L[m-1].first + 1, 0);
  long long ans = -1;
  for(int i = 1; i < n; i++) {
    int pos = lower_bound(L + 1, L + m + 1, make_pair(d[i], 0ll)) - L;
    if(pos < m && L[pos].first >= d[i]){
      ans = max(ans, 2ll * L[pos].second);
    }
    else{
      cout << "impossible";
      exit(0);
    }
  }
  cout << 1ll * ans * (n - 1);
  return 0;
}
