#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2005;

ll n, d;
ll sum;
ll h[N], l[N], mk[N], mk2[N];

int main()
{
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> h[i] >> l[i];
    sum += h[i];
  }
  cin >> d;
  int pos;
  ll maxs = 0;
  h[0] = 1e9;
  l[0] = 1e9;
  int ans = 0;
  while(1){
    pos = 0;
    maxs = 0;
    memset(mk, 0, sizeof(mk));

    for(int i = 1; i <= n; i++){
      if(sum + l[i] >= d && !mk2[i]){
        mk[i] = 1;
      }
    }
    for(int i = 1; i <= n; i++){
      if(mk[i]){
        if(h[pos] > h[i]){
          pos = i;
        }
        if(h[pos] == h[i] && l[pos] > l[i]){
          pos = i;
        }
      }
    }
    for(int i = 1; i <= n; i++)if(!mk2[i] && i != pos){
      maxs = max(maxs, sum+l[i]);
    }
    if(pos == 0) break;
    if(maxs - h[pos] < d){
      for(int i = 1; i <= n; i++){
        if(!mk2[i] && i != pos){
          if(sum - h[i] + l[pos] >= d && sum - h[pos] + l[i] < d) {
            mk2[i] = 1;
            ans++;
            break;
          }
        }
      }
    }
    ans++;
    mk2[pos] = 1;
    sum -= h[pos];
  }
  cout << ans;
  return 0;
}
