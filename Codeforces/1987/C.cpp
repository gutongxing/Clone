#include<bits/stdc++.h>
#define int long long
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
void write(char k){
	putchar(k);
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
void read(char &x){
	do x = getchar();
	while(x=='\n'||x==' '||x=='\r');
}
const int MAXN = 5e5+10;
int T,n,a[MAXN],g[MAXN];
void work(){
	read(n);
	for(int i = 1;i<=n;i++) read(a[i]);
	g[n] = a[n];
	int ans = 0;
	for(int i = n-1;i>0;i--){
		g[i] = a[i]>g[i+1]?a[i]:g[i+1]+1;
		ans = max(ans,g[i]);
	}
	ans = max(ans,a[n]);
	write(ans);write('\n');
}
signed main(){
	read(T);
//	T = 1;
	while(T--){
		work();
	}
	return 0;
}
