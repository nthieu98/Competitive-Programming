#include <bits/stdc++.h>

using namespace std;

int n;
pair<int,int> a[3005];

int main()
{
  cin >> n;
  int x;
  for(int i = 1; i <= n; i++) {
    cin >> x;
    a[i] = make_pair(x, i);
  }
  sort(a+1, a+n+1);
  int y, z;
  x = 1;
  y = z = -1;
  for(int i = 1; i <= n; i++){
    if(a[i].first > a[x].first){
      y = i;
      for(int j = i + 1; j <= n; j++){
        if(a[j].first > a[y].first){
          z = j;
          break;
        }
      }
      break;
    }
  }
  if(y == -1 || z == -1) cout << "-1 -1 -1";
  else cout << a[x].second << " " << a[y].second << " " << a[z].second;
  return 0;
}
