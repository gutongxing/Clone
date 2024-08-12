#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        map<char, int> mp;
        string s; cin >> s;
        for (char c: s) mp[c]++;
        int ans = 0;
        for (char c: string("ABCDEFG")) {
            ans += max(0, m - mp[c]);
        }
        cout << ans << endl;
    }
}
