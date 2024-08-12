//Math and Two Points
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
	const int MAXV = 4e6+10;
	int n,d,x[MAXN],y[MAXN],sumx[MAXV],sumy[MAXV],cntx,cnty,sum;
	int summx[MAXV],summy[MAXV],ans;
	signed main(){
		read(n);read(d);
		for(int i = 1;i<=n;i++){
			read(x[i]);read(y[i]);
			sumx[x[i]+2000001]++;
			sumy[y[i]+2000001]++;
		}
		sum = 0;
		for(int i = 1;i<=n;i++) sum += x[i]+2000001;
		cntx = n;
		for(int i = 1;i<=MAXV-2;i++){
			sum -= cntx;
			sum += (n-cntx);
			cntx -= sumx[i];
			if(sum<=d) summx[sum]++;
		}
		sum = 0;
		for(int i = 1;i<=n;i++) sum += y[i]+2000001;
		cnty = n;
		for(int i = 1;i<=MAXV-2;i++){
			sum -= cnty;
			sum += (n-cnty);
			cnty -= sumy[i];
			if(sum<=d) summy[sum]++;
		}
		sum = 0;
		ans = 0;
		for(int i = 0;i<=d;i++){
			ans += summy[i];
		}
		sum += summx[0]*ans;
		for(int i = 1;i<=d;i++){
			sum += summx[i]*(ans-=summy[d-i+1]);
		}
		write(sum);
		return 0;
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T = 1;
//	gtx::read(T);
	while(T--) gtx::main();
	return 0;
}
