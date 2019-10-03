#include <bits/stdc++.h>

using namespace std;

int main()
{
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int a = abs(x1-x2);
  if(!a) a+=2;
  else  a++;
  int b = abs(y1- y2);
  if(!b) b+= 2;
  else b++;
  cout << a*2+b*2;
  return 0;
}
