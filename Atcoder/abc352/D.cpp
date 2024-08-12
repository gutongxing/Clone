#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 3e5+20;
const int INF = 0x3f3f3f3f3f3f3f3f;
int pos[MAXN];
class SegmentTree{
	private:
		struct Segmenttree{
			int l,r,len;int minn,maxn;
		}tree[MAXN<<3];
		bool is_son(int k){
			return (tree[k].l==tree[k].r);
		}
		void pushup(int k){
			if(is_son(k)) return;
			tree[k].minn = min(tree[k*2].minn,tree[k*2+1].minn);
			tree[k].maxn = max(tree[k*2].maxn,tree[k*2+1].maxn);
		}
	public:
		void build(int k,int l,int r){
			tree[k].l = l;tree[k].r = r;tree[k].len = r-l+1;
			if(l==r){
				tree[k].minn = tree[k].maxn = pos[l];
				return;
			}
			int mid = (l+r)>>1;
			build(k*2,l,mid);
			build(k*2+1,mid+1,r);
			pushup(k);
		}
		int maxn(int k,int l,int r){
			if(tree[k].l>r||tree[k].r<l) return 0;
			if(tree[k].l>=l&&tree[k].r<=r){
				return tree[k].maxn;
			}
			int ans = max(maxn(k*2,l,r),maxn(k*2+1,l,r));
			pushup(k);
			return ans;
		}
		int minn(int k,int l,int r){
			if(tree[k].l>r||tree[k].r<l) return INF;
			if(tree[k].l>=l&&tree[k].r<=r){
				return tree[k].minn;
			}
			int ans = min(minn(k*2,l,r),minn(k*2+1,l,r));
			pushup(k);
			return ans;
		}
}TREE;
int n,q,ans=INF,sumn,sumq,t[MAXN];
signed main(){
	memset(t,0x3f,sizeof(t));
	scanf("%lld%lld",&n,&q);
	for(int i = 1;i<=n;i++){
		int x;
		scanf("%lld",&x);
		pos[x] = i;
	}
	TREE.build(1,1,n);
	for(int i = 1;i<=n;i++){
		int r = i+q-1;if(r>n) break;
		int minn = TREE.minn(1,i,r);
		int maxn = TREE.maxn(1,i,r);
		ans = min(ans,maxn-minn);
	}
	printf("%lld",ans);
	return 0;
}
