#include <bits/stdc++.h>

using namespace std;

int main()
{
  long long a, b, c;
  cin >> a >> b >> c;
  c *= 5;
  long long res = a;
  for(int i = 0; i <= (a+1)/c; i++){
    long long k = (a - c*i) / b;
    long long tmp = a - c*i - b*k;
    if(tmp>0)res = min(res, tmp);
  }
  cout << res;
  return 0;
}
