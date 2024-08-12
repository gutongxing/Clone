#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("PZ.cpp","r",stdin);
	freopen("OUT.cpp","w",stdout);
	char tmp = getchar();
	cout << "\t\t\"";
	while(tmp!=EOF){
		if(tmp=='\n'){
			cout << "\",";
			cout << '\n';
			cout << "\t\t\"";
		}else if(tmp=='\t'){
			cout << "\\t";
		}else if(tmp=='\"'){
			cout << "\\\"";
		}else if(tmp=='\\'){
			cout << "\\\\";
		}else{
			cout << tmp;
		}
		tmp=getchar();
	}
	return 0;
}
