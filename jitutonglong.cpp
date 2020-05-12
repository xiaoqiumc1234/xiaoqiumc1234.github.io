#include<iostream>
#include<string>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{
	int x, y, z, u;
    //x=头
    //y=脚
	x = 35;
	y = 94;
	z = 2 * x - y / 2;
	u = y / 2 - x;
	cout << "鸡有" << z << "兔有" << u << endl;
	return 0;
}