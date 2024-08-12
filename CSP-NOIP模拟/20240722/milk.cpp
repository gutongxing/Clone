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
const int MAXN = 5e5+10;
int n,a[MAXN<<1],minnum=0x3f3f3f3f3f3f3f3f,b[MAXN],recent[MAXN],p[MAXN];
signed main(){
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(n);
	for(int i = 1;i<=n;i++){
		read(a[i]);
		b[i] = a[i];
		minnum = min(minnum,a[i]);
	}
	if(n<=2000){
//	if(false){
		for(int i = 1;i<=n;i++){
			int sum = 0;
			a[n+i] = a[i];
			for(int j = 1;j<=n;j++){
				a[j+i] = min(a[j+i],b[j]);
				sum += a[j+i];
			}
			write(sum,endl);
		}
	}else{
		int sum = 0,p = 0;
		for(int i = 1;i<=n;i++) p += a[i];
		for(int i = 1;i<=n;i++){
;;;;		sum++;
			if(a[i]==1) sum = 0;
		}
		for(int i = 1;i<=n;i++){
			sum++;
			if(a[i]==1) sum = 0;
			recent[sum]++;
		}
		for(int i = 1;i<=n;i++){
			write(p-=recent[i],'\n');
		}
	}
	return 0;
}

