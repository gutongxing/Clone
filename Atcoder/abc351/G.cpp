#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 4e5+10;
const int MOD = 998244353;
int n,m,a[MAXN],x,ans,y,op;
//Segment tree
#define l(x) tree[x].ls
#define r(x) tree[x].rs
#define sum1(x) tree[x].sum1
#define sum2(x) tree[x].sum2
class SegmentTree{
	private:
		struct Segmenttree{
			int l,r,len,sum,times;
		}tree[MAXN<<3];
		bool is_son(int k){
			return tree[k].l == tree[k].r;
		}
		void pushup(int k){
			if(is_son(k)) return;
			tree[k].sum = tree[k*2].sum+tree[k*2+1].sum;
			tree[k].times = tree[k*2].times*tree[k*2+1].times%MOD;
		}
	public:
		void build(int k,int l,int r){
			tree[k].l = l;tree[k].r = r;
			tree[k].len = r-l+1;tree[k].times = 0;
			if(l==r){
				if(l==1||r==n) tree[k].sum = 0;
				else tree[k].sum = v[1]*(n-l);
				return;
			}
			int mid = (l+r)>>1;
			build(k*2,l,mid);
			build(k*2+1,mid+1,r);
			pushup(k);
		}
		void add(int k,int x,int val){
			if(tree[k].l>x||tree[k].r<x) return;
			if(tree[k].l>=x&&tree[k].r<=x){
				tree[k].times
				return;
			}
			pushdown(k);
			add(k*2,l,r,val);
			add(k*2+1,l,r,val);
			pushup(k);
		}
		void times(int k,int l,int r,int div,int time){
			if(tree[k].l>r||tree[k].r<l) return;
			if(tree[k].l>=l&&tree[k].r<=r){
				make_tag2(k,div,time);
				return;
			}
			pushdown(k);
			times(k*2,l,r,div,time);
			times(k*2+1,l,r,div,time);
			pushup(k);
		}
		void reset(int k,int x){
			if(tree[k].l>x||tree[k].r<x) return;
			if(tree[k].l==x&&tree[k].r==x){
				tree[k].sum = 0;
				return;
			}
			pushdown(k);
			reset(k*2,x);
			reset(k*2+1,x);
			pushup(k);
		}
		int ask(int k,int l,int r){
			if(tree[k].l>r||tree[k].r<l) return 0;
			if(tree[k].l>=l&&tree[k].r<=r){
				return tree[k].sum;
			}
			pushdown(k);
			int ans = ask(k*2,l,r)+ask(k*2+1,l,r);
			pushup(k);
			return ans;
		}
}t;
	
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
