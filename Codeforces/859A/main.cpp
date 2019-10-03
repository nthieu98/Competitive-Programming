#include <bits/stdc++.h>

using namespace std;

int n;
int a[30];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int k = *max_element(a+1, a+n+1);
    cout << max(0, k-25);
    return 0;
}
