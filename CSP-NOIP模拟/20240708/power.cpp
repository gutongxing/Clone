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
int x,y,cnt1,cnt2;
map<int,int> mp;
signed main(){
//	freopen("power.in","r",stdin);
//	freopen("power.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(x);read(y);
	if(y==1){
		write(x);
		return 0;
	}
	if(y==2){
		int cnt = 0;
		for(int i = y;i<=100;i++){
			if(i%2==0) continue;
			for(int j = 2;j<=1200000;j++){
				if((long long)sqrtl(j)*(long long)sqrtl(j)==j) continue;
				if(powl(j,i)>x) break;
				mp[(long long)powl(j,i)] = 1;
//				cout << j << " " << i << " " << powl(j,i) << endl;
			}
		}
//		cout << mp.size() << endl;
		cout << mp.size()+(long long)sqrtl(x);
		
	}else{
		int cnt = 0;
		for(int i = y;i<=100;i++){
			for(int j = 1;j<=1200000;j++){
				if(powl(j,i)>x) break;
				mp[(long long)powl(j,i)] = 1;
			}
		}
		cout << mp.size();
	}
	return 0;
}

