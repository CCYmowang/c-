//�ļ�ժҪ������ģ�飬������������м���
//�ܳ��� 17130130312
//2019.5.18
#include<iostream>
#include<string>
#include"error.hpp"
#include"lexer.hpp"
#include"parser.hpp"
#include"sym.hpp"

using namespace std;

int main(int argc, char* argv[]){
    //���ļ�
	if (Lexer::parseCommandLine(argc, argv) != 0)
	{
		cerr << "�ļ��޷���" << endl;
		return 1;
	}
	//Ԥ�������
	Symbol_table::table["pi"] = 3.1415926535897932385;
	Symbol_table::table["e"] = 2.7182818284590452354;
	while (Lexer::END != Lexer::get_token()){
		if(Lexer::curr_tok == Lexer::END)
		    break;
		if(Lexer::curr_tok == Lexer::PRINT)
		    continue;
		if(Lexer::curr_tok == Lexer::ERR)
		{
			Lexer::skip();
			continue;
		}
	double  value = Parser::expr(false);
		Error::line++;
		switch(Lexer::curr_tok)
		{
		case Lexer::PRINT:
		case Lexer::END:
			cout << "Line:" << Error::line - 1 << " result is " << value << endl;
			continue;
		case Lexer::ERR:
			Lexer::skip();
			continue;
		default:
			Error::error("may need expression ending");
			Lexer::skip();
			continue;
		}
	}
	if(Lexer::input != &std::cin)
		delete Lexer::input;
	return 0;
}
