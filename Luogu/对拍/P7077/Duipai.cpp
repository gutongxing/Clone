#include<bits/stdc++.h>
using namespace std;
int main(){
	cout << "正在编译文件：data.cpp" << endl;
	if(system("g++ data.cpp -o data -std=c++14")) return 0;
	cout << "编译完成" << endl;
	cout << "正在编译文件：force.cpp" << endl;
	if(system("g++ force.cpp -o force -std=c++14")) return 0;
	cout << "编译完成" << endl;
	cout << "正在编译文件：std.cpp" << endl;
	if(system("g++ std.cpp -o std -std=c++14")) return 0;
	cout << "编译完成" << endl;
	cout << "开始对拍" << endl;
    while (1){
//        system("data.exe > in.txt");
		double t=clock();
		if(system("data > in.txt")) return 0;
        if(system("force < in.txt > force.txt")) return 0;
		cout << "force 完成：" << clock()-t << "ms" << endl;
		t = clock();
		if(system("std < in.txt > std.txt")) return 0;
		cout << "std 完成：" << clock()-t << "ms" << endl;
		t = clock();
        if (system("fc std.txt force.txt"))return cout << "WA",0;
		cout << "AC" << endl;
    }
    return 0;
}
 
