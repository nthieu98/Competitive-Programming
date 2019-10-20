#include <bits/stdc++.h>

using namespace std;

long long R, G, B, n;

int main()
{
  cin >> R >> G >> B >> n;
  long long cur = 1;
  string st = "";
  while(n > 1)
  {
    int k = n % 3;
    st += ('0' + k);
    n = (n + 1) / 3;
  }
  reverse(st.begin(), st.end());
  //cout << st << endl;
  for(int i = 0; i < st.size(); i++){
    if(st[i] == '0'){
      G += B;
      swap(R, B);
    }
    else if(st[i] == '1'){
      B += R;
      swap(R, G);
    }
    else{
      R += G;
      swap(B, G);
    }
  }
  cout << R << " " << G << " " << B;
  return 0;
}
