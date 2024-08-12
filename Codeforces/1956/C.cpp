#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n;
signed main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		printf("%lld %lld\n",1ll*n*(n+1)/2*(n/2)+1ll*((n)/2+1+n)*(n-n/2)/2*n,n+n/2);
		for(int i = 1;i<=n;i++){
			printf("%lld %lld ",1ll,i);
			for(int j = 1;j<=n;j++){
				printf("%lld ",j);
			}
			puts("");
		}
		for(int i = 1;i<=n/2;i++){
			printf("%lld %lld ",2ll,i);
			for(int j = 1;j<=n;j++){
				printf("%lld ",j);
			}
			puts("");
		}
	}
	return 0;
}
