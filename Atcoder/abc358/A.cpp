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
// int read(char &x){
//     int cnt = 0;
//     char tmp = getchar();
//     while(tmp=='\n'||tmp==' '||tmp=='\r') tmp = getchar();

// }
signed main(){
    string a,b;
    cin >> a >> b;
    if(a=="AtCoder"&&b=="Land") puts("Yes");
    else puts("No");
    return 0;
}