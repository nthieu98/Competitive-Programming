#include <bits/stdc++.h>

using namespace std;

const int N = 200100;

struct BIT
{
    int a[N];
    BIT(){};
    void update(int x, int p)
    {
        for(; x > 0; x -= x & (-x)) a[x] += p;
    }

    int get(int x)
    {
        int p = 0;
        for(; x < N; x += x & (-x)) p += a[x];
        return p;
    }
};


BIT t;
int n;
int a[N], b[N], c[N], mark[N];
vector<int> ans[N];


int main()
{
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  cin >> n;
  for(int i = 1; i <= n; i++) {cin >> a[i];b[i] = a[i];}
  sort(b+1,b+n+1);
  for(int i = 1; i <= n; i++){
    c[i] = lower_bound(b+1,b+n+1, a[i])-b;
  }
  for(int i = 1; i <= n; i++) {
    int k = t.get(c[i]);
    ans[k].push_back(b[c[i]]);
    t.update(c[i]-1, 1);
    if(ans[k].size() > 1){
      int pos = lower_bound(b+1,b+n+1,ans[k][ans[k].size()-2])-b;
      t.update(pos-1, -1);
    }
  }
  for(int i = 0; i < n; i++){
    if(ans[i].empty()) continue;
    for(int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
    cout << endl;
  }
  return 0;
}
