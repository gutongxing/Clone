#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6+10;
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
int n,m;
struct order1{
	int x,id;
}o1[MAXN];
bool cmp_order1(order1 a,order1 b){
	return a.x==b.x?a.id<b.id:a.x<b.x;
}
int sum_order2;
struct order2{
	bool que;
	int id;
	int x,y;
}o2[MAXN];
bool cmp_order2(order2 a,order2 b){
	return a.x==b.x?(a.y==b.y?a.que<b.que:a.y<b.y):a.x>b.x;
}
class SegmentTree{
	private:
		struct segmentree{
			int l,r,maxn;
		}tree[MAXN<<3];
		void pushup(int id){
			tree[id].maxn = max(tree[id*2].maxn,tree[id*2+1].maxn);
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
		void change(int k,int x,int y){
			if(tree[k].l>x||tree[k].r<x) return;
			if(tree[k].l>=x&&tree[k].r<=x){
				tree[k].maxn = y;
				return;
			}
			change(k*2,x,y);
			change(k*2+1,x,y);
			pushup(k);
		}
		int maxn(int k,int x,int y){
			if(tree[k].l>y||tree[k].r<x) return 0;
			if(tree[k].l>=x&&tree[k].r<=y){
				return tree[k].maxn;
			}
			return max(maxn(k*2,x,y),maxn(k*2+1,x,y));
		}
}seg;
class BIT{
	private:
		int lowbit(int k){
			return k&(-k);
		}
		int c[MAXN];
	public:
		void add(int x,int y){
			for(int i = x;i<MAXN;i+=lowbit(i)){
				c[i]+=y;
			}
		}
		int ask(int x){
			int res = 0;
			for(int i = x;i;i-=lowbit(i)){
				res += c[i];
			}
			return res;
		}
		int ask(int l,int r){
			return ask(r)-ask(l-1); 
		}
}bit;
int lst[MAXN];
int ans[MAXN];
signed main(){
	read(n);read(m);
	for(int i = 1;i<=n;i++){
		int x;
		read(x);
		o1[i].x = x;
		o1[i].id = i;
	}
	sort(o1+1,o1+1+n,cmp_order1);
	seg.build(1,1,n);
	for(int i = 1;i<=n;i++){
		int p = seg.maxn(1,lst[o1[i].x]+1,o1[i].id);
		seg.change(1,o1[i].id,o1[i].x);
		if(!lst[o1[i].x]){
			++sum_order2;
			o2[sum_order2].x = o1[i].x;
			o2[sum_order2].y = o1[i].x;
			o2[sum_order2].id = o1[i].id;
		}else if(p){
			++sum_order2;
			o2[sum_order2].x = p;
			o2[sum_order2].y = o1[i].x;
			o2[sum_order2].id = o1[i].id;
		}
		lst[o1[i].x] = o1[i].id;
	}
	for(int i = 1;i<=m;i++){
		int x,y;
		read(x);read(y);
		++sum_order2;
		o2[sum_order2].x = x;
		o2[sum_order2].y = y;
		o2[sum_order2].id = i;
		o2[sum_order2].que = 1;
	}
	sort(o2+1,o2+1+sum_order2,cmp_order2);
	for(int i = 1;i<=sum_order2;i++){
		if(o2[i].que){
			ans[o2[i].id] = bit.ask(o2[i].y);
		}else bit.add(o2[i].y,1);
	}
	for(int i = 1;i<=m;i++){
		write(ans[i]);
		puts("");
	}
	return 0;
}
