#include<bits/stdc++.h>
using namespace std;
int T,n;map<char,int> mp;char a[510];
signed main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,a+1);
		int cnt = 0;
		mp.clear();
		for(int i = 1;i<=n;i++){
			mp[a[i]]++;
		}
		for(auto tmp:mp){
			if(tmp.first<=tmp.second+'A'-1) cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}

