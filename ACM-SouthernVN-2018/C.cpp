#include <bits/stdc++.h>

using namespace std;

#define MAX 10000
#define INF int(1e9+7)
#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;

int main(){
  // freopen("C.inp", "r", stdin);
  ll x0, y0, r, x1, y1, x2, y2;
  cin >> x0 >> y0 >> r >> x1 >> y1 >> x2 >> y2;
  ll m = y2-y1, n = x2-x1;
  ll u = __gcd(m, n);
  m /= u; n /= u;
  ll d = 2*r;
  ll t = (ll)sqrt(d*d / (m*m + n*n));
  // cout << m << n << t << endl;
  cout << t+1 << endl;
  return 0;
}