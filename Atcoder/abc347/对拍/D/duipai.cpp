#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n = 0;
    while (1) //一直循环，直到找到不一样的数据
    {
		cout << ++n <<":";
        system("data.exe > in.txt");
        system("baoli.exe < in.txt > baoli.txt");
        system("d.exe.lnk < in.txt > std.txt");
        if (system("fc std.txt baoli.txt")) //当 fc 返回 1 时，说明这时数据不一样
            break;                          //不一样就跳出循环
    }
    return 0;
}

