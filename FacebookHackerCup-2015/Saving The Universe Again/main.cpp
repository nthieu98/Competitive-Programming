#include <bits/stdc++.h>

using namespace std;

int cal(string s){
  int k = 0;
  int p = 1;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'C') p *= 2;
    else k += p;
  }
  return k;
}

void go(int x, string st)
{
  int c = 0;
  for(int i = 0; i < st.size(); i++)
    if(st[i] == 'S') c++;
  if(c > x) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  int res = 0;
  int cur1 = 0;
  int cur2 = st.size() - 1;
  c = 0;

  while(cur1 < cur2){
    if(st[cur1] == 'C' && st[cur2] == 'S'){
      swap(st[cur1], st[cur2]);
      c++;
      int k = cal(st);
      if(k <= x){
        res = c;
        break;
      }
    }
    if(st[cur1] != 'C') cur1++;
    if(st[cur2] != 'S') cur2--;
  }
  cout << res << "\n";
}

int main()
{
  int T, x;
  string st;
  cin >> T;
  for(int i = 1; i <= T; i++){
    cout << "Case #" << i << ": ";
    cin >> x >> st;
    go(x, st);
  }
  return 0;
}
