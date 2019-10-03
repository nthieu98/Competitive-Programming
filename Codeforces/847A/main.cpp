#include <bits/stdc++.h>

using namespace std;

int n;
int l[110], r[110];
vector<pair<int, int> > P;

int main()
{
  cin >> n;
  int cnt = 0;
  for(int i = 1; i <= n; i++)cin >> l[i] >> r[i];
  for(int i = 1; i <= n; i++)
    if(!l[i] && !r[i]) P.push_back(make_pair(i,i));
    else if(!l[i]){
      int root = i;
      int tr = root;
      while(r[tr]) tr = r[tr];
        P.push_back(make_pair(root, tr));
    }
  for(int i = 0; i < P.size(); i++){
    if(i<P.size()-1)r[P[i].second] = P[i+1].first;
    if(i>0)l[P[i].first] = P[i-1].second;
  }
  for(int i = 1; i <= n; i++) cout << l[i] << " " << r[i] << endl;
  return 0;
}
