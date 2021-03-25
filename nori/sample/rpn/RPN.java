package nori.sample.rpn;

import java.util.*;
class RPN<T>{

	String[] evalSrc;
	public RPN(String[] evalSrc){
		this.evalSrc=evalSrc;
	}

	public String Calc(){

		String acumLator="";
		Stack<String> stack=new Stack<String>();
		for(String x : this.evalSrc){
			switch(x){
				case "+":
					try{
						acumLator=stack.pop().toString();
						acumLator=String.valueOf(Integer.parseInt(stack.pop())+Integer.parseInt(acumLator));
						stack.push(acumLator);
					}catch(NumberFormatException numE){

						acumLator=stack.pop().toString();
						acumLator=String.valueOf(Double.parseDouble(stack.pop())+Double.parseDouble(acumLator));
						stack.push(acumLator);
					}
					break;
				case "-":
					try{
						acumLator=stack.pop().toString();
						acumLator=String.valueOf(Integer.parseInt(stack.pop())-Integer.parseInt(acumLator));
						stack.push(acumLator);
					}catch(NumberFormatException numE){

						acumLator=stack.pop().toString();
						acumLator=String.valueOf(Double.parseDouble(stack.pop())-Double.parseDouble(acumLator));
						stack.push(acumLator);
					}
					break;
				case "*":
					try{
						acumLator=stack.pop().toString();
						acumLator=String.valueOf(Integer.parseInt(stack.pop())*Integer.parseInt(acumLator));
						stack.push(acumLator);
					}catch(NumberFormatException numE){

						acumLator=stack.pop().toString();
						acumLator=String.valueOf(Double.parseDouble(stack.pop())*Double.parseDouble(acumLator));
						stack.push(acumLator);
					}
					break;
				case "/":
					try{
						acumLator=stack.pop().toString();
						acumLator=String.valueOf(Integer.parseInt(stack.pop())/Integer.parseInt(acumLator));
						stack.push(acumLator);
					}catch(NumberFormatException numE){

						acumLator=stack.pop().toString();
						acumLator=String.valueOf(Double.parseDouble(stack.pop())/Double.parseDouble(acumLator));
						stack.push(acumLator);
					}
					break;
				default:
					stack.push(String.valueOf(x));
			}
		}
		var result=stack.pop();
		return result;
	}
}
