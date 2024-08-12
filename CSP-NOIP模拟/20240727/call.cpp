#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
namespace gtx{
	const int MAXN = 1e5+10;
	int a[MAXN];
	struct SegmentTree{
		int l,r,val;
		int times;
	}tree[MAXN<<3];
	void build(int k,int l,int r){
		tree[k].l = l;
		tree[k].r = r;
		tree[k].times = 1;
		if(l==r){
			tree[k].val = a[l];
			return;
		}
		int mid = (l+r)>>1;
		build(k*2,l,mid);
		build(k*2+1,mid+1,r); 
	}
	void maketag(int k,int u){
		tree[k].times *= u;
		tree[k].val *= u;
	}
	void pushdown(int k){
		if(tree[k].times!=1){
			maketag(k*2,tree[k].times);
			maketag(k*2+1,tree[k].times);
			tree[k].times = 1;
		}
	}
	void add(int k,int x,int y){
		if(tree[k].l>x||tree[k].r<x) return;
		if(tree[k].l==x&&tree[k].r==x){
			tree[k].val+=y;
			return;
		}
		pushdown(k);
		add(k*2,x,y);
		add(k*2+1,x,y); 
	}
	int ask(int k,int x){
		if(tree[k].l>x||tree[k].r<x) return 0;
		if(tree[k].l==x&&tree[k].r==x){
			return tree[k].val;
		}
		pushdown(k);
		return ask(k*2,x)+
		ask(k*2+1,x);
	}
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
	struct node{
		int tf,x,val;
		vector<int> v;
	}fuc[MAXN];
	int n,m,q;
	void dfs(int k){
		if(fuc[k].tf==1){
			add(1,fuc[k].x,fuc[k].val);
//			cout << k << endl;
//			for(int i = 1;i<=n;i++){
//				write(ask(1,i),' ');
//			}
//			cout << endl;
			return;
		}
		if(fuc[k].tf==2){
			tree[1].times*=fuc[k].val;
//			cout << k << endl;
//			for(int i = 1;i<=n;i++){
//				write(ask(1,i),' ');
//			}
//			cout << endl;
			return;
		}
		for(int i:fuc[k].v) dfs(i);
	}
	signed main(){
		read(n);
		for(int i = 1;i<=n;i++){
			read(a[i]);
		}
		build(1,1,n);
		read(m);
		int cnt = 0;
		for(int i= 1;i<=m;i++){
			read(fuc[i].tf);
			if(fuc[i].tf==1){
				read(fuc[i].x);
				read(fuc[i].val);
			}else if(fuc[i].tf==2){
				read(fuc[i].val);
			}else{
				cnt++;
				int k;
				read(k);
				while(k--){
					int x;
					read(x);
					fuc[i].v.push_back(x);
				}
			}
		}
		if(cnt==m){
			for(int i = 1;i<=n;i++){
				write(ask(1,i),' ');
			}
			return 0;
		}
		read(q);
		while(q--){
			int x;
			read(x);
			dfs(x);
		}
		for(int i = 1;i<=n;i++){
			write(ask(1,i),' ');
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
