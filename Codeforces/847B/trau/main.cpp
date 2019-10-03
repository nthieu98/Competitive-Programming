#include <bits/stdc++.h>

using namespace std;

const int N = 200100;

int n;
int a[N];
vector<int> ans[N];

int main()
{
  freopen("inp.txt", "r", stdin);
  freopen("ans.txt", "w", stdout);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++){
    int k = 0;
    while(k<=n){
      if(ans[k].empty() || ans[k].back() < a[i]) break;
      k++;
    }
    ans[k].push_back(a[i]);
  }
  for(int i = 0; i < n; i++){
    if(ans[i].empty()) break;
    for(int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
    cout << endl;
  }
  return 0;
}
