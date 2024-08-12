#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
const int MAXN = 2e5;
int T,n,a[MAXN];
signed main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		int minimum = 0,maximum = 0,ans_max = 0,ans_min = 1;
		for(int i = 1;i<=n;i++){
			scanf("%lld",a+i);
			if(i==3){
				int x= 0 ;
			}
			if(maximum+a[i]==abs(minimum+a[i])&&maximum!=minimum){
				ans_max = ans_max*(maximum>=0?2:1)%MOD+ans_min*(minimum+a[i]>=0?2:1)%MOD;
			}else if(maximum+a[i]<=abs(minimum+a[i])){
				ans_max = ans_min*(minimum+a[i]>=0?2:1);
			}else ans_max = ans_max*(maximum+a[i]>=0?2:1);
			ans_max %= MOD;
			maximum = max(maximum+a[i],abs(minimum+a[i]));
			minimum += a[i];
			if(a[i]>0) ans_min *= 2;
			ans_min%=MOD;
		}
		printf("%lld\n",(ans_max+MOD)%MOD);
	}
	return 0;
}
