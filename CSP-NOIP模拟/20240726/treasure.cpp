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
	const int MAXN = 15;
	const int INF = 0x3f3f3f3f;
	int vis[MAXN];
	int n,m,ans=INF;
	struct Edge{
		int x,y,z;
	}E[MAXN];
	void dfs(int k,int now){
		if(ans<now) return;
		if(k==n){
			ans = now;
			return;
		}
		for(int i = 1;i<=m;i++){
			bool f1 = vis[E[i].x]==INF;
			bool f2 = vis[E[i].y]==INF;
			if(!(f1^f2)) continue;
			if(f1){
				vis[E[i].x] = vis[E[i].y]+1;
				dfs(k+1,now+vis[E[i].x]*E[i].z);
				vis[E[i].x] = INF;
			}else{
				vis[E[i].y] = vis[E[i].x]+1;
				dfs(k+1,now+vis[E[i].y]*E[i].z);
				vis[E[i].y] = INF;
			}
		}
	}
	signed main(){
		read(n);read(m);
		for(int i = 1;i<=m;i++) read(E[i].x),read(E[i].y),read(E[i].z);
		for(int i = 1;i<=n;i++) vis[i] = INF;
		for(int i = 1;i<=n;i++) vis[i] = 0,dfs(1,0),vis[i] = INF;
		write(ans);
		return 0;
	}
}
signed main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T = 1;
//	gtx::read(T);
	while(T--) gtx::main();
	return 0;
}

