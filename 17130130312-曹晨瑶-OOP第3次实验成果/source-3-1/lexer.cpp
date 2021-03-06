//文件摘要：词法分析器
//曹晨瑶 17130130312
//2019.5.18
#include<iostream>
#include<string>
#include"lexer.hpp"
#include"error.hpp"
#include"sym.hpp"
using namespace std;
using namespace Lexer;

Token_value Lexer::curr_tok = PRINT;
double Lexer::number_value;
string Lexer::string_value;
istream *Lexer::input;
vector<std::string> Lexer::fileNames;

Lexer::Token_value Lexer::get_token(){
	char ch;
	do {
		if (!(input->get(ch)))
		{  // 当前文件结束了，尝试打开下一文件
			if (switch_input() != 0)
				return curr_tok = END;
			else
			{
			//cout << ch << endl;
				ch = ' ';
				continue;
			}
		}
		//if (!cin.get(ch)) return curr_tok = END;
	} while (ch != '\n' && isspace(ch) && ch != ';');
	switch (ch) {
	case '\n': case ';':
		return curr_tok = PRINT;
	case '+': case '-': case '*': case '/':
	case '(': case ')': case '=':
		return curr_tok = Token_value(ch);
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		(*Lexer::input).putback(ch);
		(*Lexer::input) >> number_value;
		return curr_tok = NUMBER;
	default:
		if (isalpha(ch)) {
			string_value = ch;
			while ((*Lexer::input).get(ch) && isalnum(ch)) string_value.push_back(ch);
			    (*Lexer::input).putback(ch);
			    return curr_tok = NAME;
		}
		Error::error("ERR");
		return curr_tok = ERR;
	}
}

int Lexer::parseCommandLine(int argc, char* argv[])
{
	if (argc == 1){
            Lexer::input = &cin; return 0; }
	else{
		for(int i = 1; i < argc; ++i)
			fileNames.push_back(argv[i]);
		// 接着先打开第1个输入文件
		Lexer::input = new ifstream(fileNames[0].c_str());
		if(Lexer::input->good())
		{
			fileNames.erase(fileNames.begin());
			return 0;
		}
		else return 1;
	}
}

int Lexer::switch_input()
{
	if(fileNames.empty())
	{
	    return 1;
	}  /*没有文件了*/
	else{
		delete Lexer::input; //关闭上个文件，接着打开下个文件
		Lexer::input = new ifstream(fileNames[0].c_str());
		if (Lexer::input->good())
		{
			fileNames.erase(fileNames.begin());
			return 0;
		}
		else return 1;
	}
}

void Lexer::skip()
{
	Error::error_line[Error::line] = 1;
	Error::no_of_errors++;
	while((*Lexer::input))
	{
		char ch;
		Lexer::input->get(ch);
		switch(ch)
		{
		case  '\n':
		case  ';':
			Lexer::input->get(ch);
			return;
		}
	}
}
