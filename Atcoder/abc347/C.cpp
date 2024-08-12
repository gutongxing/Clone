#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a,b,d[500100],q[500100];
signed main(){
	scanf("%lld%lld%lld",&n,&a,&b);
	for(int i = 1;i<=n;i++){
		scanf("%lld",d+i);
		d[i] = (d[i]-1)%(a+b)+1;
	}
	sort(d+1,d+1+n);
	for(int i = 1;i<=n;i++){
		d[i+n] = d[i]+(a+b);
	}
	bool fj = 0;
	for(int i = n;i<=2*n;i++){
		if(d[i]-d[i-n+1]<a) fj = 1;
	}
	if(fj) puts("Yes");
	else puts("No");
	return 0;
}

