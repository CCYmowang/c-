//文件摘要：语法分析器接口
//曹晨瑶 17130130312
//2019.5.18

#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

namespace Parser
{
	double prim(bool get);
	double term(bool get);
	double expr(bool get);
}
