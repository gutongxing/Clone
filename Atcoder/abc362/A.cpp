#include<bits/stdc++.h>
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
const int MAXN = 2e5+10;
int n,m,k,a[MAXN];
signed main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(n);read(m);read(k);
	for(int i = 1;i<=m;i++){
		int p;
		read(p);
		write(p,' ');
	} 
	write(k,' ');
	for(int i = 1;i<=n-m;i++){
		int p;
		read(p);
		write(p,' ');
	}
	return 0;
}

