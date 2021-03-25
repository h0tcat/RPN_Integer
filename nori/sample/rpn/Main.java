package nori.sample.rpn;

public class Main{
	public static void main(String[] args){
		if(args.length==1){
			RPN reversePolish=new RPN(args[0].split(" "));
			var result=reversePolish.Calc();
			System.out.println(result);
		}
	}
}
