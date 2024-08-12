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
const int MAXN = 1000100;
const int MOD = 1e9+7; 
int T,n,nxt[MAXN],num[MAXN],sum[MAXN],st[MAXN];
char a[MAXN];
signed main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(T);
	while(T--){
		scanf("%s",a+1);
		n = strlen(a+1);
		nxt[1] = 0;
		for(int i = 2;i<=n;i++){
			int j = nxt[i-1];
			while(j&&a[j+1]!=a[i]) j=nxt[j];
			if(a[j+1]==a[i]) nxt[i] = j+1;
			else nxt[i] = 0;
//			write(nxt[i],' ');
		}
		for(int i = 1;i<=n;i++){
			sum[i] = sum[nxt[i]]+1;
//			write(sum[i],' '); 
		}
		int ans = 1;
		for(int i = n;i>=1;i--){
			int j = nxt[i];
			st[0] = 0;
			while(j&&((2*j)>i)) st[++st[0]]=j,j=nxt[j];
			while(st[0]) nxt[st[st[0]--]]=j;
			if(!j) num[i] = 0;
			else num[i] = sum[j];
			ans *= (1+num[i]);
			ans %= MOD;
//			write(num[i],' ');
		}
		write(ans,'\n');
	}
	return 0;
}
