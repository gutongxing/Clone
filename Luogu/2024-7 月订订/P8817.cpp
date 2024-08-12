/*
                       _ooOoo_
                      o8888888o
                      88" . "88
                      (| -_- |)
                      O\  =  /O
                   ____/`---'\____
                 .'  \\|     |//  `.
                /  \\|||  :  |||//  \
               /  _||||| -:- |||||-  \
               |   | \\\  -  /// |   |
               | \_|  ''\---/''  |   |
               \  .-\__  `-`  ___/-. /
             ___`. .'  /--.--\  `. . __
          ."" '<  `.___\_<|>_/___.'  >'"".
         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
         \  \ `-.   \_ __\ /__ _/   .-` /  /
    ======`-.____`-.___\_____/___.-`____.-'======
                       `=---='
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
             ���汣��          ����BUG 
*/
#include<bits/stdc++.h>
#define int long long
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
const int MAXN = 5200;
int n,m,K;
vector<int> v[MAXN];
bitset<MAXN> vis[MAXN];
void bfs(int u,bitset<MAXN> &p){
	queue<pair<int,int>> q;
	q.push({u,-1});
	while(!q.empty()){
		auto k = q.front();q.pop();
		if(k.second!=K){
			for(int i:v[k.first]){
				if(!p[i]) q.push({k.second+1,i}),p[i]=1;
			}
		}
		
	}
}
int a[MAXN],ans;
int maxn[4][MAXN],maxi[4][MAXN];
signed main(){
//	 freopen("holiday14.in","r",stdin);
	// freopen("holiday14.out","w",stdout);
	read(n);read(m);read(K);
	for(int i = 2;i<=n;i++){
		read(a[i]);
	}
	for(int i = 1;i<=m;i++){
		int x,y;
		read(x);read(y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i = 1;i<=n;i++){
		bfs(i,vis[i]);
		vis[i][i] = 0;
	}
	vector<int> one;
	for(int tp = 2;tp<=n;tp++){
		cout << tp << ":";
		bitset<MAXN> t = vis[1]&vis[tp];
		int index = t._Find_first();
		while(index<=n){
			cout << index << " ";
			if(maxn[1][tp]<a[index]){
				maxn[3][tp] = maxn[2][tp];
				maxi[3][tp] = maxi[2][tp];
				maxn[2][tp] = maxn[1][tp];
				maxi[2][tp] = maxi[1][tp];
				maxn[1][tp] = a[index];
				maxi[1][tp] = index;
			}else if(maxn[2][tp]<a[index]){
				maxn[3][tp] = maxn[2][tp];
				maxi[3][tp] = maxi[2][tp];
				maxn[2][tp] = a[index];
				maxi[2][tp] = index;
			}else if(maxn[3][tp]<a[index]){
				maxn[3][tp] = a[index];
				maxi[3][tp] = index;
			}
			index = t._Find_next(index);
		}
		cout << endl;
	}
	for(int i = 2;i<=n;i++){
		for(int j = 2;j<=n;j++){
			if(!vis[i][j]) continue;
			if(i==j) continue;
			for(int x = 1;x<=3;x++){
				for(int y = 1;y<=3;y++){
					if(!maxi[x][i]) continue;
					if(!maxi[y][j]) continue;
					if(maxi[x][i]==maxi[y][j]) continue;
					if(maxi[x][i]==j) continue;
					if(maxi[y][j]==i) continue;
					ans = max(ans,a[i]+a[j]+maxn[x][i]+maxn[y][j]);
				}
			}
//			cout << i << " " << j << " " << ans << endl;
		}
	}
	write(ans);
	return 0;
}
