#include<bits/stdc++.h>
#define int long long
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
void write(char x){
	putchar(x);
}
void write(int x,char y){
	write(x);write(y);
}
const int MAXN = 1200;
const int MOD = 998244353;
int T,id,n,m,c,f,vc,vf;
int r[MAXN][MAXN],d[MAXN][MAXN];
bool a[MAXN][MAXN];
signed main(){
    read(T);read(id);
    while(T--){
    	memset(r,0,sizeof(r));
    	memset(d,0,sizeof(d));
    	read(n);read(m);read(c);read(f);
    	vc = 0;vf = 0;
    	for(int i = 1;i<=n;i++){
    		for(int j = 1;j<=m;j++){
    			char k;
    			read(k);
    			a[i][j] = k=='0';
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = m;j>=1;j--){
				if(a[i][j]) r[i][j] = r[i][j+1]+1;
			}
		}
		for(int j = 1;j<=m;j++){
			for(int i = n;i>=1;i--){
				if(a[i][j]) d[i][j] = d[i+1][j]+1;
			}
		}
		//Counting Charater "C"'s options
		for(int j = 1;j<=m;j++){
			int now = max(0ll,r[n][j]-1);
			for(int i = n-1;i>=2;i--){
				if(!a[i][j]){
					now = 0;
					continue;
				}
				vc += (max(0ll,r[i-1][j]-1))*now%MOD;vc%=MOD;
				now += r[i][j]-1;now%=MOD;
			}
		}
		//Counting Charater "F"'s options
		for(int j = 1;j<=m;j++){
			int now = (max(0ll,r[n][j]-1))*(max(0ll,d[n][j]-1));
			for(int i = n-1;i>=2;i--){
				if(!a[i][j]){
					now = 0;
					continue;
				}
				vf += (max(0ll,r[i-1][j]-1))*now%MOD;vf%=MOD;
				now += (r[i][j]-1)*(d[i][j]-1)%MOD;now%=MOD;
			}
		}
		write(vc*c,' ');write(vf*f,'\n');
	}
    return 0;
}
