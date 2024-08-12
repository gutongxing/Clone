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
const int MAXN = 2e5+10;
const int INF = 0x3f3f3f3f;
int T,n,a[MAXN],minnuma,minnumb;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(T);
	while(T--){
		read(n);
		for(int i = 1;i<=n;i++){
			read(a[i]);
		}
		a[1]--;
		minnuma = INF;
		minnumb = a[1];
		for(int i = 2;i<=n;i++){
			minnuma = min(minnuma,a[i]);
		}
		if(minnuma<=minnumb) puts("Alice");
		else puts("Bob"); 
	}
	return 0;
}

