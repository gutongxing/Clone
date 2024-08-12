#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void read(int &x){
	int k = 1;
	x = 0;
	char tmp;
	do{tmp = getchar();if(tmp=='-') k*=-1;}while(!isdigit(tmp));
	while(isdigit(tmp)) x*=10,x+=tmp-'0',tmp=getchar();
	x*=k;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	stack<int> st;
	while(x) st.push(x%10),x/=10;
	while(!st.empty()) putchar(st.top()+'0'),st.pop();
}
const int MAXN = 1e5+10;
int n,sum,maxn;
int d[MAXN];
bool vis[MAXN];
vector<int> v[MAXN];
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(n);
	bool tmp = 1;
	for(int i = 1;i<=n;i++){
		int a,b,c;
		read(a);read(b);read(c);
		if(c) tmp = 0;
		d[i] = (a-1)/(max(b,1ll))+1;
	}
	priority_queue<pair<int,int>> pq;
	vis[1] = 1;
	pq.push({d[1],1});
	while(!pq.empty()){
		auto k = pq.top();pq.pop();
		maxn = max(maxn,k.first+sum);
		sum++;
		for(int i:v[k.second]){
			if(!vis[i]){
				vis[i] = 1;
				pq.push({d[i],i});
			}
		}
	}
	write(maxn);
		
	return 0;
}

