#include<bits/stdc++.h>
using namespace std;
signed main(){
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		if(i%3){
			putchar('o');
		}else putchar('x');
	}
	return 0;
}
