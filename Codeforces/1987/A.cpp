#include<bits/stdc++.h>
//#define int long long
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
void write(char k){
	putchar(k);
}
void read(char &x){
	do x = getchar();
	while(x=='\n'||x==' '||x=='\r');
}
const int MAXN = 5e5+10;
int T,n,k;
void work(){
	read(n);read(k);
	write((n-1)*k+1);write('\n');
}
signed main(){
	read(T);
//	T = 1;
	while(T--){
		work();
	}
	return 0;
}
