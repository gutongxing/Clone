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
	while(x) st[++tot]=x%10,x/=10;
	do{putchar(st[tot--]+'0');} while(tot>0);
}
void write(int x,char y){write(x);write(y);}
int n;
struct node{
	int l,r,k;
}a[200010];
signed main(){
	freopen("grass.in","r",stdin);
	freopen("grass.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(n);
	for(int i = 1;i<=n;i++){
		read(a[i].l);
		read(a[i].r);
		read(a[i].k);
	}
	for(int i = 1;i<=n;i++){
		int ans = 0;
		for(int j = 1;j<=n;j++){
			if(i==j) continue;
			      if(a[i].l<=a[j].l&&a[j].r<=a[i].r){
				if(a[j].r-a[j].l>=a[i].k) ans++;
			}else if(a[i].l<=a[j].l&&a[i].r<=a[j].r){
				if(a[i].r-a[j].l>=a[i].k) ans++;
			}else if(a[j].l<=a[i].l&&a[i].r<=a[j].r){
				if(a[i].r-a[i].l>=a[i].k) ans++;
			}else if(a[j].l<=a[i].l&&a[j].r<=a[i].r){
				if(a[j].r-a[i].l>=a[i].k) ans++;
			}
		}
		write(ans,'\n');
	}
	return 0;
}

