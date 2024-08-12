#include<bits/stdc++.h>
#pragma G++ optimize(3)
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
void read(char &x){
    x = getchar();
    while(x==' '||x=='\n'||x=='\r') x = getchar();
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
const int MAXN = 3e5+10;
#define lson tree[k].ls
#define rson tree[k].rs
struct Segmenttree{
    int l,r,sum;
    int ls,rs;
}tree[(int)(MAXN*88.5)];
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
        tree[k].sum += q;
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
int lowbit(int k){
    return k&(-k);
}
int get(int k){
    return tree[k].sum;
}
vector<int> xroot,yroot;
int kth(int c){
    int sum1 = 0,sum2 = 0,lst = 0;
    for(int i:xroot){
        pushdown(i);
        sum1 += get(tree[i].ls);
		lst = i;
    }
    for(int i:yroot){
        pushdown(i);
        sum2 += get(tree[i].ls);
		lst = i;
    }
    if(tree[lst].l == tree[lst].r) return tree[lst].r;
    if(sum2-sum1<c){
		for(int i = 0;i<xroot.size();i++) xroot[i] = tree[xroot[i]].rs;
		for(int i = 0;i<yroot.size();i++) yroot[i] = tree[yroot[i]].rs;
        return kth(c+sum1-sum2);
    }else{
		for(int i = 0;i<xroot.size();i++) xroot[i] = tree[xroot[i]].ls;
		for(int i = 0;i<yroot.size();i++) yroot[i] = tree[yroot[i]].ls;
		return kth(c);
	}
}
int root[MAXN];
int n,m,a[MAXN];
struct question{
    char tmp;
    int l,r,k;
}q[MAXN];
vector<int> v;
int to(int k){
    return lower_bound(v.begin(),v.end(),k)-v.begin();
}
signed main(){
    // freopen("P2617_11.in","r",stdin);
    // freopen("P2617_11.out","w",stdout);
    read(n);read(m);
    for(int i = 1;i<=n;i++){
        read(a[i]);
        v.push_back(a[i]);
    }
    for(int i = 1;i<=m;i++){
        char tmp;
        read(tmp);
        int l,r,k;
        read(l);read(r);
        switch(tmp){
        case 'Q':{
            read(k);
            break;
        }
        case 'C':{
            v.push_back(r);
        }
        }
        q[i].tmp = tmp;
        q[i].l = l;
        q[i].r = r;
        q[i].k = k;
    }   
    sort(v.begin(),v.end());
    unique(v.begin(),v.end());
    root[0] = 1;
    tree[1].l = 0;
    tree[1].r = v.size()-1;tot++;
    for(int i = 1;i<=n;i++){
        root[i] = ++tot;
        tree[root[i]] = tree[root[i-1]];
    }
    for(int i = 1;i<=n;i++){
        root[i] = ++tot;
        tree[root[i]] = tree[root[i-1]];
    }
    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j+=lowbit(j)) change(root[j],to(a[i]),1);
    }
    for(int i = 1;i<=m;i++){
        char tmp;
        tmp = q[i].tmp;
        int l,r,k;
        l = q[i].l;r = q[i].r;k = q[i].k;
        switch(tmp){
        case 'Q':{
            xroot.clear();
            yroot.clear();
            for(int j = l-1;j;j-=lowbit(j)) xroot.push_back(root[j]);
            for(int j = r;j;j-=lowbit(j)) yroot.push_back(root[j]);
            cout<<(v[kth(k)]);puts("");
            break;
        }
        case 'C':{
            for(int j = l;j<=n;j+=lowbit(j)){
                change(root[j],to(r),1);
				change(root[j],to(a[l]),-1);
            }
			a[l] = r;
        }

        }
    }
    return 0;
}