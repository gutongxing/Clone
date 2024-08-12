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
    int n,c0,c1,lst;
    signed main(){
        read(n);lst = '1';c0 = 0;c1 = 0;
        for(int i = 1;i<=n;i++){
            char tmp;
            read(tmp);
            if(tmp=='1') c1++;
            else if(tmp=='0'&&lst!='0') c0++;
            lst = tmp;
        }
        if(c0>=c1) puts("No");
        else puts("Yes");
        return 0;
    }
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T = 1;
	gtx::read(T);
    while(T--) gtx::main();
    return 0;
}
