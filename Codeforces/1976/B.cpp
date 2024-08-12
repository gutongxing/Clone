#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5+10;
int T,n,a[MAXN],b[MAXN];
signed main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(int i = 1;i<=n;i++){
			scanf("%lld",a+i);
		}
		int ans = 0;
		for(int i = 1;i<=n;i++){
			scanf("%lld",&b[i]);
			ans += abs(b[i]-a[i]);
		}
		int x;
		scanf("%lld",&x);
		int minn = 0x3f3f3f3f3f3f3f3f;
		for(int i = 1;i<=n;i++){
			if(b[i]<a[i]) swap(a[i],b[i]);
			if(a[i]>x) minn = min(minn,a[i]-x);
			else if(b[i]<x) minn = min(minn,x-b[i]);
			else minn = 0;
		}
		printf("%lld\n",ans+minn+1);
	}
	return 0;
}

