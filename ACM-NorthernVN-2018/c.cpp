#include <bits/stdc++.h>

using namespace std;

vector <pair <char, long long> > a, b, ans;
long long p, c;
string o, s, t;

long long num(string &str, int index) {
    long long res = 0;
    while (index < (int)str.size() && isdigit(str[index])) {
        res = res * 10 + str[index] - '0';
        ++index;
    }
    return res;
}

void conv(vector <pair <char, long long> > &dest, string &src) {
    for (int i = 0; i < (int)src.size(); ++i) {
        if (islower(src[i])) {
            dest.push_back({src[i], num(src, i + 1)});
        }
    }
}

void solve1() {
    cin >> s >> t;
    conv(a, s);
    conv(b, t);
    if (a.back().first == b[0].first) {
        a.back().second += b[0].second;
    } else {
        a.push_back(b[0]);
    }
    for (pair <char, long long> e: a) {
        cout << e.first << e.second;
    }
    for (int i = 1; i < (int)b.size(); ++i) {
        cout << b[i].first << b[i].second;
    }
}

void reduce() {
    for (int i = 1; i < (int)ans.size(); ++i) {
        if (ans[i].first == ans[i - 1].first) {
            ans[i].second += ans[i - 1].second;
            ans[i - 1].second = 0;
        }
    }
}

void solve2() {
    cin >> s >> p >> c;
    --p;
    conv(a, s);
    int idx = 0;
    for (; idx < (int)a.size(); ++idx) {
        if (p < a[idx].second) break;
        p -= a[idx].second;
        ans.push_back(a[idx]);
    }
    if (p) {
        ans.push_back(a[idx]);
        ans.back().second = p;
        a[idx].second -= p;
    }
    for (; idx < (int)a.size(); ++idx) {
        long long foo = min(c, a[idx].second);
        a[idx].second -= foo;
        c -= foo;
        if (a[idx].second)
            ans.push_back(a[idx]);
    }
    reduce();
    for (pair <char, long long> e: ans) {
        if (e.second)
            cout << e.first << e.second;
    }
}

void solve3() {
    cin >> s >> p >> c;
    --p;
    conv(a, s);
    int idx = 0;
    for (; idx < (int)a.size(); ++idx) {
        if (p < a[idx].second) break;
        p -= a[idx].second;
    }
    ans.push_back(a[idx]);
    ans[0].second -= p;
    if (c <= ans[0].second)
        ans[0].second = c;
    else {
        c -= ans[0].second;
        for (++idx; idx < (int)a.size(); ++idx) {
            if (c == 0) break;
            ans.push_back(a[idx]);
            ans.back().second = min(ans.back().second, c);
            c -= ans.back().second;
        }
    }
    for (pair <char, long long> e: ans) {
        if (e.second)
            cout << e.first << e.second;
    }
}

void solve4() {
    cin >> s >> t >> p;
    --p;
    conv(a, s);
    conv(b, t);
    int idx = 0;
    for (; idx < (int)a.size(); ++idx) {
        if (p < a[idx].second) break;
        p -= a[idx].second;
        ans.push_back(a[idx]);
    }
    pair <char, long long> as, af;
    if (idx != (int)a.size()) {
        as = af = a[idx];
        as.second = p;
        af.second = a[idx].second - p;
    } else {
        as = af = {0, 0};
    }

    if (as.second) ans.push_back(as);
    for (pair <char, long long> e: b) {
        ans.push_back(e);
    }

    if (af.second) ans.push_back(af);
    for (++idx; idx < (int)a.size(); ++idx)
        ans.push_back(a[idx]);
    reduce();
    for (pair <char, long long> e: ans) {
        if (e.second)
            cout << e.first << e.second;
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    while (cin >> o) {
        a.clear();
        b.clear();
        ans.clear();
        cout << o << ": ";
        switch (o[1]) {
            case '1': solve1(); break;
            case '2': solve2(); break;
            case '3': solve3(); break;
            default: solve4(); break;
        }
        cout << endl;
    }
}