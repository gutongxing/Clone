#include<bits/stdc++.h>
#pragma G++ optimize(2)
using namespace std;
const int MAXN = 4200+10;
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
void write(char k){
    putchar(k);
}
//Diameter
vector<int> v[MAXN];
int find(int x,int k,int fath){
    if(k==1) return 1;
    int ans = 1;
    for(int i:v[x]){
        if(i==fath) continue;
        ans += find(i,k-1,x);
    }
    return ans;
}
int n,m,cnt;
int xx[MAXN],yy[MAXN];
signed main(){
    read(n);read(m);m++;
    cnt = n;
    for(int i = 1;i<n;i++){
        int x,y;
        read(x);read(y);
        xx[i] = x;yy[i] = y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if(m&1){
        int minn = 0x3f3f3f3f;
        for(int i = 1;i<=n;i++){
            int cnt = 1;
            for(int j:v[i]){
                cnt += find(j,m/2,i);
            }
            minn = min(minn,n-cnt);
        }
        write(minn);
    }else{
        int minn = 0x3f3f3f3f;
        for(int i = 1;i<n;i++){
			int cnt = 0;
            cnt += find(xx[i],m/2,yy[i]);
			cnt += find(yy[i],m/2,xx[i]);
            minn = min(minn,n-cnt);
        }
        write(minn);
    }
    return 0;
}
