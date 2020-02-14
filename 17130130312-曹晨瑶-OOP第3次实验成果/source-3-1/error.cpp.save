//文件摘要：错误处理器
// 曹晨瑶 17130130312
//2019.5.18

#include"error.hpp"
#include"lexer.hpp"
#include"parser.hpp"
using namespace std;

int Error::no_of_errors = 0;
int Error::line = 1;
int Error::error_line[100] = {0};

double Error::error(const string& s) {
	no_of_errors++;
	cerr << "line：" << Error::line << " has " << "error: " << s << endl;
	Error::error_line[Error::line] = 1;
	return 11;
}
