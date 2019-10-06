#include <bits/stdc++.h>

using namespace std;

int main()
{
  int x1, y1, x2, y2;
  int T;
  cin >> T;
  for(int _ = 1; _ <= T; _++) {
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2 && y1 == y2) {
      cout << "YES\n";
      continue;
    }
    if((!x1 && !y1) || (!x2 && !y2)) {
      cout << "NO\n";
      continue;
    }
    if(!x1) x1 += y1;
    if(!y1) y1 += x1;
    if(!x2) x2 += y2;
    if(!y2) y2 += x2;
    int d1 = __gcd(abs(x1), abs(y1));
    int d2 = __gcd(abs(x2), abs(y2));
    if(d2 == d1){
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}
