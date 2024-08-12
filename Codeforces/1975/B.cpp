#include<bits/stdc++.h>
#define int long long
#pragma G++ optimize(2)
using namespace std;
const int MAXN = 1e5+10;
int T;
int n;
int u[MAXN];
signed main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(int i = 1;i<=n;i++){
			scanf("%lld",u+i);
		}
		sort(u+1,u+1+n);
		n = unique(u+1,u+1+n)-u-1;
		bool fg = 1;
		vector<int> v;
		for(int i = 2;i<=n;i++){
			if(u[i]%u[1]) v.push_back(u[i]);
		}
		for(int i = 1;i<v.size();i++){
			if(v[i]%v[0]) fg = 0;
		}
		if(fg) puts("yes");
		else puts("no");
	}
	return 0;
}

