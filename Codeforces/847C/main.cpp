#include <bits/stdc++.h>

using namespace std;

long long n, k;
const long long K = 1ll*150000*300001;

int main()
{
  cin >> n >> k;
  long long re = k;
  if(k > K) {
    cout << "Impossible";
    exit(0);
  }
  long long pos, S = 0;
  for(long long i = 1; i <= 300000; i++){
    S+=i;
    if(S > k) {
      pos = i-1;
      re-=(S-i);
      break;
    }
  }
  if(pos+1+(re!=0) > n){
    cout << "Impossible";
    exit(0);
  }
  int p = n-(pos+1+(re!=0));
  for(int i = 0; i <= pos; i++){
    cout << "(";
    if(i == re-1 && re) cout << "()";
  }
  for(int i = 0; i <= pos; i++) cout << ")";
  for(int i = 1; i <= p; i++) cout <<"()";
  return 0;
}
