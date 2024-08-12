// Problem: B - Vertical Writing
// Contest: AtCoder - AtCoder Beginner Contest 366
// URL: https://atcoder.jp/contests/abc366/tasks/abc366_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
	void write(char x,char y){write(x);write(y);}
	const int MAXN = 120;
	int n,maxn[MAXN];
	char a[MAXN][MAXN];
	signed main(){
		read(n);
		for(int i = 1;i<=n;i++){
			scanf("%s",a[i]+1);
			maxn[i] = max(maxn[i-1],(int)strlen(a[i]+1));
			for(int j = strlen(a[i]+1)+1;j<=200;j++) a[i][j]='*';
		}
		for(int i = 1;i<=maxn[n];i++){
			for(int j = n;j>=1&&maxn[j]>=i;j--){
				write(a[j][i]);
			}
			puts("");
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
