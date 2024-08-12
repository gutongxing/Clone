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
	const int MAXN = 1e5+10;
	const int MOD = 998244353;
	int n,a[MAXN],m,q;
	struct node{
		int type;
		int x,val;
		vector<int> v;
	}f[MAXN];
	int rd[MAXN],reply[MAXN];
	int mul[MAXN],add[MAXN],d[MAXN];
	bool vis[MAXN];
	void dfs(int x){
		if(vis[x]) return;
		vis[x] = 1;
		if(f[x].type==1) return;
		if(f[x].type==2) return mul[x] = f[x].val,void();
		for(int i:f[x].v){
			dfs(i);
			mul[x] = (mul[x]*mul[i])%MOD;
		}
	}
	vector<int> topo_order,topo_rever;
	void Topo(){
		queue<int> q;
		for(int i = 1;i<=m;i++){
			if(!rd[i]){
				q.push(i);
			}
		}
		stack<int> st;
		while(!q.empty()){
			int tmp = q.front();q.pop();
			topo_order.push_back(tmp);
			if(f[tmp].type==3) for(int i:f[tmp].v) if(!(--rd[i])) q.push(i);
		}
		topo_rever = topo_order;
		reverse(topo_rever.begin(),topo_rever.end());
	}
	int qpow(int x,int y){
		if(y==0) return 1;
		if(y==1) return x;
		int k = qpow(x,y>>1);
		k*=k;k%=MOD;
		if(y&1) k*=x;k%=MOD;
		return k;
	}
	signed main(){
		read(n);
		for(int i = 1;i<=n;i++){
			read(a[i]);
			mul[i] = 1;
		}
		read(m);
		for(int i = 1;i<=m;i++){
			int T;
			read(T);
			f[i].type = T;
			if(T==1){
				read(f[i].x);read(f[i].val);
			}else if(T==2) read(f[i].val);
			else{
				int x;
				read(x);
				while(x--){
					int y;
					read(y);
					f[i].v.push_back(y);
					rd[y]++;
				}
				reverse(f[i].v.begin(),f[i].v.end());
			}
		}
		Topo();
		for(int i:topo_rever){
			if(f[i].type==1){mul[i]=1;continue;}
			if(f[i].type==2){mul[i]=f[i].val;continue;}
			for(int x:f[i].v){mul[i]=(mul[x]*mul[i])%MOD;}
		}
		read(q);
		int now = 1;
		vector<int>vvv;
		for(int i = 1;i<=q;i++){int k;read(k);vvv.push_back(k);}
		reverse(vvv.begin(),vvv.end());
		for(int k:vvv){
			add[k] = (add[k]+now)%MOD;
			reply[k]++;
			now = (now*mul[k])%MOD;
		}
		int summ = 1;
		for(int x:topo_order){
			if(f[x].type==1) d[f[x].x]=(d[f[x].x]+add[x]*f[x].val%MOD)%MOD;
			if(f[x].type==2) summ = (summ*qpow(f[x].val,reply[x]))%MOD; 
			if(f[x].type==1||f[x].type==2) continue;
			int now = add[x];
			for(int i:f[x].v){
				add[i]=(add[i]+now)%MOD;
				reply[i] = (reply[i]+reply[x])%MOD;
				now=(now*mul[i])%MOD;
			}
		}
		for(int i = 1;i<=n;i++){
			write((a[i]*summ%MOD+d[i])%MOD,' ');
		}
		return 0;
	}
}
signed main(){
 	freopen("call.in","r",stdin);
 	freopen("call.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T = 1;
//	gtx::read(T);
	while(T--) gtx::main();
	return 0;
}
