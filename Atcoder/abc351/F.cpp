#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 4e5+10;
int n,m,a[MAXN],x,ans,y,op;
//Segment tree
#define l(x) tree[x].ls
#define r(x) tree[x].rs
#define sum1(x) tree[x].sum1
#define sum2(x) tree[x].sum2
struct seg{
	int Segmentsum;
	struct SegmentTree{
		int l,r,len,ls,rs,sum1,sum2;
	}tree[MAXN*8];
	void build(int l,int r){
		Segmentsum++;
		tree[Segmentsum].l = l;
		tree[Segmentsum].r = r;
		tree[Segmentsum].len = r-l+1;
		tree[Segmentsum].sum1 = 0;
		tree[Segmentsum].sum2 = 0;
	}
	void pushup(int x){
		if(tree[x].l==tree[x].r) return;
		sum1(x) = sum1(l(x))+sum1(r(x));
		sum2(x) = sum2(l(x))+sum2(r(x));
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
	void modify(int k,int x){
		if(tree[k].l>x||tree[k].r<x) return;
		if(tree[k].l==x&&tree[k].r==x){
			tree[k].sum1 += x;
			tree[k].sum2 += 1;
			return;
		}
		pushdown(k);
		modify(l(k),x);
		modify(r(k),x);
		pushup(k);
	}
	__int128 ask1(int k,int l,int r){
		if(tree[k].l>r||tree[k].r<l) return 0;
		if(tree[k].l>=l&&tree[k].r<=r){
			return tree[k].sum1;
		}
		pushdown(k);
		__int128 ans = ask1(l(k),l,r)+ask1(r(k),l,r);
		pushup(k);
		return ans;
	}
	__int128 ask2(int k,int l,int r){
		if(tree[k].l>r||tree[k].r<l) return 0;
		if(tree[k].l>=l&&tree[k].r<=r){
			return tree[k].sum2;
		}
		pushdown(k);
		__int128 ans = ask2(l(k),l,r)+ask2(r(k),l,r);
		pushup(k);
		return ans;
	}
}t1,t2;
	
signed main(){
	scanf("%lld",&n);
	t1.build(-0,1e8);
	t2.build(-0,1e8);
	for(int i = 1;i<=n;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
		ans += x*t1.ask2(1,0,x-1)-t1.ask1(1,0,x-1);
		ans -= x*t1.ask2(1,x+1,1e8)-t1.ask1(1,x+1,1e8);
		ans += y*t2.ask2(1,0,y-1)-t2.ask1(1,0,y-1);
		ans -= y*t2.ask2(1,y+1,1e8)-t2.ask1(1,y+1,1e8);
		t1.modify(1,x);
		t2.modify(1,y);
	}
	printf("%lld",ans);
	return 0;
}
