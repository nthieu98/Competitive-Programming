#include <bits/stdc++.h>

using namespace std;


int main()
{
  int ans = 0;
  for(int p = 1; p >= 0; p--)
    for(int q = 3; q >=0; q--)
      for(int i = 6; i >= 0; i--)
        for(int j = 12; j >=0; j--)
          for(int k = 24; k >= 0; k--)
            if(16*p+8*q+4*i+2*j+1*k==24) ans++;
  cout << ans;
  return 0;
}
