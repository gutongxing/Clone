#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n = 0;
    while (1) //һֱѭ����ֱ���ҵ���һ��������
    {
		cout << ++n <<":";
        system("data.exe > in.txt");
        system("baoli.exe < in.txt > baoli.txt");
        system("d.exe.lnk < in.txt > std.txt");
        if (system("fc std.txt baoli.txt")) //�� fc ���� 1 ʱ��˵����ʱ���ݲ�һ��
            break;                          //��һ��������ѭ��
    }
    return 0;
}

