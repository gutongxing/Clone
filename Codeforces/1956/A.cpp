#include<bits/stdc++.h>
using namespace std;
int T,k,q,a[120],n[120];
signed main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&k,&q);
		for(int i = 1;i<=k;i++) scanf("%d",a+i);
		for(int i = 1;i<=q;i++) scanf("%d",n+i);
		for(int i = 1;i<=q;i++) printf("%d ",min(n[i],a[1]-1));
		puts("");
	}
	return 0;
}
