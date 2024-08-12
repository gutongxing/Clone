#include<bits/stdc++.h>
using namespace std;
int sum; 
signed main(){
	for(int i = 1;i<=9;i++){
		int x;
		cin >> x;
		sum+=x;
	}
	for(int i =  1;i<=8;i++){
		int x;
		cin >> x;
		sum-=x;
	}
	printf("%d",sum+1);
	return 0;
}
