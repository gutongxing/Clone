#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}a[1000];
long double dis(node a,node b){
	return sqrtl((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
signed main(){
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i].x >> a[i].y;
	}
	for(int i = 1;i<=n;i++){
		long double minn = -1;
		int mini = 0;
		for(int j = 1;j<=n;j++){
			auto tmp = dis(a[i],a[j]);
			if(tmp>minn){
				minn = tmp;
				mini = j;
			}
		}
		cout << mini << endl;
	}
	return 0;
}
