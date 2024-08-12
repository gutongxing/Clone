#include<bits/stdc++.h>
#define int long long
using namespace std;
//Fast IO
void read(int &n){
	n = 0;int k = 1;
	char tmp;
	do{tmp = getchar();}while(!(tmp=='-'||isdigit(tmp)));
	if(tmp=='-'){k = -1;tmp=getchar();}
	while(isdigit(tmp)){n*=10;n+=tmp-'0';tmp=getchar();};
}
void write(int n){
	if(n<0) putchar('-');
	n = abs(n);
	stack<int> s;
	while(n) s.push(n%10),n/=10;
	while(!s.empty()) putchar(s.top()+'0'),s.pop(); 
}
const int MAXN = 1e5+10;
int n;
struct segmenttree{
	int l,r,len,maxn,maxpos;
	int lazy_tag;
}tree[MAXN<<3];
int a[MAXN],b[MAXN];
void maketag_lazy(int k,int x){
	tree[k].lazy_tag += x;
	tree[k].maxn -= x;
}
void pushdown(int k){
	if(tree[k].lazy_tag){
		maketag_lazy(k*2,tree[k].lazy_tag);
		maketag_lazy(k*2+1,tree[k].lazy_tag);
		tree[k].lazy_tag = 0;
	}
}
void pushup(int k){
	if(tree[k*2].maxn>=tree[k*2+1].maxn){
		tree[k].maxn = tree[k*2].maxn;
		tree[k].maxpos = tree[k*2].maxpos;
	}else{
		tree[k].maxn = tree[k*2+1].maxn;
		tree[k].maxpos = tree[k*2+1].maxpos;
	}
}
void build(int k,int l,int r){
	tree[k].l = l;
	tree[k].r = r;
	tree[k].len = r-l+1;
	if(l==r){
		tree[k].maxn = 2*a[l]+b[l];
		tree[k].maxpos = l;
		return;
	}
	int mid = (l+r)>>1;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	pushup(k);
}
void modify_m(int k,int l,int r,int p){
	if(l>r) return;
	if(tree[k].l>r||tree[k].r<l) return;
	if(tree[k].l>=l&&tree[k].r<=r){
		maketag_lazy(k,p);
		return;
	}
	pushdown(k);
	modify_m(k*2,l,r,p);
	modify_m(k*2+1,l,r,p); 
	pushup(k);
}
void modify_m(int k,int l,int p){
	if(tree[k].l>l||tree[k].r<l) return;
	if(tree[k].l>=l&&tree[k].r<=l){
		tree[k].maxn = min(tree[k].maxn,p);
		return;
	}
	pushdown(k);
	modify_m(k*2,l,p);
	modify_m(k*2+1,l,p); 
	pushup(k);
}
int ans = 0,lst = 1;
signed main(){
//	freopen("solder.in","r",stdin);
//	freopen("solder.out","w",stdout);
	read(n);
	for(int i = 1;i<=n;i++){
		read(a[i]);
	}
	for(int i = 1;i<=n;i++){
		read(b[i]);
	}
	build(1,1,n);
	for(int i = 1;i<=n;i++){
		ans += tree[1].maxn;
		int tmp = tree[1].maxpos;
		int t = tree[1].maxn-b[tmp];
		while(lst<tmp){
			modify_m(1,lst,b[lst]);
			lst++;
		}
		modify_m(1,tmp,n,t);
		modify_m(1,tmp,0);
		write(ans);putchar('\n');
	}
	return 0;
}

