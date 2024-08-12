#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+10;
const long long INF = 0x3f3f3f3f3f3f3f3f;
int opt,n,m,r,p,q,x,y,z,w[MAXN];
char tmp[MAXN];
struct SegmentTree{
	int l,r,len;
	long long maxn,sum;
	long long lazy_sum,lazy_to = INF;
}tree[MAXN<<2];
inline void pushup(int k){
	if(tree[k].l==tree[k].r) return;
	tree[k].maxn = max(tree[k*2].maxn,tree[k*2+1].maxn);
	tree[k].sum = tree[k*2].sum+tree[k*2+1].sum;
}
inline void pushdown(int k){
	if(tree[k].lazy_to!=INF){
		tree[k*2].sum = tree[k].lazy_to*tree[k*2].len;
		tree[k*2+1].sum = tree[k].lazy_to*tree[k*2+1].len;
		tree[k*2].maxn = tree[k].lazy_to;
		tree[k*2+1].maxn = tree[k].lazy_to;
		tree[k*2].lazy_sum = tree[k*2+1].lazy_sum = 0;
		tree[k*2].lazy_to = tree[k*2+1].lazy_to = tree[k].lazy_to;
		tree[k].lazy_to = INF;
	}
	if(tree[k].lazy_sum){
		tree[k*2].sum += tree[k].lazy_sum*tree[k*2].len;
		tree[k*2+1].sum += tree[k].lazy_sum*tree[k*2+1].len;
		tree[k*2].maxn += tree[k].lazy_sum;
		tree[k*2+1].maxn += tree[k].lazy_sum;
		tree[k*2].lazy_sum += tree[k].lazy_sum;
		tree[k*2+1].lazy_sum += tree[k].lazy_sum;
		tree[k].lazy_sum = 0;
	}
}
inline void build(int k,int l,int r){
	tree[k].l = l;tree[k].r = r;
	tree[k].len = r-l+1;
	tree[k].lazy_to = INF;
	if(l==r) return;
	int mid = (l+r)>>1;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
inline void modify(int k,int x,int y){
	if(tree[k].l>x||tree[k].r<x) return;
	if(tree[k].l==x&&tree[k].r==x){
		tree[k].maxn = y;
		tree[k].sum = y;
		return;
	}
	pushdown(k);
	modify(k*2,x,y);
	modify(k*2+1,x,y);
	pushup(k);
}
inline void modify(int k,int l,int r,int x){
	if(tree[k].l>r||tree[k].r<l) return;
	if(tree[k].l>=l&&tree[k].r<=r){
		tree[k].maxn = x;
		tree[k].sum = x*tree[k].len;
		tree[k].lazy_sum = 0;
		tree[k].lazy_to = x;
		return;
	}
	pushdown(k);
	modify(k*2,l,r,x);
	modify(k*2+1,l,r,x);
	pushup(k);
}
inline void add(int k,int x,int y){
	if(tree[k].l>x||tree[k].r<x) return;
	if(tree[k].l==x&&tree[k].r==x){
		tree[k].maxn += y;
		tree[k].sum += y;
		return;
	}
	pushdown(k);
	add(k*2,x,y);
	add(k*2+1,x,y);
	pushup(k);
}
inline void add(int k,int l,int r,int x){
	if(tree[k].l>r||tree[k].r<l) return;
	if(tree[k].l>=l&&tree[k].r<=r){
		tree[k].maxn += x;
		tree[k].sum += x*tree[k].len;
		tree[k].lazy_sum += x;
		return;
	}
	pushdown(k);
	add(k*2,l,r,x);
	add(k*2+1,l,r,x);
	pushup(k);
}
inline long long ask_max(int k,int l,int r){
	if(tree[k].l>r||tree[k].r<l) return -INF;
	if(tree[k].l>=l&&tree[k].r<=r){
		return tree[k].maxn;
	}
	pushdown(k);
	long long ans = max(ask_max(k*2,l,r),ask_max(k*2+1,l,r));
	pushup(k);
	return ans;
}
inline long long ask_sum(int k,int l,int r){
	if(tree[k].l>r||tree[k].r<l) return 0;
	if(tree[k].l>=l&&tree[k].r<=r){
		return tree[k].sum;
	}
	pushdown(k);
	long long ans = ask_sum(k*2,l,r)+ask_sum(k*2+1,l,r);
	pushup(k);
	return ans;
}
struct Edge{
	int to,w;
};
int fath[MAXN],son[MAXN];
int tid[MAXN],top[MAXN],maxnum[MAXN];
int dep[MAXN],sz[MAXN],sum_id;
vector<int> v[MAXN];
inline void dfs1(int k,int fa,int d){
	fath[k] = fa;dep[k] = d;sz[k] = 1;son[k] = 0;
	for(int i:v[k]){
		if(i==fa) continue;
		dfs1(i,k,d+1);
		sz[k] += sz[i];
		if(!son[k]) son[k] = i;
		else{
			if(sz[son[k]]<sz[i]) son[k] = i;
		}
	}
}
inline void dfs2(int k,int grand){
	tid[k] = ++sum_id;
	top[k] = grand;
	if(son[k]){
		dfs2(son[k],grand);
		for(int i:v[k]){
			if(i == fath[k]) continue;
			if(i == son[k]) continue;
			dfs2(i,i);
		}
	}
	maxnum[k] = sum_id;
}
inline void modify_chain(int u,int k){
	modify(1,tid[u],k);
}
inline void modify_chain(int u,int v,int k){
	while(top[u]!=top[v]){
		if(dep[top[u]]>dep[top[v]]){
			modify(1,tid[top[u]],tid[u],k);
			u = fath[top[u]];
		}else{
			modify(1,tid[top[v]],tid[v],k);
			v = fath[top[v]];
		}
	}
	if(dep[u]>dep[v]) swap(u,v);
	modify(1,tid[u],tid[v],k);
}
inline void add_chain(int u,int k){
	add(1,tid[u],k);
}
inline void add_chain(int u,int v,int k){
	while(top[u]!=top[v]){
		if(dep[top[u]]>dep[top[v]]){
			add(1,tid[top[u]],tid[u],k);
			u = fath[top[u]];
		}else{
			add(1,tid[top[v]],tid[v],k);
			v = fath[top[v]];
		}
	}
	if(dep[u]>dep[v]) swap(u,v);
	add(1,tid[u],tid[v],k);
}
inline long long max_chain(int u,int v){
	long long ans = -INF;
	while(top[u]!=top[v]){
		if(dep[top[u]]>dep[top[v]]){
			ans = max(ans,ask_max(1,tid[top[u]],tid[u]));
			u = fath[top[u]];
		}else{
			ans = max(ans,ask_max(1,tid[top[v]],tid[v]));
			v = fath[top[v]];
		}
	}
	if(dep[u]>dep[v]) swap(u,v);
	ans = max(ans,ask_max(1,tid[u],tid[v]));
	return ans;
}
inline long long sum_chain(int u,int v){
	long long ans = 0;
	while(top[u]!=top[v]){
		if(dep[top[u]]>dep[top[v]]){
			ans += ask_sum(1,tid[top[u]],tid[u]);
			u = fath[top[u]];
		}else{
			ans += ask_sum(1,tid[top[v]],tid[v]);
			v = fath[top[v]];
		}
	}
	if(dep[u]>dep[v]) swap(u,v);
	ans += ask_sum(1,tid[u],tid[v]);
	return ans;
}
struct node{
	int x,y,z;
}ppppp[MAXN];
inline void read(int &x){
	char now = '?';
	while(now!='-'&&!('0'<=now&&now<='9')) now = getchar();
	int alpha = 1;
	if(now=='-'){
		alpha = -1;
		now = getchar();
	}
	x = 0;
	while('0'<=now&&now<='9'){
		x*=10;x+=now-'0';
		now = getchar();
	}
	x*=alpha;
}
//Every Code's Different
inline void init(int n){
	dfs1(1,0,1);
	dfs2(1,1);
	build(1,1,n);
	for(int i = 1;i<=n;i++){
		modify(1,tid[i],w[i]);
	}
}
int ans[MAXN];
inline void ans1(int k){
	for(int i:v[k]){
		if(i==fath[k]) continue;
		ans1(i);
	}
	ans[1] += (dep[k]-1)*w[k];
}
inline void ans0(int k){
	if(k!=1){
		int sum = ask_sum(1,tid[k],maxnum[k]);
		ans[k] = ans[fath[k]]-sum+(ask_sum(1,tid[1],maxnum[1])-sum);
		ans[0] = min(ans[0],ans[k]);
	}
	for(int i:v[k]){
		if(i==fath[k]) continue;
		ans0(i);
	}
}
signed main(){
	read(n);
	for(int i = 1;i<n;i++){
		read(x);read(y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i = 1;i<=n;i++){
		scanf("%d",w+i);
	}
	init(n);
	ans[0] = 0x3f3f3f3f;
	ans1(1);
	ans0(1);
	printf("%d",ans[0]);
	return 0;
}
