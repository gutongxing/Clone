#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+10;
int T,n,k,a[MAXN],b[MAXN];
signed main(){
	scanf("%d",&T);
	while(T--){
		int ans = 0;
		scanf("%d%d",&n,&k);
		for(int i = 1;i<=n;i++){
			scanf("%d",a+i);
		}
		for(int i = 1;i<=n;i++){
			scanf("%d",b+i);
		}
		int maxn = 0,sum = 0;
		for(int i = 1;i<=min(n,k);i++){
			sum+=a[i];
			maxn = max(maxn,b[i]);
			ans = max(ans,sum+(k-i)*maxn);
		}
		printf("%d\n",ans);
	}
	return 0;
}

