#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

int n;
int a[N], mark[N];

int main()
{
  cin >> n;
  for(int i = 1;i <= n; i++) cin >> a[i];
  cout << 1 << " ";
  int cur = n+1;
  for(int i = 1; i < n; i++){
    mark[a[i]] = 1;
    while(mark[cur-1]) cur--;
    cout << i+1 - (n+1-cur) << " ";
  }
  cout << 1;

  return 0;
}
