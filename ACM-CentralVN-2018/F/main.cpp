#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1000005;

ll n, L;
ll a[N*2];

int main()
{
  cin >> n >> L;
  int t = 0;
  ll x;
  for(int i = 1; i <= n; i++){
    cin >> x;
    a[++t] = x;
    a[++t] = L-x;
  }
  sort(a+1, a+t+1);
  double ans = 0.0;
  int flag = 0;
  for(int i = t, j = n-1; j >= max(0ll, n-1000) ; i--, j--){
    double k = 1.0*a[i];
    for(int c = 1; c <= n-j; c++) k /= 2.0;
    ans += k;
    if(j == 0 && flag < 1) {
      flag++;
      j++;
    }
  }
  printf("%0.6f", ans);
  return 0;
}
