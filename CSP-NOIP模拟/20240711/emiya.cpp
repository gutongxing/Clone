#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
//Fast IO
const int MOD = 998244353;
void read(int &x){
	int k = 1;
	x = 0;
	char tmp;
	do{tmp = getchar();if(tmp=='-') k*=-1;}while(!isdigit(tmp));
	while(isdigit(tmp)) x*=10,x+=tmp-'0',tmp=getchar();
	x*=k;
}
void write(int x){
	if(x==0) putchar('0');
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
const int MAXN = 3e3+10;
int n,m,a[MAXN][MAXN];
signed main(){
	freopen("emiya.in","r",stdin);
	freopen("emiya.out","w",stdout);
	read(n);read(m);
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			read(a[i][j]);
		}
	}
	if(m==2){
		int ans1 = 0,ans2 = 0; 
		for(int i = 1;i<=n;i++){
			ans1 += a[i][1];
			ans2 += a[i][2];
			ans1 %= MOD;
			ans2 %= MOD;
		}
		int ans = 0;
		for(int i = 1;i<=n;i++){
			ans += a[i][1]*(ans2-a[i][2])%MOD;
			ans%=MOD;
		}
		write(((ans%MOD)+MOD)%MOD);
		return 0; 
	}else if(m==3){
		int ans1 = 0,ans2 = 0,ans3 = 0; 
		for(int i = 1;i<=n;i++){
			ans1 += a[i][1];
			ans2 += a[i][2];
			ans3 += a[i][3];
			ans1 %= MOD;ans2 %= MOD;ans3 %= MOD; 
		}
		int ans = 0;
		for(int i = 1;i<=n;i++){
			ans += a[i][1]*((ans2-a[i][2])%MOD)%MOD;
			ans%=MOD;
			ans += a[i][2]*((ans3-a[i][3])%MOD)%MOD;
			ans%=MOD;
			ans += a[i][1]*((ans3-a[i][3])%MOD)%MOD;
			ans%=MOD;
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(i==j) continue;
				ans += a[i][1]*a[j][2]%MOD*((ans3-a[i][3]-a[j][3])%MOD)%MOD;
				ans%=MOD;
			}
		}
		write(((ans%MOD)+MOD)%MOD);
		return 0;
	}
	return 0;
}

