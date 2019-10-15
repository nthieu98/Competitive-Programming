#include <bits/stdc++.h>

using namespace std;

const int N = 30;

vector <int> cha[N], chb[N];
int mk[10004];

int main()
{
  string a, b;
  cin >> a >> b;
  for(int i = 0; i < a.size(); i++){
    cha[a[i]-'A'].push_back(i);
  }
  for(int i = 0; i < b.size(); i++){
    chb[b[i]-'A'].push_back(i);
  }
  for(int i = 0; i < 26; i++){
    for(int j = 0; j < cha[i].size(); j++){
      for(int k = 0; k < chb[i].size(); k++){
        int be = cha[i][j] - chb[i][k];
        int fi = cha[i][j] + (b.size() - chb[i][k]) - 1;
        if(be >= 0 && fi < a.size()) mk[be] = 1;
      }
    }
  }
  int ans = 0;
  for(int i = 0; i <= a.size() - b.size(); i++)
    if(!mk[i]) ans++;
  cout << ans;
  return 0;
}
