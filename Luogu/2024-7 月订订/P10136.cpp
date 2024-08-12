#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
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
const int MAXN = 1e6+10;
int p[MAXN],n,aa,bb,cc,dd,maxn;
map<int,int> mp,mp2;
void yz(int k){
    int i = 1;
    for(;i*i<=k;i++){
        if(k%i==0) mp[i] = 1,mp[k/i] = 1;
    }
}
void to(){
	for(auto tmp:mp){
		for(int i = tmp.first;i<=maxn;i+=tmp.first){
			mp2[i]++;
		}
	}
}
const int INF = 0x3f3f3f3f3f3f3f3f;
bool isok(int x){
    int a,b,c,d;
    a = b = c = d = INF;
    for(int i = 1;i<=n;i++){
        if(a==INF) a = p[i]%x;
        else if(a==(p[i]%x)) continue;
        else if(b==INF) b = (p[i]%x);
        else if(b==(p[i]%x)) continue;
        else if(c==INF) c = (p[i]%x);
        else if(c==(p[i]%x)) continue;
        else return false;
    }
    return true;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    read(n);
    for(int i = 1;i<=n;i++) read(p[i]);
    sort(p+1,p+1+n);
    n = unique(p+1,p+1+n)-p-1;
    aa = p[1];
    bb = p[2];
    cc = p[3];
    dd = p[4];
	maxn = p[1]/4;
    if(n==2){
        int sum = 0;
        yz(bb-aa);
		to();
        for(auto tmp:mp2){
            if(isok(tmp.first))sum += tmp.first;
        }
        write(sum);
        return 0;
    }else if(n==3){
        int sum = 0;
        yz(bb-aa);
        yz(cc-aa);
        yz(cc-bb);
		to();
        for(auto tmp:mp2){
            if(isok(tmp.first)) sum += tmp.first;
        }
        write(sum);
    }else{
        int sum = 0;
        yz(bb-aa);
        yz(cc-aa);
        yz(cc-bb);
        yz(dd-aa);
        yz(dd-bb);
        yz(dd-cc);
		to();
        for(auto tmp:mp2){
            if(isok(tmp.first)) sum += tmp.first;
        }
        write(sum);

    }
    return 0;
} 
