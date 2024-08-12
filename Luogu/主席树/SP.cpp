#include<bits/stdc++.h>
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
vector<int> v[500010];
int n,m,a[500010];
//LCA
int LCA_ST[500010][30],LCA_dep[500010];
void LCA_init(int k,int dep,int fath){
    LCA_ST[k][0] = fath;
    LCA_dep[k] = dep;
    for(int pppp=0;pppp<(int)v[k].size();pppp++){
        int i = v[k][pppp];
        if(i==fath) continue;
        LCA_init(i,dep+1,k);
    }
}
void LST_ST_init(){
    for(int j = 1;j<30;j++){
        for(int i = 1;i<=n;i++){
            LCA_ST[i][j] = LCA_ST[LCA_ST[i][j-1]][j-1];
        }
    }
}
int LCA_jump(int k,int dep){
    int tmp = 0;
    while(dep){
        if(dep&1){
            k = LCA_ST[k][tmp];
        }
        tmp++;
        dep>>=1;
    }
    return k;
}
int LCA(int x,int y){
    if(LCA_dep[x]<LCA_dep[y]) swap(x,y);
    x = LCA_jump(x,LCA_dep[x]-LCA_dep[y]);
    if(x==y) return x;
    for(int i = 30-1;i>=0;i--){
        if(LCA_ST[x][i]!=LCA_ST[y][i]){
            x = LCA_ST[x][i];
            y = LCA_ST[y][i];
        }
    }
    return LCA_ST[x][0];
}
#define lson tree[k].ls
#define rson tree[k].rs
struct Segmentree{
    int l,r,sum;
    int ls,rs;
}tree[80000000];
int tot;
void pushup(int k){
    tree[k].sum = tree[lson].sum+tree[rson].sum;
}
void change(int k,int p,int q){
    if(tree[k].l>p||tree[k].r<p) return;
    if(tree[k].l==p&&tree[k].r==p){
        tree[k].sum += q;
        return;
    }
    if(((tree[k].l+tree[k].r)>>1)<p){
        ++tot;
        tree[tot] = tree[rson];
        rson = tot;
		tree[rson].l = ((tree[k].l+tree[k].r)>>1)+1;
		tree[rson].r = tree[k].r;
        change(rson,p,q);
    }else{
        ++tot;
        tree[tot] = tree[lson];
        lson = tot;
		tree[lson].l = tree[k].l;
		tree[lson].r = (tree[k].l+tree[k].r)>>1;
        change(lson,p,q);
    }
    pushup(k);
}
int get(int k){
    return tree[k].sum;
}
int kth(int xroot,int yroot,int lcaroot,int fathroot,int c,int l,int r){
    if(l==r) return l;
    int tmp = get(tree[xroot].ls)+get(tree[yroot].ls)-get(tree[lcaroot].ls)-get(tree[fathroot].ls);
    if(tmp<c){
        return kth(tree[xroot].rs,tree[yroot].rs,tree[lcaroot].rs,tree[fathroot].rs,c-tmp,((l+r)>>1)+1,r);
    }else return kth(tree[xroot].ls,tree[yroot].ls,tree[lcaroot].ls,tree[fathroot].ls,c,l,(l+r)>>1);
}
int root[500010];
struct question{
    int u,v,k;
}q[500010];
vector<int> lsh;
int to(int k){
    return lower_bound(lsh.begin(),lsh.end(),k)-lsh.begin();
}
void dfs(int k,int fath){
    root[k] = ++tot;
    tree[root[k]] = tree[root[fath]];
    change(root[k],a[k],1);
    for(int pppp=0;pppp<(int)v[k].size();pppp++){
        int i = v[k][pppp];
        if(i==fath) continue;
        dfs(i,k);
    }
}
signed main(){
    read(n);read(m);
    for(int i = 1;i<=n;i++){
        read(a[i]);
        lsh.push_back(a[i]);
    }
    for(int i = 1;i<n;i++){
        int x,y;
        read(x);read(y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    sort(lsh.begin(),lsh.end());
    unique(lsh.begin(),lsh.end());
	for(int i = 1;i<=n;i++) a[i] = to(a[i]);
    root[0] = ++tot;
    tree[root[0]].l = 0;
    tree[root[0]].r = 1e5+10;
    LCA_init(1,0,0);
    LST_ST_init();
    dfs(1,0);
	int lst = 0;
    for(int i = 1;i<=m;i++){
        read(q[i].u);read(q[i].v);read(q[i].k);q[i].u^=lst;
        int lca = LCA(q[i].u,q[i].v);
        write(lst = lsh[kth(root[q[i].u],root[q[i].v],root[lca],root[LCA_ST[lca][0]],q[i].k,0,1e5+10)]);putchar('\n');
    }
    return 0;
}