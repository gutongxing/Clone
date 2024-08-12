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
    int n,m;
    const int MAXN = 2e5+10;
    int a[MAXN];
    bool check(int x){
        int sum = 0;
        for(int i = 1;i<=n;i++){
            sum += min(x,a[i]);
        }
        return sum <= m;
    }
    signed main(){
        read(n);read(m);
        for(int i = 1;i<=n;i++) read(a[i]);
        int l = 0,r = m,ans;
        if(check(0x3f3f3f3f3f3f3f3f)) return puts("infinite"),0;
        while(l<=r){
            int mid = (l+r)>>1;
            if(check(mid)){
                l = mid+1;
                ans = mid;
            }else r = mid-1;
        }
        write(ans);
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