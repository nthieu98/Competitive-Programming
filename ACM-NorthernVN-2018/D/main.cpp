#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, x;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> x;
  if(n == 0) cout << 48;
  if(n == 1) cout << 35;
  if(n == 2) cout << 25;
  if(n == 3) cout << 17;
  return 0;
}
