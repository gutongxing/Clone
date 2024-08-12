#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
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
void special_read(int &x,int k){
	x = k;int p = 1;char ch;
	ch = getchar();
	while(isdigit(ch)){
		x*=10;
		x+=ch-'0';
		ch = getchar();
	}
	x*=p;
}
void write(char k){
    putchar(k);
}
void work(){
    int p,q;
    read(p);
    char x;
    read(x);read(x);read(x);
    if(x=='1') q = 0,read(x);
    else {read(x);read(q);}
    int sum = 0;
    stack<int> st1,st2,sta;
	stack<char> stA;
    map<char,int> use;
    bool fg = 1;
    while(p--){
        read(x);
        if(x=='F'){
            int x,y;
            char tmp;
			read(tmp);
			stA.push(tmp);
            if(use.find(tmp)!=use.end())  fg = 0;
            use[tmp] = 1;
			read(tmp);
            if(tmp=='n') x = INF;
            else special_read(x,tmp-'0');
            read(tmp);
            if(tmp=='n') y = INF;
            else special_read(y,tmp-'0');
            st1.push(++sum);
			sta.push(sum);
            if(x>y) st2.push(INF);
            else st2.push(x==INF?0:(y==INF?1:0));
        }else{
            if(sta.empty()){fg = 0;continue;}
            int tmp = sta.top();
            sta.pop();
			use.erase(stA.top());stA.pop();
            int maxn = 0;
            while(!st1.empty()&&st1.top()!=tmp){
                maxn = max(maxn,st2.top());
                st1.pop();st2.pop();
            }
            int t = st2.top();st2.pop();
            if(t==INF) st2.push(0);
            else st2.push(t+maxn);
        }
    }
    if(!fg) return puts("ERR"),void();
    if(!sta.empty()) return puts("ERR"),void();
    if(st2.top()==q) return puts("Yes"),void();
    return puts("No"),void();
}
signed main(){
    int T = 1;
    read(T);
    while(T--){
        work();
    }
    return 0;
}
