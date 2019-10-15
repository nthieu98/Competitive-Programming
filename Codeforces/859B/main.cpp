#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
  long long n;
  cin >> n;
  long long k;
  for(long long i = 1; i <= n; i++)
    if(i*i > n) {
      k = i-1;
      break;
    }
    else if(i*i == n) {
      cout << i*4;
      exit(0);
    }
  long long ans = k*4;
  if(k*k+k<n){
    ans += 4;
  }
  else ans += 2;
  cout << ans;
  return 0;
}
