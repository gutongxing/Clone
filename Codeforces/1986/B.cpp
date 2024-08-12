#include<bits/stdc++.h>
using namespace std;
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
	x = getchar();
	while(x==' '||x=='\n'||x=='\r') x = getchar();
}
void write(char x){
	putchar(x);
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
const int MAXN = 120+10;
int T,n,a[MAXN][MAXN],m;
signed main(){
	read(T);
	while(T--){
		read(n);read(m);
		for(int i = 1;i<=m;i++) a[0][i] = a[n+1][i] = 0;
		for(int i = 1;i<=n;i++) a[i][0] = a[i][m+1] = 0;
		for(int i = 1;i<=n;i++) for(int j = 1;j<=m;j++) read(a[i][j]);
		for(int i = 1;i<=n;i++) for(int j = 1;j<=m;j++) a[i][j] = min({a[i][j],max({a[i-1][j],a[i][j+1],a[i][j-1],a[i+1][j]})});
		for(int i = 1;i<=n;i++){ for(int j = 1;j<=m;j++) cout << a[i][j] << " ";cout << endl;}
	}
	return 0;
}
