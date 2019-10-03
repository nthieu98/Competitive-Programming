#include <bits/stdc++.h>

using namespace std;

int n;
string a[1020];

int main()
{
  cin >> n;
  int ans = 0;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 0; i < 7; i++){
    int cnt = 0;
    for(int j = 1; j <= n; j++) cnt += (a[j][i] == '1');
    ans = max(ans, cnt);
  }
  cout << ans;
    return 0;
}
