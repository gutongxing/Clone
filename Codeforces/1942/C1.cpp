#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x,y,a[200010],ans;
signed main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld",&n,&x,&y);
		ans = x-2;
		for(int i = 1;i<=x;i++){
			scanf("%lld",a+i);
		}
		sort(a+1,a+1+x);
		x++;
		a[x] = a[1]+n;
		for(int i = 2;i<=x;i++){
			if(a[i]-a[i-1]==2) ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
