#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 	freopen("03.in","r",stdin);
 	freopen("03.out","w",stdout);
    int t;
    cin >> t;
 
    while (t--) {
        int n, m;
        cin >> n >> m;
 
        vector<vector<int>> grid1(n, vector<int>(m));
        vector<vector<int>> grid2(n, vector<int>(m));
 
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid1[i][j];
 
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid2[i][j];
 
        map<set<int>, int> mp, mpp;
 
        for (int i = 0; i < n; i++) {
            set<int> st(grid1[i].begin(), grid1[i].end());
            mp[st]++;
        }
 
        bool flag = true;
 
        for (int i = 0; i < n; i++) {
            set<int> st(grid2[i].begin(), grid2[i].end());
            if (mp.find(st) == mp.end() || mp[st] == 0) {
                flag = false;
                break;
            }
            mp[st]--;
            if (mp[st] == 0) mp.erase(st);
        }
 
        for (int i = 0; i < m; i++) {
            set<int> st;
            for (int j = 0; j < n; j++)
                st.insert(grid1[j][i]);
            mpp[st]++;
        }
 
        for (int i = 0; i < m; i++) {
            set<int> st;
            for (int j = 0; j < n; j++)
                st.insert(grid2[j][i]);
            if (mpp.find(st) == mpp.end() || mpp[st] == 0) {
                flag = false;
                break;
            }
            mpp[st]--;
            if (mpp[st] == 0) mpp.erase(st);
        }
 
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
 
    return 0;
}
