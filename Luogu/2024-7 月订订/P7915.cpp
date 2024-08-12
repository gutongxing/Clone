#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
//Fast IO
void read(int &x){
	x = 0;int h = 1;char tmp;
	do{tmp=getchar();if(tmp=='-')h*=-1;}while(!isdigit(tmp));
	while(isdigit(tmp)) x*=10,x+=tmp-'0',tmp=getchar();
	x*=h;
}
void read(char &x){do{x=getchar();}while(x==' '||x=='\n'||x=='\r');}
void write(char x){putchar(x);}
void write(int x){
	if(x<0) putchar('-'),x=-x;int st[200]={0},tot=0;
	do{st[++tot]=x%10,x/=10;} while(x);
	while(tot){putchar(st[tot--]+'0');};
}
void write(int x,char y){write(x);write(y);}
const int ttttttttttttmmmmmmmmmmmmmmmmpppppppppppppppp = 5e5+10;
const int MAXN = ttttttttttttmmmmmmmmmmmmmmmmpppppppppppppppp<<1;
int T,n,a[MAXN];
bool checkl(){
    list<int> st1,st2;
    int pos = 2;
    while(pos<=2*n){
        if(a[pos]==a[1]) break;
        st1.push_back(a[pos++]);
    }
	pos++;
    while(pos<=2*n){
        st2.push_front(a[pos++]);
    }
    string ans1 = "L",ans2 = "";
    while(!st1.empty()&&!st2.empty()){
        if(*st1.begin()==*st1.rbegin()&&st1.size()>1){
            ans1 += 'L';
            ans2 += 'L';
            st1.pop_front();
            st1.pop_back();
        }else if(*st1.begin()==*st2.rbegin()){
            ans1 += 'L';
            ans2 += 'R';
            st2.pop_back();
            st1.pop_front();
        }else if(*st2.begin()==*st1.rbegin()){
            ans1 += 'R';
            ans2 += 'L';
            st1.pop_back();
            st2.pop_front();
        }else if(*st2.begin()==*st2.rbegin()&&st2.size()>1){
            ans1 += 'R';
            ans2 += 'R';
            st2.pop_back();
            st2.pop_front();
        }else return false;
    }
    while(!st1.empty()){
        if(*st1.begin()==*st1.rbegin()){
            ans1 += 'L';
            ans2 += 'L';
            st1.pop_front();
            st1.pop_back();
        }else return false;
    }
    while(!st2.empty()){
        if(*st2.begin()==*st2.rbegin()){
            ans1 += 'R';
            ans2 += 'R';
            st2.pop_back();
            st2.pop_front();
        }else return false;
    }
    cout << ans1+string(ans2.rbegin(),ans2.rend())+'L' << endl;
    return true;
}
bool checkr(){
    list<int> st1,st2;
    int pos = 1;
    while(pos<2*n){
        if(a[pos]==a[2*n]) break;
        st1.push_back(a[pos++]);
    }
	pos++;
    while(pos<2*n){
        st2.push_front(a[pos++]);
    }
    string ans1 = "R",ans2 = "";
    while(!st1.empty()&&!st2.empty()){
        if(*st1.begin()==*st1.rbegin()&&st1.size()>1){
            ans1 += 'L';
            ans2 += 'L';
            st1.pop_front();
            st1.pop_back();
        }else if(*st1.begin()==*st2.rbegin()){
            ans1 += 'L';
            ans2 += 'R';
            st2.pop_back();
            st1.pop_front();
        }else if(*st2.begin()==*st1.rbegin()){
            ans1 += 'R';
            ans2 += 'L';
            st1.pop_back();
            st2.pop_front();
        }else if(*st2.begin()==*st2.rbegin()&&st2.size()>1){
            ans1 += 'R';
            ans2 += 'R';
            st2.pop_back();
            st2.pop_front();
        }else return false;
    }
    while(!st1.empty()){
        if(*st1.begin()==*st1.rbegin()){
            ans1 += 'L';
            ans2 += 'L';
            st1.pop_front();
            st1.pop_back();
        }else return false;
    }
    while(!st2.empty()){
        if(*st2.begin()==*st2.rbegin()){
            ans1 += 'R';
            ans2 += 'R';
            st2.pop_back();
            st2.pop_front();
        }else return false;
    }
    cout << ans1+string(ans2.rbegin(),ans2.rend())+'L' << endl;
    return true;
}
signed main(){
//	freopen("palin2.in","r",stdin);
//	freopen("palin2.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1;i<=2*n;i++){
            cin >> a[i];
        }
        if(!checkl()&&!checkr()){
            cout << -1 << endl;
        }
    }
	return 0;
}
