#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n, m, l;
int a[N], c[N];
vector<int> b[N];

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> l;
  for(int i = 1; i <= l; i++){
    int x;
    cin >> x;
    a[x] = 1;
  }
  for(int i = 1; i <= n; i++){
    int num, x;
    cin >> num;
    c[i] = num;
    for(int j = 1; j <= num; j++){
      cin >> x;
      b[i].push_back(x);
    }
  }
  int ans = 0;
  int cur = m-l;

  for(int i = 1; i <= n; i++){
    for(int j = 0; j < b[i].size(); j++){
      if(a[b[i][j]] == 0){
        a[b[i][j]]= 1;
        cur--;
      }
      else{
        cur++;
        a[b[i][j]] = 0;
      }
    }
    if(cur == m){
      cout << i;
      exit(0);
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < b[i].size(); j++){
      if(a[b[i][j]] == 0){
        a[b[i][j]]= 1;
        cur--;
      }
      else{
        cur++;
        a[b[i][j]] = 0;
      }
    }
    if(cur == m){
      ans = n+i;
      break;
    }
  }
  if(!ans) cout <<-1;
  else cout << ans;
  return 0;
}
