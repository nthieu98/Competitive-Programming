#include <bits/stdc++.h>

using namespace std;

int xx[] = {0, 1, -1, 0};
int yy[] = {-1, 0 , 0, 1};

int n, x, y, d;
int a[100][100];
string dir;

int go(int X, int Y)
{
  int p = -1;
  for(int i = 0; i <= 3; i++)
    if(!a[X+xx[i]][Y+yy[i]]){
      if(i==d) {p = i; break;}
      if(i+d == 3 && p == -1) p = i;
      if(i+d != 3) p = i;
    }
  return p;
}

int main()
{
  cin >> n >> dir >> x >> y;
  x++;
  y++;
  if(dir == "s") d = 1;
  if(dir == "n") d = 2;
  if(dir == "e") d = 3;
  if(dir == "w") d = 0;
  for(int i = 0; i <= n+1; i++) a[0][i] = a[n+1][i] = a[i][0] = a[i][n+1] = -1;
  a[x][y] = 1;
  int t = 2;
  while(1){
    int k = go(x, y);
    if(k == -1) break;
    x += xx[k];
    y += yy[k];
    a[x][y] = t++;
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++) cout << a[i][j] << " ";
    cout << endl;
  }
  return 0;
}
