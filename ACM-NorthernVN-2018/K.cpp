#include <bits/stdc++.h>

using namespace std;

#define MAX 1010

typedef long long ll;

ll m, n, M;
ll a[MAX], b[MAX];

int main(){
  // freopen("K.inp", "r", stdin);
  cin >> m >> n >> M;
  for(int i = 1; i <= m; i++){
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++){
    cin >> b[i];
  }
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
      ll x = __gcd(a[i], b[j]);
      a[i] /= x;
      b[j] /= x;
    }
  }
  ll p = 1, q = 1;
  for(int i = 1; i <= m; i++) p = (p*a[i]) % M;
  for(int i = 1; i <= n; i++) q = (q*b[i]) % M;
  cout << p << " " << q << endl;
  return 0;
}