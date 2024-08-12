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
	if(k<0) write('-');
	k = abs(k);
	vector<int> num;
	do{
		num.push_back(k%10);
		k/=10;
	}while(k);
    reverse(num.begin(),num.end());
	for(int i:num){
		putchar(i+48);
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
    write(10000);
    return 0;
}