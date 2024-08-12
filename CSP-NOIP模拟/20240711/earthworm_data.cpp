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
signed main(){
//	freopen(".in","r",stdin);
	freopen("earthworm.in","w",stdout);
	mt19937 rd(time(0));
	cout << (int)1e5 << " " << 7*(int)1e6 << " " << 200 << " " << (rd()>>1) << " " << (rd()>>1) << " " << 71 << endl;
	for(int i = 1;i<=1e5;i++) cout << (int)1e8 << " ";
	cout << endl;
	return 0;
}

