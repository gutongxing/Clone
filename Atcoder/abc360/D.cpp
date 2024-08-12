#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+10;
int n,m,a[MAXN],x,y,op;
//Segment tree
#define l(x) tree[x].ls
#define r(x) tree[x].rs
#define maxn(x) tree[x].maxn
#define lazy(x) tree[x].lazy
int Segmentsum;
struct SegmentTree{
	int l,r,len,ls,rs,maxn;
	int lazy;
}tree[MAXN*8];
void build(int l,int r){
	Segmentsum++;
	tree[Segmentsum].l = l;
	tree[Segmentsum].r = r;
	tree[Segmentsum].len = r-l+1;
	tree[Segmentsum].maxn = 0;
}
void pushup(int x){
	if(tree[x].l==tree[x].r) return;
	maxn(x) = max(maxn(l(x)),maxn(r(x)));
}
void maketag(int x,int p){
	maxn(x) += p;
	lazy(x) += p;
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
	if(lazy(x)){
		maketag(l(x),lazy(x));
		maketag(r(x),lazy(x));
		lazy(x) = 0;
	}
}
void modify(int k,int l,int r,int y){
	if(tree[k].l>r||tree[k].r<l) return;
	if(tree[k].l>=l&&tree[k].r<=r){
		maxn(k) += y;
		return;
	}
	pushdown(k);
	modify(l(k),l,r,y);
	modify(r(k),l,r,y);
	pushup(k);
}
int get_max(int k,int l,int r){
	if(tree[k].l>r||tree[k].r<l) return 0;
	if(tree[k].l>=l&&tree[k].r<=r){
		return maxn(k);
	}
	pushdown(k);
	int ans = max(get_max(l(k),l,r),get_max(r(k),l,r));
	pushup(k);
	return ans;
}
signed main(){
//	freopen("P3369_7.in","r",stdin);
//	freopen("P3369_7.ans","w",stdout);
	scanf("%d",&n);
	build(0,1e9);
	
	return 0;
}
