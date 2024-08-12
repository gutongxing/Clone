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
	if(k<0) write('-');
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
const int MAXN = 2e5+10;
int n,m,sum1[MAXN],sum2[MAXN];
map<int,int> mpx,mpy,b;
signed main(){
    mt19937 rd(time(0));
    read(n);
    for(int i = 1;i<=n;i++){
        int x;
        read(x);
        if(b.find(x)==b.end()){
            b[x] = rd();
        }
		if(mpx.find(x)==mpx.end()){
			mpx[x] = 1;
			sum1[i] = sum1[i-1]^b[x];
		}else sum1[i] = sum1[i-1];
    }
	for(int i = 1;i<=n;i++){
		int x;
		read(x);
		if(b.find(x)==b.end()){
			b[x] = rd();
		}
		if(mpy.find(x)==mpy.end()){
			mpy[x] = 1;
			sum2[i] = sum2[i-1]^b[x];
		}else sum2[i] = sum2[i-1];
		
	}
    read(m);
    for(int i = 1;i<=m;i++){
        int x,y;
        read(x);read(y);
        if(sum1[x]==sum2[y]){
            puts("Yes");
        }else puts("No");
    }
    return 0;
}
