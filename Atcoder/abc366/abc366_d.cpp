// Problem: D - Cuboid Sum Query
// Contest: AtCoder - AtCoder Beginner Contest 366
// URL: https://atcoder.jp/contests/abc366/tasks/abc366_d
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
	const int MAXN = 120;
	int a[MAXN][MAXN][MAXN],b[MAXN][MAXN][MAXN],n,q;
	signed main(){
		read(n);
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		for(int k=1;k<=n;k++)
		read(a[i][j][k]);
		for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
        for(int k=1;k<=n;k++)
	    b[i][j][k]=b[i-1][j][k]+b[i][j-1][k]+b[i][j][k-1]
	                -b[i-1][j-1][k]-b[i-1][j][k-1]-b[i][j-1][k-1]
	                +b[i-1][j-1][k-1]+a[i][j][k];
		read(q);
		while(q--){
			int x,y,z,p,q,r;
			read(p);read(x);read(q);read(y);read(r);read(z);
			write(b[x][y][z]-b[x][y][r-1]-b[x][q-1][z]-b[p-1][y][z]
			+b[x][q-1][r-1]+b[p-1][y][r-1]+b[p-1][q-1][z]
			-b[p-1][q-1][r-1],'\n');
		}
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
