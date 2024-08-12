#include<bits/stdc++.h>
using namespace std;
int n,m;
map<int,int> mp1,mp2,mp3,mp4;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i<=m;i++){
		int x,y,k;
		cin >> k;
		x = (k-1)/n+1;
		y = k-(x-1)*n;
		if(++mp1[x]==n){
			printf("%d",i);
			return 0;
		}
		if(++mp2[y]==n){
			printf("%d",i);
			return 0;
		}
		if(++mp3[x+y]==n){
			printf("%d",i);
			return 0;
		}
		if(++mp4[x-y]==n){
			printf("%d",i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}

