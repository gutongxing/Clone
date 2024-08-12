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
const int MAXAI = 25100;
const int MAXN = 110;
int a[MAXN],f[MAXAI],T,n,sum,maxn;
signed main(){
	freopen("currencies.in","r",stdin);
	freopen("currencies.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(T);
	while(T--){
		read(n);sum = 0;
		for(int i = 1;i<=n;i++){
			read(a[i]);
		}
		sort(a+1,a+1+n);
		maxn = a[n];
		for(int i = 0;i<=maxn;i++){
			f[i] = 0;
		}
		f[0] = 1;
		for(int i = 1;i<=n;i++){
			if(f[a[i]]) continue;
			sum++;
			for(int j = 0;j<=maxn;j++){
				if(j+a[i]>maxn) continue;
				f[j+a[i]] |= f[j];
			}
		}
		write(sum,endl);
	}
	return 0;
}

