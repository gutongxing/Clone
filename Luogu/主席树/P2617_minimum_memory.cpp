#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
const int MAXM = 5e7+10;
#define lson ls[k]
#define rson rs[k]
int sum[MAXM],ls[MAXM],rs[MAXM];
int tot;
void pushup(int k){
    sum[k] = sum[lson]+sum[rson];
}
void copy(int x,int y){
    sum[x] = sum[y];
    ls[x] = ls[y];
    rs[x] = rs[y];
}
void change(int k,int p,int q,int l,int r){
    if(l>p||r<p) return;
    if(l==p&&r==p){
        sum[k] += q;
        return;
    }
    int mid = (l+r>>1);
    if(mid<p){
        ++tot;
        copy(tot,rson);
        rson = tot;
        change(rson,p,q,mid+1,r);
    }else{
        ++tot;
        copy(tot,lson);
        lson = tot;
        change(lson,p,q,l,mid);
    }
    pushup(k);
}
int lowbit(int k){
    return k&(-k);
}
int get(int k){
    return sum[k];
}
vector<int> xroot,yroot;
int kth(int c,int l,int r){
    int sum1 = 0,sum2 = 0,lst = 0;
    for(int i:xroot){
        if(!ls[i]) ls[i] = ++tot;
        sum1 += get(ls[i]);
		lst = i;
    }
    for(int i:yroot){
        if(!ls[i]) ls[i] = ++tot;
        sum2 += get(ls[i]);
		lst = i;
    }
    if(l == r) return l;
    int mid = (l+r)>>1;
    if(sum2-sum1<c){
		for(int i = 0;i<xroot.size();i++) xroot[i] = rs[xroot[i]];
		for(int i = 0;i<yroot.size();i++) yroot[i] = rs[yroot[i]];
        return kth(c+sum1-sum2,mid+1,r);
    }else{
		for(int i = 0;i<xroot.size();i++) xroot[i] = ls[xroot[i]];
		for(int i = 0;i<yroot.size();i++) yroot[i] = ls[yroot[i]];
		return kth(c,l,mid);
	}
}
int root[MAXN];
int n,m,a[MAXN];
struct question{
    char tmp;
    int l,r,k;
}q[MAXN];
int v[MAXN<<2],lsh;
int to(int k){
    return lower_bound(v,v+lsh,k)-v;
}
signed main(){
    // freopen("P2617_11.in","r",stdin);
//     freopen("P2617_11.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%d",a+i);
        v[lsh++] = (a[i]);
    }
    for(int i = 1;i<=m;i++){
        char tmp[2];
        scanf("%s",tmp);
        int l,r,k;
        scanf("%d%d",&l,&r);
        switch(tmp[0]){
        case 'Q':{
            scanf("%d",&k);
            break;
        }
        case 'C':{
            v[lsh++] = r;
        }
        }
        q[i].tmp = tmp[0];
        q[i].l = l;
        q[i].r = r;
        q[i].k = k;
    }
    sort(v,v+lsh);
    unique(v,v+lsh);
    root[0] = ++tot;
    for(int i = 1;i<=n;i++){
        root[i] = ++tot;
        copy(root[i],root[i-1]);
    }
    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j+=lowbit(j)) change(root[j],to(a[i]),1,0,lsh-1);
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
            printf("%d",(v[kth(k,0,lsh-1)]));puts("");
            break;
        }
        case 'C':{
			if(i==58031){
				int x =0 ;
			}
            for(int j = l;j<=n;j+=lowbit(j)){
                change(root[j],to(r),1,0,lsh-1);
				change(root[j],to(a[l]),-1,0,lsh-1);
            }
			a[l] = r;
        }
        }
    }
	int x = 0;
    return 0;
}
