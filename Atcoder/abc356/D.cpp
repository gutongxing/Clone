#include<bits/stdc++.h>
#define int long long
#pragma G++ optimize(2) 
using namespace std;
const int MOD = 998244353;
int n,m,ans;
signed main(){
	scanf("%lld%lld",&n,&m);n++;
	bitset<100> b(m);
	for(int i = 0;i<=60;i++){
		if(b[i]){
			ans += n/(1ll<<(i+1))*(1ll<<i)%MOD;ans%=MOD;
			ans += max(0ll,n%(1ll<<(i+1))-(1ll<<i));
		}
		ans%=MOD;
	}
	printf("%lld",ans);
	return 0;
}

