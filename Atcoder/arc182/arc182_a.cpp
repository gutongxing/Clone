// Problem: A - Chmax Rush!
// Contest: AtCoder - AtCoder Regular Contest 182
// URL: https://atcoder.jp/contests/arc182/tasks/arc182_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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
	const int MAXN = 5100;
	const int MOD = 998244353;
	class SegmentTree{
		private:
			struct st{
				int l,r,maxn;
			}tree[MAXN<<3];
			void pushdown(int k){
				tree[k*2].maxn = max(tree[k*2].maxn,tree[k].maxn);
				tree[k*2+1].maxn = max(tree[k*2+1].maxn,tree[k].maxn);
			}
			void pushup(int k){
				tree[k].maxn = max(tree[k*2].maxn,tree[k*2+1].maxn);
			}
		public:
			void build(int k,int l,int r){
				tree[k].l = l;
				tree[k].r = r;
				if(l==r){return ;}
				int mid = (l+r)>>1;
				build(k*2,l,mid);
				build(k*2+1,mid+1,r);
			}
			void to(int k,int l,int r,int p){
				if(tree[k].l>r||tree[k].r<l) return;
				if(tree[k].l>=l||tree[k].r<=r){
					tree[k].maxn = max(tree[k].maxn,p);
					return;
				}
				pushdown(k);
				to(k*2,l,r,p);
				to(k*2+1,l,r,p);
				pushup(k);
			}
			int maxn(int k,int l,int r){
				if(tree[k].l>r||tree[k].r<l) return 0;
				if(tree[k].l>=l||tree[k].r<=r){
					return tree[k].maxn;
				}
				pushdown(k);
				int p = max(maxn(k*2,l,r),maxn(k*2+1,l,r));
				pushup(k);
				return p;
			}
	};
	int n,q,dp[MAXN][2],p[MAXN],v[MAXN];
	signed main(){
		read(n);read(q);
		for(int i = 1;i<=q;i++){
			read(p[i]);read(v[i]);
			SegmentTree tl,tr;
			tl.build(1,1,n);
			tr.build(1,1,n);
			dp[i][0] = dp[i][1] = 1;
			for(int j = 1;j<i;j++){
				if(v[j]>v[i]){
					if(p[j]<p[i]) dp[i][0] = 0;
					else if(tl.maxn(1,p[j],n)>v[j]) dp[i][0] = 0;
					else{
						tl.to(1,p[j],n,v[j]);
						dp[i][0] = (dp[i][0]*dp[j][1])%MOD;
					}
				}else{
					dp[i][0] = (dp[i][0]*(dp[j][0]+dp[j][1])%MOD)%MOD;
				}
			}
			for(int j = 1;j<i;j++){
				if(v[j]>v[i]){
					if(p[j]>p[i]) dp[i][1] = 0;
					else if(tr.maxn(1,1,p[j])>v[j]) dp[i][1] = 0;
					else{
						tr.to(1,1,p[j],v[j]);
						dp[i][1] = (dp[i][1]*dp[j][0])%MOD;
					}
				}else{
					dp[i][1] = (dp[i][1]*(dp[j][0]+dp[j][1])%MOD)%MOD;
				}
			}
		}
		write((dp[q][0]+dp[q][1])%MOD);
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
