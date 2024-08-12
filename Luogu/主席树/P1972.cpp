#include<bits/stdc++.h>
#define int long long
using namespace std;
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
	if(k<0) putchar('-');
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
const int MAXN = 1e6+10;
#define lson tree[k].ls
#define rson tree[k].rs
struct Segmentree{
    int l,r,sum;
    int ls,rs;
}tree[MAXN*30];
int tot;
void pushup(int k){
    tree[k].sum = tree[lson].sum+tree[rson].sum;
}
void pushdown(int k){
    int l = tree[k].l;
    int r = tree[k].r;
    int mid = (l+r)>>1;
    if(!lson){
        lson = ++tot;
        tree[tot].l = l;
        tree[tot].r = mid;
    }
    if(!rson){
        rson = ++tot;
        tree[tot].l = mid+1;
        tree[tot].r = r;
    }
}

void change(int k,int p,int q){
    if(tree[k].l>p||tree[k].r<p) return;
    if(tree[k].l==p&&tree[k].r==p){
        tree[k].sum = q;
        return;
    }
    pushdown(k);
    if(tree[lson].r<p){
        ++tot;
        tree[tot] = tree[rson];
        rson = tot;
        change(rson,p,q);
    }else{
        ++tot;
        tree[tot] = tree[lson];
        lson = tot;
        change(lson,p,q);
    }
    pushup(k);
}
int get(int k){
    return tree[k].sum;
}
int kth(int xroot,int yroot,int c){
    pushdown(xroot);pushdown(yroot);
    if(tree[xroot].l==tree[xroot].r) return tree[xroot].l;
    if(get(tree[yroot].ls)-get(tree[xroot].ls)<c){
        return kth(tree[xroot].rs,tree[yroot].rs,c-get(tree[yroot].ls)+get(tree[xroot].ls));
    }else return kth(tree[xroot].ls,tree[yroot].ls,c);
}
int root[2*MAXN];
int n,m,a[MAXN];
signed main(){
    read(n);
    root[0] = 1;
    tree[1].l = 1;
    tree[1].r = 1e6;tot++;
    for(int i = 1;i<=n;i++){
        read(a[i]);
        root[i] = ++tot;
        tree[root[i]] = tree[root[i-1]];
        change(root[i],a[i],1);
    }
    read(m);
    for(int i = 1;i<=m;i++){
        int l,r,k;
        read(l);read(r);
        write(get(root[r])-get(root[l-1]));puts("");
    }
    return 0;
}