// LUOGU_RID: 161565567
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int maxmod=998244353000000000;
int n,x,dp[105][105][1024],jc[105],ans,t;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>x;
	jc[0]=1;
	for(int i=1;i<=n;i++){
		jc[i]=jc[i-1]*i%mod;
	}
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			for(int z=0;z<(1<<(2*x-1));z++){
				t=(z>>1);
				dp[i][j][t]+=dp[i-1][j][z];
				dp[i][j][t]%=mod;
				for(int k=0;k<2*x-1;k++){
					if(!(t&(1<<k))&&k+i-x>=0&&k+i-x<=n-1){
						dp[i][j+1][t|(1<<k)]+=dp[i-1][j][z];
						dp[i][j+1][t|(1<<k)]%=mod;
					}
				}
cout << i << " " << j << " " << z << " " << dp[i][j][z] << endl;
			}
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<(1<<(2*x-1));j++){
			//if(dp[n][i][j])cout<<dp[n][i][j]<<' '<<i<<' '<<j<<'\n';
			if(i%2){
				ans-=dp[n][i][j]*jc[n-i];
			}else ans+=dp[n][i][j]*jc[n-i];
			ans=(ans+maxmod)%mod;
		}
	}
	cout<<ans;
	return 0;
}


