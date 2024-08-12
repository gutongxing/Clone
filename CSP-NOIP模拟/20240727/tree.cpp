#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
namespace gtx{
//	Fast IO
	void read(int &x){
		x = 0;int h = 1;char tmp;
		do{tmp=getchar();if(tmp=='-')h*=-1;}while(!isdigit(tmp));
		while(isdigit(tmp)) x*=10,x+=tmp-'0',tmp=getchar();
		x*=h;
	}
	void read(char &x){do{x=getchar();}while(x==' '||x=='\n'||x=='\r');}
	void write(char x){putchar(x);}
	void write(int x){
		if(x<0) putchar('-'),x=-x;int st[200]={0},tot=0;
		do{st[++tot]=x%10,x/=10;} while(x);
		while(tot){putchar(st[tot--]+'0');};
	}
	void write(int x,char y){write(x);write(y);}
    const int MAXN = 2e6+10;
    int base[2][2],n,v[MAXN];
    int qpow[2][MAXN];
    struct node{
        int l,r,order0,rever0,order1,rever1,sz,rsz;
    }tree[MAXN];
    int ans = 0;
    void dfs(int k){
        if(k==0) return;
        dfs(tree[k].l);
        dfs(tree[k].r);
        tree[k].order0 = 1ll*tree[tree[k].l].order0*qpow[0][tree[tree[k].r].sz+1]%base[0][1];
        tree[k].order0 = (tree[k].order0+1ll*v[k]*qpow[0][tree[tree[k].r].sz]%base[0][1])%base[0][1];
        tree[k].order0 = (tree[k].order0+tree[tree[k].r].rever0)%base[0][1];
        tree[k].order1 = 1ll*tree[tree[k].l].order1*qpow[1][tree[tree[k].r].sz+1]%base[1][1];
        tree[k].order1 = (tree[k].order1+1ll*v[k]*qpow[1][tree[tree[k].r].sz]%base[1][1])%base[1][1];
        tree[k].order1 = (tree[k].order1+tree[tree[k].r].rever1)%base[1][1];
        tree[k].rever0 = 1ll*tree[tree[k].r].rever0*qpow[0][tree[tree[k].l].sz+1]%base[0][1];
        tree[k].rever0 = (tree[k].rever0+1ll*v[k]*qpow[0][tree[tree[k].l].sz]%base[0][1])%base[0][1];
        tree[k].rever0 = (tree[k].rever0+tree[tree[k].l].rever0)%base[0][1];
        tree[k].rever1 = 1ll*tree[tree[k].r].rever1*qpow[1][tree[tree[k].l].sz+1]%base[1][1];
        tree[k].rever1 = (tree[k].rever1+1ll*v[k]*qpow[1][tree[tree[k].l].sz]%base[1][1])%base[1][1];
        tree[k].rever1 = (tree[k].rever1+tree[tree[k].l].rever1)%base[1][1];
        tree[k].sz = tree[tree[k].l].sz+tree[tree[k].r].sz+1;
        tree[k].rsz = tree[tree[k].l].rsz+tree[tree[k].r].rsz+1;
        if(tree[tree[k].l].order0==tree[tree[k].r].rever0
         &&tree[tree[k].l].order1==tree[tree[k].r].rever1){
            ans = max(ans,tree[k].rsz);
        }
    }
	signed main(){
		base[0][0] = 103;
        base[0][1] = 100003;
        base[1][0] = 10007;
        base[1][1] = 10000003;
        tree[0].sz = 1;
        tree[0].order0 = 1030;
        tree[0].order1 = 1030;
        tree[0].rever0 = 1030;
        tree[0].rever1 = 1030;
        qpow[0][0] = qpow[1][0] = 1;
        for(int i = 1;i<=2000001;i++){
            qpow[0][i] = (1ll*qpow[0][i-1]*base[0][0])%base[0][1];
            qpow[1][i] = (1ll*qpow[1][i-1]*base[1][0])%base[1][1];
        }
        read(n);
        for(int i = 1;i<=n;i++){
            read(v[i]);
        }
        for(int i = 1;i<=n;i++){
            read(tree[i].l);read(tree[i].r);
            tree[i].l = max(tree[i].l,0);
            tree[i].r = max(tree[i].r,0);
        }
        dfs(1);
        write(ans);
		return 0;
	}
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T = 1;
//	gtx::read(T);
	while(T--) gtx::main();
	return 0;
}
