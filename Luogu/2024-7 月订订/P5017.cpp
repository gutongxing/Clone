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
	void o(int &x,int y){
		x>y&&(x=y);
	}
	const int MAXN = 510;
	const int MAXM = 210;
	const int MAXT = 4e6+10;
	const int INF = 0x3f3f3f3f3f3f3f3f;
	int f[MAXN][MAXM];
	int n,m,t[MAXN];
	signed main(){
		read(n);read(m);
		for(int i = 1;i<=n;i++){
			read(t[i]);
		}
		sort(t+1,t+1+n);
		memset(f,0x3f,sizeof(f));
		for(int i = 0;i<2*m;i++) f[1][i] = i;
		for(int i = 1;i<n;i++){
			for(int j = 0;j<2*m;j++){
				if(f[i][j]<INF){
					if(t[i]+j>=t[i+1]){
						o(f[i+1][t[i]+j-t[i+1]],f[i][j]+t[i]+j-t[i+1]);
					}
					for(int k = t[i] + j + m >= t[i + 1] ? 0 : t[i + 1] - t[i] - j - m;t[i] + j + m + k - t[i + 1] < m * 2; ++ k)
						if(t[i] + j + m + k >= t[i + 1])
							o(f[i + 1][t[i] + j + m + k - t[i + 1]],f[i][j] + t[i] + j + m + k - t[i + 1]);
					if(t[i]+j+m<=t[i+1]){
						for(int k = 0;k<2*m;k++){
							o(f[i+1][k],f[i][j]+k);
						}
					}
				}
				// cout << i << " " << j << " " << f[i][j] << endl;
			}
		}
		int ans = INF;
		for(int i = 0;i<2*m;i++){
			ans = min(ans,f[n][i]);
		}
		write(ans);
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
