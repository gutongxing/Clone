#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,maxi,maxn;
map<int,int> mp;
signed main(){
	cin >> n;
	for(int i = 1;i<=n;i++){
		int a,b;
		cin >> b >> a;
		if(mp.find(a)!=mp.end()){
			mp[a] = min(mp[a],b);
		}else mp[a] = b;
	}
	for(auto i:mp){
		maxn = max(maxn,i.second);
	}
	cout << maxn;
	return 0;
}
