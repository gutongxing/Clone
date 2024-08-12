#include<bits/stdc++.h>
using namespace std;
long long t,n,num;
string st; 
int main(){
	cin>>t;
	while(t--){
		stack<int> s; 
		cin>>n;
		while(n--){
			cin>>st;
			if(st=="push"){
				cin>>num;
				s.push(num);
			}else if(st=="pop"){
				if(s.empty())
				    cout<<"Empty"<<endl;
				else
				    s.pop();
			}else if(st=="query"){
				if(s.empty())
				    cout<<"Anguei!"<<endl;
				else
				    cout<<s.top();
			}else if(st=="size")
			    cout<<s.size()<<endl;
		}
	} 
	return 0;
}	 

