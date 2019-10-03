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
  if(cal(st) <= x){
    cout << 0 << "\n";
    return;
  }
  while(cal(st) > x){
    for(int i = st.size()-1; i > 0; i--)
      if(st[i] == 'S' && st[i-1] == 'C') {
        swap(st[i], st[i-1]);
        res++;
        break;
      }
  }
  cout << res << "\n";
}

int main()
{
  freopen("inp.txt", "r", stdin);
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
