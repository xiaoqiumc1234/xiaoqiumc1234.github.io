#include <math.h>
#include <iostream>
#include <cstdlib>
#include <clocale>
using namespace std;

char table[] = "fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";
int tr[58] = { 0 };

int s[] = { 11, 10, 3, 8, 4, 6 };
long long _xor = 177451812;
long long _add = 8728348608;

long long dec(string x)
{
	for (int i = 0; i < 58; i++)
		tr[(int)table[i]] = i;
	long long r = 0;
	for (int i = 0; i < 6; i++)
		r += tr[x[s[i]]] * (long long)pow(58,i);
	return (r - _add)^_xor;
}


string enc(long long x)
{
	x = (x^_xor)+_add;
	string r = "BV1  4 1 7  ";
	for (int i = 0; i < 6; i++)
		r[s[i]] = table[(int)(x / (long long)pow(58, i) % 58)];

	return r;
}

string pretoupper(string x){
	int len = x.length();
	for(int i = 0; i < 2; i++){
		if(islower(x[i])) x[i] = toupper(x[i]);
	}
	
	return x;
}

int main()
{
	string str;
	system("title av号与bv号互转") ; 
	cout << "请输入一个av号或bv号：";
	cin >> str;
	if(str.length() <= 2) goto inputerr;
	str = pretoupper(str);
	if(str[0] == 'A' && str[1] == 'V'){//av
		string sub = str.substr(2);
		long long num = _atoi64(sub.c_str());
		
		cout << "对应的bv号为：" << enc(num) << endl;
	}
	else if(str[0] == 'B' && str[1] == 'V'){
		cout << "对应的av号为：av" << dec(str) << endl;
	} //bv

	else 
inputerr:
	cout << "输入不合法！请输入av或bv开头的合法字符串！" << endl;//illegal input
	
	cout << "请按[enter]键继续..." << endl;
	getchar();
	getchar();
}

