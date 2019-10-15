#include <bits/stdc++.h>

using namespace std;



int main()
{
  string st;
  cin >> st;
  int x = st[0] - '0';
  int y = st[2] - '0';
  if(st[1] == '+') cout << x+y;
  else cout << x-y;
  return 0;
}
