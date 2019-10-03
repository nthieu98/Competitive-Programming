#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
const long long mod = 1e9+7;

int n, m;
int a[N], b[N], c[N];
long long dp[N][N];

int main()
{
  cin >> n;
  int sum = 0;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a+1, a+n+1);
  a[n+1] = a[n] + 1;
  /**int cur = 0;
  m = 0;
  for(int i = 1; i <= n; i++){
    if(a[i] != a[i+1]){
      b[++m] = a[i];
      c[m] = i-cur;
      cur = i;
    }
  }**/
  if(a[1] == 1){
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++) dp[i][0] = 1;
  }
  else{
    cout << 0;
    exit(0);
  }
  for(int i = 2; i <= n; i++){
    for(int j = 1; j <= 3001; j++){
      dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
      if(a[i] == 1) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
      else if(a[i] > 1 && (j-a[i]) <= a[i]+1 && (j-a[i]) >= a[i]-1) dp[i][j] = (dp[i][j] + dp[i-1][j-a[i]]) % mod;
    }
  }
  long long ans = 0;
  for(int i = 1; i <= sum; i++) ans = (ans + dp[n][i]) % mod;
  cout << ans;
  return 0;
}
