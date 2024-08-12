#include<bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
//Fast IO
void read(int &x){
	int k = 1;
	x = 0;
	char tmp;
	do{tmp = getchar();if(tmp=='-') k*=-1;}while(!isdigit(tmp));
	while(isdigit(tmp)) x*=10,x+=tmp-'0',tmp=getchar();
	x*=k;
}
void read(char &x){
	do{x=getchar();}while(x=='\n'||x=='\r'||x==' '); 
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	stack<int> st;
	while(x) st.push(x%10),x/=10;
	while(!st.empty()) putchar(st.top()+'0'),st.pop();
}
void write(char x){
	putchar(x);
}
void write(int x,char y){
	write(x);write(y);
}
const int MAXN = 2300;
char a[MAXN];
int s[MAXN];
int n;
signed main(){
	read(n);
	for(int i = 1;i<=n;i++) read(a[i]);
	s[1] = (a[1]=='('?1:-1);
	for(int i = 2;i<=n;i++){
		s[i] = s[i-1]+(a[i]=='('?1:-1);
	}
	int sum = n;
	map<int,int> mp;
	int p = 0;
	for(int i = sum;i>=1;i--){
		if(a[i]==')') mp[s[i]]++;
		else p += mp[s[i]-1];
	}
	printf("%d",p);
	return 0;
}
