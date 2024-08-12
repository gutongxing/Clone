                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
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
    const int A = 2011111;
    const int B = 19491001;
    const int C = 1939901;
    const int D = 6600211;
    int base[3][3],n,v[MAXN];
    int qpow[3][MAXN];
    struct node{
        int l,r,rsz;
        int order0,rever0;
        int order1,rever1;
        int order2,rever2;
        int order3,rever3;
    }tree[MAXN];
    int ans = 0;
    void dfs(int k){
        if(k==0) return;
        dfs(tree[k].l);
        dfs(tree[k].r);
        // tree[k].order0 = 1ll*tree[tree[k].l].order0*qpow[0][tree[tree[k].r].sz+1]%base[0][1];
        // tree[k].order1 = 1ll*tree[tree[k].l].order1*qpow[1][tree[tree[k].r].sz+1]%base[1][1];
        // tree[k].order2 = 1ll*tree[tree[k].l].order2*qpow[2][tree[tree[k].r].sz+1]%base[2][1];
        // tree[k].rever0 = 1ll*tree[tree[k].r].rever0*qpow[0][tree[tree[k].l].sz+1]%base[0][1];
        // tree[k].rever1 = 1ll*tree[tree[k].r].rever1*qpow[1][tree[tree[k].l].sz+1]%base[1][1];
        // tree[k].rever2 = 1ll*tree[tree[k].r].rever2*qpow[2][tree[tree[k].l].sz+1]%base[2][1];
        // tree[k].order0 = (tree[k].order0+1ll*v[k]*qpow[0][tree[tree[k].r].sz]%base[0][1])%base[0][1];
        // tree[k].order1 = (tree[k].order1+1ll*v[k]*qpow[1][tree[tree[k].r].sz]%base[1][1])%base[1][1];
        // tree[k].order2 = (tree[k].order2+1ll*v[k]*qpow[2][tree[tree[k].r].sz]%base[2][1])%base[2][1];
        // tree[k].rever0 = (tree[k].rever0+1ll*v[k]*qpow[0][tree[tree[k].l].sz]%base[0][1])%base[0][1];
        // tree[k].rever1 = (tree[k].rever1+1ll*v[k]*qpow[1][tree[tree[k].l].sz]%base[1][1])%base[1][1];
        // tree[k].rever2 = (tree[k].rever2+1ll*v[k]*qpow[2][tree[tree[k].l].sz]%base[2][1])%base[2][1];
        // tree[k].order0 = (tree[k].order0+tree[tree[k].r].rever0)%base[0][1];
        // tree[k].order1 = (tree[k].order1+tree[tree[k].r].rever1)%base[1][1];
        // tree[k].order2 = (tree[k].order2+tree[tree[k].r].rever2)%base[2][1];
        // tree[k].rever0 = (tree[k].rever0+tree[tree[k].l].rever0)%base[0][1];
        // tree[k].rever1 = (tree[k].rever1+tree[tree[k].l].rever1)%base[1][1];
        // tree[k].rever2 = (tree[k].rever2+tree[tree[k].l].rever2)%base[2][1];
        // tree[k].sz = tree[tree[k].l].sz+tree[tree[k].r].sz+1;
        // tree[k].rsz = tree[tree[k].l].rsz+tree[tree[k].r].rsz+1;
        tree[k].order0 = (((tree[tree[k].l].order0*9997087)%9999397+v[k]*9996157)%9999397+(tree[tree[k].r].order0*9995597)%9999397)%9999397;
        tree[k].rever0 = (((tree[tree[k].r].rever0*9997087)%9999397+v[k]*9996157)%9999397+(tree[tree[k].l].rever0*9995597)%9999397)%9999397;
        tree[k].order1 = (((tree[tree[k].l].order1*9996703)%9999991+v[k]*9996073)%9999991+(tree[tree[k].r].order1*9995599)%9999991)%9999991;
        tree[k].rever1 = (((tree[tree[k].r].rever1*9996703)%9999991+v[k]*9996073)%9999991+(tree[tree[k].l].rever1*9995599)%9999991)%9999991;
        tree[k].order2 = (((tree[tree[k].l].order2*9996673)%9999593+v[k]*9995717)%9999593+(tree[tree[k].r].order2*9995549)%9999593)%9999593;
        tree[k].rever2 = (((tree[tree[k].r].rever2*9996673)%9999593+v[k]*9995717)%9999593+(tree[tree[k].l].rever2*9995549)%9999593)%9999593;
        tree[k].order3 = (((tree[tree[k].l].order3*9996373)%9998633+v[k]*9995581)%9998633+(tree[tree[k].r].order3*9995483)%9998633)%9998633;
        tree[k].rever3 = (((tree[tree[k].r].rever3*9996373)%9998633+v[k]*9995581)%9998633+(tree[tree[k].l].rever3*9995483)%9998633)%9998633;
        tree[k].rsz = tree[tree[k].l].rsz+tree[tree[k].r].rsz+1;
        if(tree[tree[k].l].order0==tree[tree[k].r].rever0&&
        tree[tree[k].l].order1==tree[tree[k].r].rever1&&
        tree[tree[k].l].order2==tree[tree[k].r].rever2&&
        tree[tree[k].l].order3==tree[tree[k].r].rever3&&
        tree[tree[k].l].rsz==tree[tree[k].r].rsz){
            ans = max(ans,tree[k].rsz);
        }
    }
	signed main(){
        tree[0].order0 = 998617;
        tree[0].rever0 = 998617;
        tree[0].order1 = 998749;
        tree[0].rever1 = 998749;
        tree[0].order2 = 997589;
        tree[0].rever2 = 997589;
        tree[0].order3 = 101;
        tree[0].rever3 = 101;
        // tree[0].rsz = 1;
        read(n);
        for(int i = 1;i<=n;i++){
            read(v[i]);
        }
        for(int i = 1;i<=n;i++){
            read(tree[i].l);read(tree[i].r);
            tree[i].l = max(tree[i].l,0ll);
            tree[i].r = max(tree[i].r,0ll);
        }
        dfs(1);
        write(ans);
		return 0;
	}
}
signed main(){
	freopen("P5018_17.in","r",stdin);
	// freopen("tree.in","r",stdin);
	// freopen("tree.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T = 1;
//	gtx::read(T);
	while(T--) gtx::main();
	return 0;
}