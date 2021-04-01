#include "RPN.h"
#include <boost/algorithm/string/classification.hpp>

nori::RPN::RPN(std::string evalSrc){
	this->evalSrc=evalSrc;
	this->stack=new std::stack<std::string>();
	
	boost::split(this->tokens,this->evalSrc,boost::is_any_of(" "));
}

nori::RPN::~RPN(){
	delete this->stack;
}

double nori::RPN::Calc(){
	
	try{
	std::for_each(
			this->tokens.begin(),
			this->tokens.end(),
			[=](std::string token){
				if(std::equal(token.begin(),token.end(),"+")){
					this->calcTokenEnum=PLUS;
					calcToken(this->calcTokenEnum);
				}else if(std::equal(token.begin(),token.end(),"-")){
					this->calcTokenEnum=MINUS;
					calcToken(this->calcTokenEnum);
				}else if(std::equal(token.begin(),token.end(),"*")){
					this->calcTokenEnum=MUL;
					calcToken(this->calcTokenEnum);
				}else if(std::equal(token.begin(),token.end(),"/")){
					this->calcTokenEnum=DIV;
					calcToken(this->calcTokenEnum);
				}else{
					this->stack->push(token);
				}
			}
	);
	}catch(char* error){
		std::cout << error << std::endl;
	}

	double result=std::stod(this->stack->top());
	return result;
}

void nori::RPN::calcToken(CALCTOKEN_ENUM  calcProc){
	switch(calcProc){
		case PLUS:
			this->acumlator=stack->top();
			this->stack->pop();

			this->acumlator=std::to_string(std::stoi(this->stack->top())+std::stoi(acumlator));
			this->stack->pop();
			this->stack->push(this->acumlator);

			break;
		case MINUS:
			this->acumlator=stack->top();
			this->stack->pop();

			this->acumlator=std::to_string(std::stoi(this->stack->top())-std::stoi(acumlator));
			this->stack->pop();
			this->stack->push(this->acumlator);

			break;
		case MUL:
			this->acumlator=stack->top();
			this->stack->pop();

			this->acumlator=std::to_string(std::stoi(this->stack->top())*std::stoi(acumlator));
			this->stack->pop();
			this->stack->push(this->acumlator);

			break;
		case DIV:
			this->acumlator=stack->top();
			this->stack->pop();

			this->acumlator=std::to_string(std::stoi(this->stack->top())/std::stoi(acumlator));
			this->stack->pop();
			this->stack->push(this->acumlator);

			break;
	}
}
