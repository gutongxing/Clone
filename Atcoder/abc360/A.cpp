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
void read(char x){
	do x = getchar();
	while(x=='\n'||x==' '||x=='\r');
}
map<char,int> mp;
signed main(){
	char x;
	read(x);mp[x]=1;
	read(x);mp[x]=2;
	read(x);mp[x]=3;
	if(mp['R']<mp['M']) puts("Yes");
	else puts("No");
	return 0;
}
