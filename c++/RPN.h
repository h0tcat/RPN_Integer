#ifndef __RPN_H__
#define __RPN_H__

#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <boost/algorithm/string/classification.hpp>


namespace nori{
	class RPN{
		public:
			RPN(std::string evalSrc);

			~RPN();
			double Calc();

		protected:
			std::string evalSrc,acumlator;
			std::vector<std::string> tokens;

			std::stack<std::string>* stack;
			
			typedef enum{
				PLUS=1,
				MINUS=2,
				MUL=3,
				DIV=4
			}CALCTOKEN_ENUM;
			CALCTOKEN_ENUM calcTokenEnum;

			void calcToken(CALCTOKEN_ENUM calcProc);
	};
};

#endif
