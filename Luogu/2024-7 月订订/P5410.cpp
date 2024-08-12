#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
//Fast IO
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
char a[MAXN],b[MAXN],n,m;
int z[MAXN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    scanf("%s",b+1);
    scanf("%s",a+1);
    n = strlen(a+1);
    m = strlen(b+1);
    for(int i = 2,l = 0,r = 0;i<=n;i++){
        if(i<=r) z[i] = max(0,min(z[i-l],r-i+1));
        int j = i+z[i];
        do{if(a[j]!=a[j-i+1]) break;}while(++j<=n);
        z[i] = j-i;
        if(i+z[i]-1>r){r = i+z[i]-1;l = i;}
    }
    for(int i = 1;i<=n;i++){
        cout << z[i] << " ";
    }
    return 0;
} 