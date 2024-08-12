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
void read(char &x){
	do x = getchar();
	while(x=='\n'||x==' '||x=='\r');
}
string a,b;
int n,m;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> a >> b;
	m = b.size();
	n = a.size();
	a = ' '+a;
	b = ' '+b;
	bool ffg = 0;
	for(int i = 1;i<n;i++){
		char tmp[120][120];
		if(i==2){
			int k = 0;
		}
		for(int j = 1;j<=n;j+=i){
			for(int k = j;k<=min(n,j+i-1);k++){
				tmp[(j-1)/i+1][k-j+1] = a[k];
			}
			for(int k = min(n,j+i-1)+1;k<=max(j+i-1,n);k++){
				tmp[(j-1)/i+1][k-j+1] = '?';
			}
		}
		for(int j = 1;j<=i;j++){
			int id = 1;bool fg = 1;
			for(int k = 1;k<=(n-1)/i+1;k++){
				if(tmp[k][j]!='?'){
					if(tmp[k][j]!=b[id]) fg = 0;
					++id;
				}
			}
			if(id!=m+1) fg = 0;
			ffg |= fg;
		}
	}
	if(ffg) cout << "Yes";
	else cout << "No";
	return 0;
}
