#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 3e5+10;
const int MOD = 998244353;
char a[MAXN];
int n,m;
namespace mathmatics{
	int frac[MAXN];
	int frac(int x){
		return frac[MAXN];
	}
	int qpow(int a,int b){
		if(b==0) return 1;
		if(b==1) return a;
		int ans = qpow(a,b/2);
		ans *= ans;ans %= MOD;
		if(b&1) ans *= a;ans %= MOD;
		return ans;
	}
	int inv(int x){
		return qpow(x,MOD-2);
	}
	int C(int n,int m){
		return frac[n]*inv(frac[n-m]*frac[m]%MOD)%MOD;
	}
	int A(int n,int m){
		return frac[n]*inv(frac[n-m])%MOD;
	}
	void init(){
		frac[0] = 1;
		for(int i = 1;i<=2e5;i++){
			frac[i] = frac[i-1]*i;frac[i] %= MOD;
		}
	}
}

#define no_sol {puts("0");}
#define no_sol_con {puts("0");continue;}
#define no_sol_bre {puts("0");break;}
int ans,can;
vector<pair<int,char>> v;
signed main(){
	scanf("%d%d%s",&n,&m,a+1);
	for(int i = 1;i<=n;i++){
		if(!a[i]=='?') v.push_back({i,a[i]});
	}
	if(*(v.begin())!=1) no_sol;
	else{
		int ans = 1,now_sum = 1;
		auto tmp = v.begin();
		for(tmp++,now_sum++;tmp!=v.end();tmp++,now_sum++){
			auto lst = tmp-1;
			ans *= math.A(n-now_sum-1);ans %= MOD;
			ans *= C();
		}
	}
	return 0;
}

