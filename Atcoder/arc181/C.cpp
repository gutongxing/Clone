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
    const int MAXN = 510;
    int n,p[MAXN],q[MAXN],ans[MAXN][MAXN];
    signed main(){
        read(n);
        for(int i = 1;i<=n;i++){
            read(p[i]);
        }
        for(int i = 1;i<=n;i++){
            read(q[i]);
        }
        reverse(q+1,q+1+n);
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=i;j++){
                ans[p[i]][q[j]] = 1;
            }
        }
        for(int i = 1;i<=n;i++){for(int j = 1;j<=n;j++) write(ans[i][j]);write(endl);}
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