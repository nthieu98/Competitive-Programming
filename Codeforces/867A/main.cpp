#include <bits/stdc++.h>

using namespace std;

int n;
string st;

int main()
{
  cin >> n;
  cin >> st;
  int cur = 0;
  for(int i = 0; i < st.size()-1; i++){
    if(st[i] == 'S' && st[i+1] == 'F') cur++;
    if(st[i] == 'F' && st[i+1] == 'S') cur--;
  }
  if(cur>0) cout <<"YES";
  else cout <<"NO";
  return 0;
}
