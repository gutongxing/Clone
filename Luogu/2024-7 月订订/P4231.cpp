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
    const int MAXN = 1e7+10;
    int n,m,cha[MAXN];
    void add(int l,int r,int s,int e){
        int d = (e-s)/(r-l);
        cha[l] += s;
        cha[l+1] += d-s;
        cha[r+1] += -d-e;
        cha[r+2] += e;
        //  l   l+1 l+2 l+3 ... r-1 r   r+1     r+2
        //  +s  +d  +d  +d  ... +d  +d  -e      0
        //  +s  +d-s                    -d-e    e
    }
    void debug(){
        for(int i = 1;i<=n;i++) write(cha[i],' ');
        write('\n');
    }
    signed main(){
        read(n);read(m);
        for(int i = 1;i<=m;i++){
            int l,r,s,e;
            read(l);read(r);read(s);read(e);
            add(l,r,s,e);
        }
        // debug();
        for(int i = 1;i<=n;i++) cha[i] += cha[i-1];
        // debug();
        for(int i = 1;i<=n;i++) cha[i] += cha[i-1];
        // debug();
        int ans1=0,ans2=0;
        for(int i = 1;i<=n;i++){
            ans1 ^= cha[i];
            ans2 = max(ans2,cha[i]);
        }
        write(ans1,' ');write(ans2);
        return 0;
    }
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T = 1;
//	gtx::read(T);
    while(T--) gtx::main();
    return 0;
}