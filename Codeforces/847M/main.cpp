#include <bits/stdc++.h>

using namespace std;

int n;
int a[200];

int main()
{
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  int k = a[2] - a[1];
  int f = 1;
  for(int i = 3; i <= n; i++)
    if(a[i] - a[i-1] != k){
      f = 0;
      break;
    }
  if(!f) cout << a[n];
  else cout << k+a[n];
  return 0;
}
