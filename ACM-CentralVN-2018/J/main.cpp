#include <bits/stdc++.h>
#define ll long long

using namespace std;

int const N = 100005;

ll pos[N], neg[N];

int main()
{
  ll n, k;
  ll x;
  cin >> n >> k;
  ll nn, np;
  nn = np = 0;
  for(int i = 1; i <= n; i++){
    cin >> x;
    if(x < 0) neg[++nn] = -x;
    else pos[++np] = x;
  }
  pos[0] = 0;
  neg[0] = 0;
  sort(neg+1, neg+nn+1);
  sort(pos+1, pos+np+1);
  ll ans = 1e12;
  for(ll i = 1; i <= min(k, nn); i++){
    if(k-i <= np) ans = min(2ll*neg[i] + pos[k-i], ans);
  }
  for(ll i = 1; i <= min(k, np); i++){
    if(k-i <= nn) ans = min(2ll*pos[i] + neg[k-i], ans);
  }
  if(k <= np) ans = min(ans, pos[k]);
  if(k <= nn) ans = min(ans, neg[k]);
  cout << ans;
  return 0;
}
