//�ļ�ժҪ���ʷ�������
//�ܳ��� 17130130312
//2019.5.18
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

namespace Lexer{
	enum Token_value{
		NAME, NUMBER, END,ERR, PLUS = '+',
		MINUS = '-', MUL = '*', DIV = '/',
		PRINT = ';', ASSIGN = '=', LP = '(', RP = ')',
	};
	extern Token_value curr_tok;
	extern double number_value;
	extern string string_value;
	extern int no_of_errors;

	Token_value get_token();
	extern std::istream *input;  // ����ָ���׼�����豸���ļ���ָ��
	extern vector<std::string> fileNames;
	int parseCommandLine(int argc, char* argv[]);
	int switch_input();
	void  skip();
}

