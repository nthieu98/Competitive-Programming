#include <bits/stdc++.h>

using namespace std;

int m;
int a[2][100005], n[2];

void go()
{
  cin >> m;
  n[0] = n[1] = 0;
  for(int i = 1; i <= m; i++) cin >> a[i&1][++n[i&1]];
  sort(a[0]+1, a[0]+n[0]+1);
  sort(a[1]+1, a[1]+n[1]+1);
  int flag = 0;
  for(int i = 1; i < m; i++){
    if((i&1 && a[1][i/2+1] > a[0][i/2+1]) || (!(i&1) && a[0][i/2] > a[1][i/2+1])){
      cout << i-1 << "\n";
      flag = 1;
      break;
    }
  }
  if(!flag) cout <<"OK\n";
}

int main()
{
  freopen("inp.txt", "r", stdin);
  int T;
  cin >> T;
  for(int i = 1; i <= T; i++){
    printf("Case #%d: ", i);
    go();
  }
  return 0;
}
