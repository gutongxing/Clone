#include<bits/stdc++.h>
using namespace std;
int main()
{
    while (1) //һֱѭ����ֱ���ҵ���һ��������
    {
//        system("data.exe > in.txt");
        system("force.exe < in.txt > force.txt");
        system("std.lnk < in.txt > std.txt");
        if (system("fc std.txt force.txt")) //�� fc ���� 1 ʱ��˵����ʱ���ݲ�һ��
            break;                          //��һ��������ѭ��
    }
    return 0;
}
 
