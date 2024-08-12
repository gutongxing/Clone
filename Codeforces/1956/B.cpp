#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
map<int,int> mp;
int T,n,x,ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		mp.clear();
		cin >> n;
		for(int i = 1;i<=n;i++){
			cin >> x;
			mp[x]++;
		}
		ans = 0;
		for(auto i:mp){
			if(i.second == 2){
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
