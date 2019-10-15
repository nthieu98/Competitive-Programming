#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, x;
  cin >> n;
  int ans = 0;
  for(int i = 1; i <= n; i++){
    cin >> x;
    if(x!=1) ans++;
  }
  cout << ans;
    return 0;
}
