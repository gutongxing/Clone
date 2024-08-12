#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
#define endl '\n'
//#define int long long
//Fast IO
int x,y;
string tmp;
map<string,int> vis;
vector<pair<char,bool>> can;
int k,n,ans;
inline bool pan(string a){
	for(int i = 0;i<a.size();i++){
		if(a[i]!=a[a.size()-1-i]) return false;
	}
	return true;
}
inline void dfs(string tmp){
//	cout << tmp << endl;
	if((int)tmp.size()==n){
		ans++;
		return;
	}
	if(vis.find(tmp)!=vis.end()) return;
	vis[tmp] = 1;
	for(int i = 0;i<n;i++){
		bool flag = 1;
		if(can[i].second==0) continue;
		tmp += can[i].first;
		if((int)tmp.size()>=k){
			if(pan(tmp.substr(tmp.size()-k,k))) flag =0 ;
		}
		if(flag){
			can[i].second = 0;
			dfs(tmp);
			can[i].second = 1;
		}
		tmp.erase(--tmp.end());
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	string s;
	cin >> s;
	for(register char tmp:s){
		can.push_back({tmp,1});
	}
	dfs("");
	cout << ans;
	return 0;
}
