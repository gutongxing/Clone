#include<bits/stdc++.h>
using namespace std;
int main()
{
    while (1) //一直循环，直到找到不一样的数据
    {
//        system("data.exe > in.txt");
        system("force.exe < in.txt > force.txt");
        system("std.lnk < in.txt > std.txt");
        if (system("fc std.txt force.txt")) //当 fc 返回 1 时，说明这时数据不一样
            break;                          //不一样就跳出循环
    }
    return 0;
}
 
