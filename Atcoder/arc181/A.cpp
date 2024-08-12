#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
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
	int n,a[MAXN],maxn[MAXN],minn[MAXN];
	signed main(){
		read(n);
		bool flag = 1;
		for(int i = 1;i<=n;i++) read(a[i]),flag&=(a[i]==i);
		if(flag) return write(0,endl),0;
		minn[n+1] = 0x3f3f3f3f;
		for(int i = 1;i<=n;i++) maxn[i]=max(maxn[i-1],a[i]);
		for(int i = n;i>=1;i--) minn[i]=min(minn[i+1],a[i]);
		for(int i = 1;i<=n;i++) if(maxn[i]==minn[i]) return puts("1"),0;
		if(a[1]==n&&a[n]==1) return puts("3"),0;
		puts("2");
		return 0;
	}
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T = 1;
	gtx::read(T);
	while(T--) gtx::main();
	return 0;
}
