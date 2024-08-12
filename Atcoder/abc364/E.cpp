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
	const int MAXN = 100;
	int n,x,y;
	struct node{
		int a,b;
	}p[MAXN];
	int f[10001][MAXN];
	signed main(){
		read(n);read(x);read(y);
		for(int i = 1;i<=n;i++){
			read(p[i].a);
			read(p[i].b);
		}
		memset(f,0x3f,sizeof(f));
		f[0][0] = 0;
		for(int i = 1;i<=n;i++){
			for(int j = x;j>=p[i].a;j--){
				for(int k = n;k>=1;k--){
					f[j][k] = min(f[j][k],f[j-p[i].a][k-1]+p[i].b);
//					cout << j << " " << k << " " << f[j][k] << endl;
				}
			}
		}
		int maxn = 0;
		for(int i = 0;i<=x;i++){
			for(int j = 0;j<=n;j++){
				if(f[i][j]<=y){
					maxn = max(maxn,j);
				}
			}
		}
		if(maxn<n) maxn++;
		write(maxn);
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

