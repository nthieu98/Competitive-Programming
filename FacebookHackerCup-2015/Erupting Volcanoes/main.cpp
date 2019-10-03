#include <bits/stdc++.h>

using namespace std;

int n, m;
int x[500], y[500], w[500];

int main()
{
  cin >> n;
  cin >> m;
  int ans = 0;
  for(int i = 1; i <= m ; i++)cin >> x[i] >> y[i] >> w[i];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
      int s = 0;
      for(int k = 1; k <= m; k++) s += max(0, w[k] - max(abs(x[k]-i),abs(y[k]-j)));
      ans = max(ans, s);
    }
  cout << ans;
  return 0;
}
