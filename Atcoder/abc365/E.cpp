#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
namespace gtx{
//	Fast IO
	void read(int &x){
		x = 0;int h = 1;char tmp;
		do{tmp=getchar();if(tmp=='-')h*=-1;}while(!isdigit(tmp));
		while(isdigit(tmp)) x*=10,x+=tmp-'0',tmp=getchar();
		x*=h;
	}
	void read(char &x){do{x=getchar();}while(x==' '||x=='\n'||x=='\r');}
	void write(char x){putchar(x);}
	void write(int x){
		if(x<0) putchar('-'),x=-x;int st[200]={0},tot=0;
		do{st[++tot]=x%10,x/=10;} while(x);
		while(tot){putchar(st[tot--]+'0');};
	}
	void write(int x,char y){write(x);write(y);}
	const int MAXN = 2e5+10;
	const int MAXBIT = 40;
	int n,a[MAXN],ans,sum[MAXN];
	signed main(){
		read(n);
		for(int i = 1;i<=n;i++){
			read(a[i]);
			sum[i] = sum[i-1]^a[i];
		}
		int res = 0;
		for(int i = 0;i<=31;i++){
			int sum0 = 1,sum1 = 0;
			for(int j = 1;j<=n;j++){
				if(sum[j]&(1<<i)){
					res += (1<<i)*sum0;
					sum1++;
				}else res += (1<<i)*sum1,sum0++;
			}
//			cout << res << endl;
		}
		for(int i = 1;i<=n;i++) res -= a[i];
		write(res);
		return 0;
	}
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T = 1;
//	gtx::read(T);
	while(T--) gtx::main();
	return 0;
}
