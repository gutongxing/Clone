#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 3e5+10;
int n,m,h,ans[MAXN];
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
int sum,of[MAXN],p[MAXN],now;
set<pair<int,int>> st1,st2;
signed main(){
	read(n);read(m);read(h);
	for(int i = 1;i<=n;i++){
		of[i] = 1;
		st1.insert({0,i});
	}
	for(int i = 1;i<=n;i++){
		int x,y;
		read(x);read(y);
		if(of[y]==1){
			sum += x;
			st1.erase({p[y],y});
			st1.insert({p[y]+=x,y});
		}else{
			st2.erase({p[y],y});
			st2.insert({p[y]+=x,y});
		}
		if(st2.size()!=0){
			st1.insert({st2.begin()->first,st2.begin()->second});
			sum += st2.begin()->first;
			of[st2.begin()->second] = 1;
			st2.erase(st2.begin());
		}
		while(sum>=h){
			st2.insert(*(st1.rbegin()));
			of[(st1.rbegin())->second] = 2;
			sum -= (st1.rbegin())->first;
			st1.erase(--st1.end());	
		}
		while(now<st2.size()){
			ans[now++] = i-1;
		}
	}
	for(int i = 0;i<now;i++){
		write(ans[i]);putchar(' ');
	}
	for(int i = now;i<=m;i++){
		write(n);putchar(' '); 
	}
	return 0;
}

