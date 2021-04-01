#include "RPN.h"

int main(int argc,char** argv){
	
	if(argc!=2){
		std::cerr << "Usage: RPNSample evalText" << std::endl;
		return -1;
	}else{
		std::string evalSrc=argv[1];
		nori::RPN RPN(evalSrc);

		double result=RPN.Calc();

		std::cout << result << std::endl;
	}
	return 0;
}
