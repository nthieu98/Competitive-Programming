#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, k, m;
int a[N], b[N], c[N];

int main()
{
  cin >> n >> k >> m;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    b[i] = a[i] % m;
    c[b[i]]++;
  }
  int cur = -1;
  for(int i = 0; i < m; i++)
    if(c[i] >= k){
      cur = i;
      break;
    }
  if(cur == -1) cout << "No";
  else {
    cout << "Yes\n";
    for(int i = 1, j = 1; i <= n, j <= k; i++)
      if(b[i] == cur) {
        cout << a[i] << " ";
        j++;
      }
  }
  return 0;
}
