#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e5+10;
int n,m;
//Segment tree
#define l(x) tree[x].ls
#define r(x) tree[x].rs
#define sum(x) tree[x].sum
int Segmentsum;
struct SegmentTree{
	int l,r,len,ls,rs,sum,maxpos=INT_MIN,minpos=INT_MAX;
}tree[MAXN*8];
void build(int l,int r){
	Segmentsum++;
	tree[Segmentsum].l = l;
	tree[Segmentsum].r = r;
	tree[Segmentsum].len = r-l+1;
	tree[Segmentsum].sum = 0;
}
void pushup(int x){
	if(tree[x].l==tree[x].r) return;
	sum(x) = sum(l(x))+sum(r(x));
	tree[x].maxpos=max(tree[l(x)].maxpos,tree[r(x)].maxpos);
	tree[x].minpos=min(tree[l(x)].minpos,tree[r(x)].minpos);
}
void pushdown(int x){
	if(tree[x].l==tree[x].r) return;
	int mid = (tree[x].l+tree[x].r)>>1;
	if(!l(x)){
		build(tree[x].l,mid);
		l(x) = Segmentsum;
	}
	if(!r(x)){
		build(mid+1,tree[x].r);
		r(x) = Segmentsum;
	}
}
void modify(int k,int x,int y){
	if(tree[k].l>x||tree[k].r<x) return;
	if(tree[k].l==x&&tree[k].r==x){
		tree[k].sum += y;
		return;
	}
	pushdown(k);
	modify(l(k),x,y);
	modify(r(k),x,y);
	pushup(k);
}
int ask(int k,int l,int r){
	if(tree[k].l>r||tree[k].r<l) return 0;
	if(tree[k].l>=l&&tree[k].r<=r){
		return sum(k);
	}
	pushdown(k);
	int ans = ask(l(k),l,r)+ask(r(k),l,r);
	pushup(k);
	return ans;
}
char a[MAXN];
int op[MAXN];
signed main(){
	scanf("%lld%lld",&n,&m);
	build(-1e9,1e9);
	scanf("%s",a+1);
	for(int i = 1;i<=n;i++){
		scanf("%lld",&op[i]);
		if(a[i]=='1'){
			modify(1,op[i],1);
		}
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		if(a[i]=='0'){
			ans += ask(1,max(-1000000000ll,op[i]-2*m),op[i]);
		}
	}
	cout << ans;
	return 0;
}
