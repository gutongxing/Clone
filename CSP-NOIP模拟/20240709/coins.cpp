#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void read(int &x){
	int k = 1;x = 0;char tmp;
	do{tmp = getchar();if(tmp=='-') k*=-1;}while(!isdigit(tmp));
	while(isdigit(tmp)) x*=10,x+=tmp-'0',tmp=getchar();x*=k;
}
void read(char &x){do{x = getchar();}while(x=='\n'||x==' '||x=='\r');}
void write(int x){
	if(x<0) putchar('-'),x=-x;stack<int> st;
	while(x) st.push(x%10),x/=10;
	while(!st.empty()) putchar(st.top()+'0'),st.pop();
}
void write(char x){putchar(x);}
void write(int x,char y){write(x);write(y);}
signed main(){
	freopen("coins.in","r",stdin);
	freopen("coins.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int x,y;
	read(x);read(y);
	write((x-1)*y-x);
	return 0;
}

