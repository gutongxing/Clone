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
}tree[MAXN<<5];
int tot;
void pushup(int k){
    tree[k].sum = tree[lson].sum+tree[rson].sum;
}
void change(int k,int p,int q){
    if(tree[k].l>p||tree[k].r<p) return;
    if(tree[k].l==p&&tree[k].r==p){
        tree[k].sum = q;
        return;
    }
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
int root[2*MAXN];
int n,m,a[MAXN];
void Build(int k,int l,int r){
    tree[k].l = l;
    tree[k].r = r;
    if(l==r){
        tree[k].sum = a[l];
        return;
    }
    int mid = (l+r)>>1;
    lson = ++tot;rson = ++tot;
    Build(lson,l,mid);
    Build(rson,mid+1,r);
}
int ask(int k,int p){
    if(tree[k].l>p||tree[k].r<p){
        return 0;
    }
    if(tree[k].l==p&&tree[k].r==p) return tree[k].sum;
    return ask(lson,p)+ask(rson,p);
}
signed main(){
    read(n);read(m);
    for(int i = 1;i<=n;i++){
        read(a[i]);
    }
    root[0] = 1;
    Build(++tot,1,n);
    for(int i = 1;i<=m;i++){
        root[i] = ++tot;
        int opt,version;
        read(version);read(opt);
        tree[root[i]] = tree[root[version]];
        if(opt==1){
            int x,y;
            read(x);read(y);
            change(root[i],x,y);
        }else{
            int x;
            read(x);
            write(ask(root[i],x));puts("");
        }
    }
    return 0;
}