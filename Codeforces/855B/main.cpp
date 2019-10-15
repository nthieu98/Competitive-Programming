#include <bits/stdc++.h>

using namespace std;

int n;
long long a[100005], b[5], mul[5][100005], dp[5][100005];

int main()
{
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  cin >> n;
  for(int i = 1; i <= 3; i++) cin >> b[i];
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= 3; i++)
    for(int j = 1; j <= n; j++) mul[i][j] = b[i]*a[j];
  for(int i = 1; i <= 3; i++)
    for(int j = 1; j <= n; j++) dp[i][j] = -1000000000000000000;
  dp[1][1] = b[1]*a[1];
  dp[2][1] = dp[1][1] + mul[2][1];
  dp[3][1] = dp[2][1] + mul[3][1];
  for(int i = 2; i <= n; i++)
    for(int j = 1; j <= 3; j++) dp[j][i] = max(dp[j][i-1], dp[j-1][i] + b[j]*a[i]);
  cout << dp[3][n];
  return 0;
}
