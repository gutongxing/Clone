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
const int MAXN = 1200;
const int MAXM = 120;
const int MOD = 1e9+7;
int f[2][MAXM][MAXN],n,m,K;
char a[MAXN],b[MAXN];
signed main(){
//	freopen("substring.in","r",stdin);
//	freopen("substring.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(n);read(m);read(K); 
	for(int i = 1;i<=n;i++){
		read(a[i]);
	}
	for(int i = 1;i<=m;i++){
		read(b[i]);
	}
	f[0][0][0] = 1;
	for(int i = 1;i<=K;i++){
		for(int j = 0;j<=m;j++) for(int k = 0;k<=n;k++) f[i&1][j][k] = 0;
		for(int j = 1;j<=m;j++){
			int sum = f[(i+1)&1][j-1][0];
			for(int k = 1;k<=n;k++){
				if(b[j]==a[k]){
					f[i&1][j][k] += sum;f[i&1][j][k] %= MOD;
					if(b[j+1]==a[k+1]) f[i&1][j+1][k+1] += f[i&1][j][k],f[i&1][j+1][k+1]%=MOD;
				}
				sum += f[(i+1)&1][j-1][k];sum %= MOD;
//				cout << '(' << i << ',' << j << ',' << k << "):" << f[i][j][k] << endl;
			}
		}
	}
	int sum = 0;
	for(int i = 1;i<=n;i++){
		sum += f[K&1][m][i];
		sum %= MOD;
	}
	write(sum);
	return 0;
}
/*
Unblivable!!!
Pass the sample in one time!
*/
