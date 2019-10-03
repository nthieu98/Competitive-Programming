#include <bits/stdc++.h>

using namespace std;

int n, x;
int a[110];

int main()
{
  cin >> n >> x;
  for(int i = 1; i <= n; i++) cin >> a[i];
  sort(a+1, a+n+1);
  int ans = 0;
  int t = 1;
  while(a[t] < x && t <= n) t++;
  if(t == n+1) {
    ans += x-n+1;
    if(a[])
  }
  else {
    ans += x-t+1;
    if(a[t+1] == x) ans++;
  }
  cout << ans;
  return 0;
}
