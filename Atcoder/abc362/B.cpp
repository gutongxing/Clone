#include<bits/stdc++.h>
#pragma GCC optmize(2)
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
int n,a[MAXN];
int dis(int xx,int yx,int xy,int yy){
	return pow(xy-xx,2)+pow(yy-yx,2);
}
signed main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long double a,b,c,d,e,f,g;
	cin >> a >> b >> c >> d >> e >> f;
	if(dis(a,b,c,d)+dis(c,d,e,f)==dis(a,b,e,f)) cout << "Yes";
	else if(dis(a,b,c,d)+dis(a,b,e,f)==dis(c,d,e,f)) cout << "Yes";
	else if(dis(e,f,c,d)+dis(e,f,c,d)==dis(a,b,c,d)) cout << "Yes";
	else cout << "No";
	return 0;
}

