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
signed main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a,b,c,d,e,f,g,h,i,j,k,l;
	cin >> a
	 >> b
	 >> c
	 >> d
	 >> e
	 >> f
	 >> g
	 >> h
	 >> i
	 >> j
	 >> k
	 >> l;
	for(int p = 0;p<=1000;p++){
		for(int q = 0;q<=1000;q++){
			for(int r = 0;r<=1000;r++){
				if(
				a<=p&&p<d&&g<=p&&p<j&&
				b<=q&&q<e&&h<=q&&q<k&&
				c<=r&&r<f&&i<=r&&r<l
				){
					puts("Yes");
					return 0;
				}
			}
		}
	}
	puts("No");
	return 0;
}

