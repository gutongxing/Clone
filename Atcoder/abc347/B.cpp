#include<bits/stdc++.h>
using namespace std;
int len = 0;
string str;
map<string,bool> mp;
signed main(){
	cin >> str;
	for(int i = 0;i<str.size();i++){
		for(int j = 1;;j++){
			if(i+j-1<str.size()){
				mp[str.substr(i,j)] = 1;
			}else break;
		}
	}
	printf("%d",mp.size());
	return 0;
}

