//文件摘要：语法分析器
//曹晨瑶 17130130312
//2019.5.18

#include<iostream>
#include"lexer.hpp"
#include"error.hpp"
#include"sym.hpp"
#include"parser.hpp"

using namespace Lexer;

double Parser::prim(bool get){
	if(get)
        get_token();
	switch(curr_tok){
	    case NUMBER://数字
	{
		double v=number_value;
		get_token();
		return v;
	}
	case NAME:
	{
		double& v=Symbol_table::table[string_value];
		if(get_token()==ASSIGN)
            v=expr(true);
		    return v;
	}
	case MINUS:
		return -prim(true);
	case LP:
	{
		double e=expr(true);
		if(curr_tok != RP)
		    return Error::error(") expected.");
		get_token();
		return e;
	}
	case ERR:
	{
		//Lexer::skip();
		Error::error("ERR");
		while (Lexer::curr_tok != Lexer::PRINT)
			Lexer::get_token();
		return 11;
	}
	default:
		return Error::error("primary expected.");
	}
}

double Parser::term(bool get){
	double left=prim(get);
	for(;;)
		switch (curr_tok){
		case MUL:
			left *= prim(true);
			break;
		case DIV:
			if (double d = prim(true)){
				left /= d;
				break;
			}
			return Error::error("divide by 0.");//除数不为0
		default:
			return left;
		}
}

double Parser::expr(bool get){
	double left=term(get);
	for(;;)
		switch(curr_tok){
		case PLUS:
			left += term(true);
			break;
		case MINUS:
			left -= term(true);
			break;
		default:
			Error::error_line[Error::line] = 1;
			return left;
		}
}
