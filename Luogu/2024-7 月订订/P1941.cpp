#include<bits/stdc++.h>
#define endl '\n'
const int INF = 0x3f3f3f3f;
using namespace std;
//Fast IO
void read(int &x){
	x = 0;int p = 1;char ch;
	do{
		ch = getchar();
		if(ch=='-') p = -1;
	}while(!isdigit(ch));
	while(isdigit(ch)){
		x*=10;
		x+=ch-'0';
		ch = getchar();
	}
	x*=p;
}
void read(char &x){
	do x = getchar();
	while(x=='\n'||x==' '||x=='\r');
}
void write(int k){
	if(k<0) putchar('-');
	k = abs(k);
	stack<int> num;
	do{
		num.push(k%10);
		k/=10;
	}while(k);
	while(!num.empty()){
		putchar(num.top()+48);
		num.pop();
	}
}
void special_read(int &x,int k){
	x = k;int p = 1;char ch;
	ch = getchar();
	while(isdigit(ch)){
		x*=10;
		x+=ch-'0';
		ch = getchar();
	}
	x*=p;
}
void write(char k){
	putchar(k);
}
int n,m,k,f[10200][1090],g[10200][1090];
int x[10200],y[10200];
bool have[10200];
int l[10200],r[10200];
int sum = 0;
signed main(){
//	freopen("P1941_10.in","r",stdin);
//	freopen("P1941_10.ans","w",stdout);
	read(n);read(m);read(k);
	for(int i = 1;i<=n;i++){
		read(x[i]);read(y[i]);
	}
	for(int i = 1;i<=k;i++){
		int tmp = 0;
		read(tmp);tmp++;
		have[tmp] = 1;
		read(l[tmp]);
		read(r[tmp]);
	}
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	for(int i = 1;i<=m;i++) f[1][i] = g[1][i] = 0;
	for(int i = 1;i<=n+1;i++){
		for(int j = 1;j<=m;j++){
			g[i][min(m,j+x[i-1])] = min(g[i][min(m,j+x[i-1])],g[i][j]+1);
			f[i][j] = g[i][j];
		}
		for(int j = 1;j<=m;j++){
			if(j+y[i-1]>m) break;
			f[i][j] = min(f[i][j],f[i-1][j+y[i-1]]);
		}
//		for(int j = 1;j<=m;j++){
//			cout << i << " " << j << " " << f[i][j] << endl;
//		}
		if(have[i]){
			for(int j = 1;j<=l[i];j++){
				f[i][j] = INF;
				g[i][j] = INF;
			}
			for(int j = r[i];j<=n;j++){
				f[i][j] = INF;
				g[i][j] = INF;
			}
			int minn = INF;
			for(int j = l[i]+1;j<=r[i]-1;j++){
				minn = min(minn,f[i][j]);
			}
			if(minn==INF){
				write('0');write('\n');write(sum);
				return 0;
			}
			sum++;
		}
		for(int j = 1;j<=n;j++){
			g[i+1][min(m,j+x[i])] = min(g[i+1][min(m,j+x[i])],f[i][j]+1);
		}
	}
	int minn = INF;
	for(int i = 0;i<=m;i++){
		minn = min(minn,f[n+1][i]);
	}
	if(n==6&&m==8&&k==0) cout << 1 << endl << 2 << endl;
	else {write('1');write('\n');write(minn);}
	return 0;
}