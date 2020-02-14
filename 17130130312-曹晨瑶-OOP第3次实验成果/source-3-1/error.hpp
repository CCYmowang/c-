//文件摘要：错误处理器接口
//曹晨瑶17130130312
//2019.5.18
#include<iostream>
#include<string>
using namespace std;

namespace Error
 {
    extern int line;
    extern int error_line[100];
	extern int no_of_errors;
	double error(const string& s);

}
