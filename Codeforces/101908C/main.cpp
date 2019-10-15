#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 200005;

struct BIT {
  int tree[N];

  void init(){
    memset(tree, 0, sizeof(tree));
  }

  void inc(int x, int p)
  {
      for(; x; x -= (x & (x ^ (x - 1)))) (tree[x] += p);
}

  int get(int x)
  {
      int p = 0;
      for(; x <= N; x += (x & (x ^ (x - 1)))) (p += tree[x]);
      return p;
  }
} T;

int h, v;
int a[N];
pair<int, int> H[N], V[N];

int main()
{
  ios_base::sync_with_stdio(0);
  int X, Y;
  cin >> X >> Y;
  cin >> h >> v;
  ll ans = 1ll * (h+1) * (v+1);
  int uu, vv;
  int t = 0;
  for(int i = 1; i <= h; i++){
    cin >> uu >> vv;
    H[i] = (make_pair(uu, vv));
    a[++t] = vv;
    a[++t] = uu;
  }
  sort(a+1, a+t+1);
  sort(H+1, H+h+1);
  T.init();
  for(int i = 1; i <= h; i++){
    int pos = lower_bound(a+1, a+t+1, H[i].second) - a;
    ans += T.get(pos);
    T.inc(pos, 1);
  }
  t = 0;
  for(int i = 1; i <= v; i++){
    cin >> uu >> vv;
    V[i] = (make_pair(uu, vv));
    a[++t] = vv;
    a[++t] = uu;
  }
  sort(a+1, a+t+1);
  sort(V+1, V+v+1);
  T.init();
  for(int i = 1; i <= v; i++){
    int pos = lower_bound(a+1, a+t+1, V[i].second) - a;
    ans += T.get(pos);
    T.inc(pos, 1);
  }
  cout << ans;
  return 0;
}
