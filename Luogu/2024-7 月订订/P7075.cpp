#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
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
bool run(int k){
	if(k%100==0) return k%400==0;
	return k%4==0;
}
int months[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int julian = 2299160;
void write_date(int year,int month,int day){
	write(day,' ');write(month,' ');
	if(year<=0){
		year = abs(year)+1;
		write(year,' ');
		puts("BC");
	}else{
		write(year,'\n');
	}
}
void Code_for_get(){
	int sum = 0;
	for(int i = -4712;i<=1581;i++){
		sum += (i%4==0?366:365);
	}
	cout << sum << endl;
	for(int i = 1;i<=9;i++) sum += months[i];
	cout << sum << endl;
	cout << sum+3 << endl;
}
signed main(){
	freopen("P7075_6.in","r",stdin);
	freopen("julian.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	Code_for_get();
	int T;
	read(T);
	while(T--){
		int x;
		read(x);
		if(x<=julian){
			int year = -4712;
			year += x/1461*4;
			x = x%1461;
			while(x>=0){
				x -= (year%4==0?366:365);
				year++;
			}
			x += ((--year)%4==0?366:365);
			int month = 1;
			while(x>=0){
				x -= months[month]+(month==2&&year%4==0?1:0);
				month++;
			}
			month--;
			x += months[month]+(month==2&&year%4==0?1:0);
			write_date(year,month,x+1);
		}else{
			x -= julian;x--;
			int year = 1582;
			int month = 10;
			int day = 15;
			x -= 17;
			if(x<=0){
				x += 17;
				write_date(year,month,day+x-1);
				continue;
			}
			month = 11;
			day = 1;
			while(x>=0&&month<=12){
				x -= months[month];
				month++;
			}
			if(x<0){
				month--;
				x += months[month];
				write_date(year,month,x+1);
				continue;
			}
			month = 1;
			year ++;
			year += x/146097*400;
			x = x%146097;
			while(x>=0){
				x -= (run(year)?366:365);
				year++;
			}
			x += (run(--year)?366:365);
			while(x>=0){
				x -= months[month]+(month==2&&run(year)?1:0);
				month++;
			}
			month--;
			x += months[month]+(month==2&&run(year)?1:0);
			write_date(year,month,x+1);
		}
	}
	return 0;
}
