#include <bits/stdc++.h>

using namespace std;

const int N = 410;

int n;
string str[410];

void change(string st, int x)
{
  string nst = "";
  for(int i = 0; i < st.size(); i++)
    if(st[i] == 'u') nst += "oo";
    else if(st[i] == 'k'){
      int j = i+1;
      while(st[j] == 'k' && j < st.size())j++;
      if(st[j] == 'h') {
        nst += "h";
        i = j;
      }
      else nst += "k";
    }
    else nst += st[i];
  str[x] = nst;
}

int main()
{
  cin >> n;
  for(int i = 1;i <= n; i++) {
    cin >> str[i];
    change(str[i], i);
  }
  int ans = 0;
  int k;
  for(int i = 1;i <= n; i++){
    k = 1;
    for(int j = i-1; j>=1; j--)
      if(str[j] == str[i]) k = 0;
    ans += k;
  }
  cout << ans;
  return 0;
}
