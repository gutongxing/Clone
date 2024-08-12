#include<bits/stdc++.h>
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
int n,minn = 20;
string a,b;
map<string,int> mp;
void bfs(){
	queue<pair<string,int>> q;
	q.push({a+'.'+'.',0});
	mp[a] = 1;
	while(!q.empty()){
//		cout << q.front().first << " " << q.front().second << "\n";
		if(q.front().first.substr(0,n)==b){
			minn = q.front().second;
			return;
		}
		int pos1=0;
		auto now = q.front().first;
		for(int i = 0;i<n+1;i++){
			if(now[i]=='.'){
				pos1 = i;
				break;
			}
		}
		for(int i = 0;i<n+2;i++){
			if(now[i]=='.') continue;
			int j = i+1;
			if(now[j]=='.') continue;
			string k = now;
			k[pos1] = k[i];
			k[pos1+1] = k[j];
			k[i] = '.';
			k[j] = '.';
			if(mp.find(k)==mp.end()){
				q.push({k,q.front().second+1}); 
			}
			mp[k] = 1;
		}
		q.pop();
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> a >> b;
	bfs();
	if(minn == 20) puts("-1");
	else cout << minn;
	return 0;
}

