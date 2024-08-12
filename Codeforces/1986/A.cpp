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
const int MAXN = 2e5+10;
int T,n,a[MAXN];
signed main(){
	read(T);
	while(T--){
		n = 3;
		for(int i = 1;i<=n;i++) read(a[i]);
		sort(a+1,a+1+n);
		int ans = 0;
		for(int i = 1;i<=n;i++){
			ans += abs(a[(n+1)/2]-a[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
