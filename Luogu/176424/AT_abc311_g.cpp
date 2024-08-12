#include<bits/stdc++.h>
#define int long long
#define left _zqh_
#define right flying_hq
using namespace std;
const int MAXN = 320;
const int LOGN = log2(MAXN)+5;
int n,m,matrix[MAXN][MAXN],ans;
void read(int &x){
	x = 0;int p = 1;char ch;
	do{
		ch = getchar();
		if(ch=='-') p = -1;
	}while(!isdigit(ch));
	while(isdigit(ch)){
		x*=10;
		x+=ch-'0';
		ch = getchar();
	}
	x*=p;
}
int sum[MAXN][MAXN],now[MAXN],left[MAXN],right[MAXN],q[MAXN],minn[MAXN];
class Segmenttree{
	private:
		struct segment{
			int l,r,min=0X3F3F3F3F;
		}tree[MAXN<<3];
		void pushup(int id){
			tree[id].min = min(tree[id*2].min,tree[id*2+1].min);
		}
	public:
		void build(int k,int l,int r){
			tree[k].l = l;
			tree[k].r = r;
			if(l==r) return;
			int mid = (l+r)>>1;
			build(k*2,l,mid);
			build(k*2+1,mid+1,r);
		}
		void change(int k,int p,int q){
			if(tree[k].l>p||tree[k].r<p) return;
			if(tree[k].l>=p&&tree[k].r<=p){
				tree[k].min = q;
				return; 
			}
			change(k*2,p,q);
			change(k*2+1,p,q);
			pushup(k);
		}
		int getmin(int k,int l,int r){
			if(tree[k].l>r||tree[k].r<l) return 0x3f3f3f3f;
			if(tree[k].l>=l&&tree[k].r<=r){
				return tree[k].min; 
			}
			return min(getmin(k*2,l,r),getmin(k*2+1,l,r));
		}
}tree[MAXN];
signed main(){
	read(n);read(m);
	for(int i = 1;i<=m;i++) tree[i].build(1,1,n);
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			read(matrix[i][j]);
			sum[i][j] = sum[i-1][j]+matrix[i][j];
			tree[j].change(1,i,matrix[i][j]);
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			if(i == 1&&j== 2){
				int k = 0;
			}
			for(int k = 1;k<=m;k++){
				now[k] = sum[j][k]-sum[i-1][k];
				q[k] = q[k-1]+now[k];
				minn[k] = tree[k].getmin(1,i,j);
			}
			stack<pair<int,int>> st;
			for(int k = 1;k<=m;k++){
				while(!st.empty()&&st.top().second>=minn[k]) st.pop();
				if(st.empty()){
					left[k] = 1;
				}else{
					left[k] = st.top().first+1;
				}
				st.push({k,minn[k]});
			}
			while(!st.empty()){
				st.pop();
			}
			for(int k = m;k>=1;k--){
				while(!st.empty()&&st.top().second>=minn[k]) st.pop();
				if(st.empty()){
					right[k] = m;
				}else{
					right[k] = st.top().first-1;
				}
				st.push({k,minn[k]});
			}
			for(int k = 1;k<=m;k++){
				ans = max(ans,(q[right[k]]-q[left[k]-1])*minn[k]);
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
