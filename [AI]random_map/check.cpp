#include <bits/stdc++.h>

using namespace std;

int main()
{
  freopen("map.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int n, m, sx, sy, fx, fy;
  int x;
  cin >> n >> m >> sx >> sy >> fx >> fy;
  if(sx > n || sx < 0 ||
     sy > m || sy < 0 ||
     fx > n || fy < 0 ||
     fy > m || fy < 0){
      cout << 1;
      return 0;
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> x;
      if(x < 0) {
        cout << 1;
        exit(0);
      }
    }
  }
  cout << 0;
}
