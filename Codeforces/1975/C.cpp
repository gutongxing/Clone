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
		int maxn = 0;
		for(int i = 1;i<=n;i++){
			scanf("%lld",u+i);
			if(i!=n) maxn = max(maxn,u[i]);
		}
		printf("%d\n",maxn);
	}
	return 0;
}

