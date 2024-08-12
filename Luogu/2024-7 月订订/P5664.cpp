#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
//Fast IO
void read(int &x){
	int k = 1;
	x = 0;
	char tmp;
	do{tmp = getchar();if(tmp=='-') k*=-1;}while(!isdigit(tmp));
	while(isdigit(tmp)) x*=10,x+=tmp-'0',tmp=getchar();
	x*=k;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	stack<int> st;
	while(x) st.push(x%10),x/=10;
	while(!st.empty()) putchar(st.top()+'0'),st.pop();
}
void write(char x){
	putchar(x);
}
void write(int x,char y){
	write(x);write(y);
}
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
const int MAXN = 120;
const int MAXM = 2e3+10;
int n,m,a[MAXN][MAXM],f[MAXN][MAXN*2],sum[MAXN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(n);read(m);
	int opt = 1;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			read(a[i][j]);
			sum[i] += a[i][j];sum[i]%=MOD;
		}
		opt*=(sum[i]+1);opt%=MOD;
	}
//	cout << opt << endl;
	int ans = 0;
	for(int j = 1;j<=m;j++){
		memset(f,0,sizeof(f));
		f[0][n] = 1;
		for(int i = 1;i<=n;i++){
			for(int k = 0;k<=2*n;k++){
				f[i][k] = (f[i-1][k]+f[i-1][k-1]*a[i][j]%MOD)%MOD+f[i-1][k+1]*((sum[i]-a[i][j]+MOD)%MOD+MOD)%MOD;
				f[i][k] %= MOD;
			}
		}
		for(int k = n+1;k<=2*n;k++){
			ans += f[n][k];ans%=MOD;
		}
	}
	write(((opt-1-ans+MOD)%MOD+MOD)%MOD);
	return 0;
}

