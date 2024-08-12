#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 3e5+10;
class Segmenttree{
	private:
		struct segment{
			int l,r,tag,sum,maxn,maxpos;
		}tree[MAXN<<3];
		void pushup(int id){
			tree[id].sum = tree[id*2].sum + tree[id*2+1].sum;
			if(tree[id*2].maxn>tree[id*2+1].maxn){
				tree[id].maxn = tree[id*2].maxn;
				tree[id].maxpos = tree[id*2].maxpos;
			}else{
				tree[id].maxn = tree[id*2+1].maxn;
				tree[id].maxpos = tree[id*2+1].maxpos;
			}
		}
	public:
		void build(int k,int l,int r){
			tree[k].l = l;
			tree[k].r = r;
			if(l==r){
				tree[k].maxpos = l;
				return;
			}
			int mid = (l+r)>>1;
			build(k*2,l,mid);
			build(k*2+1,mid+1,r);
		}
		void change(int k,int p){
			if(tree[k].l>p||tree[k].r<p) return;
			if(tree[k].l>=p&&tree[k].r<=p){
				tree[k].tag = 1;
				tree[k].maxn = 0;
				tree[k].sum = 0;
				tree[k].maxpos = 0;
				return;
			}
			change(k*2,p);
			change(k*2+1,p);
			pushup(k);
		}
		void add(int k,int p,int q){
			if(tree[k].l>p||tree[k].r<p) return;
			if(tree[k].l>=p&&tree[k].r<=p){
				if(!tree[k].tag){
					tree[k].sum += q;
					tree[k].maxn += q;
				}
				return;
			}
			add(k*2,p,q);
			add(k*2+1,p,q);
			pushup(k);
		}
		void getmax(int &maxn,int &maxpos){
			maxn = tree[1].maxn;
			maxpos = tree[1].maxpos;
		}
		int all(){
			return tree[1].sum;
		}
}tree;
int n,m,h,p,q,ans[MAXN],cnt;
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
void write(int k){
	if(k<0) write('-');
	k = abs(k);
	stack<int> num;
	do{
		num.push(k%10);
		k/=10;
	}while(k);
	while(!num.empty()){
		putchar(num.top()+48);
		num.pop();
	}
}
signed main(){
	read(n);read(m);read(h);
	tree.build(1,1,m);
	for(int i = 1;i<=n;i++){
		int x,y;
		read(x);read(y);
		tree.add(1,y,x);
		while(tree.all()>h){
			ans[cnt++] = i-1;
			int maxn=0,maxpos;
			tree.getmax(maxn,maxpos);
			tree.change(1,maxpos);
		}
		printf("%d %d\n",cnt,tree.all());
	}
	for(int i = 0;i<cnt;i++){
		write(ans[i]);putchar(' ');
	}
	for(int i = cnt;i<=m;i++){
		write(n);putchar(' '); 
	}
	return 0;
}

