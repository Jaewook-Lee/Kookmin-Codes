package recursive_operation;

import java.util.Scanner;

public class Operations {
	static void recursiveAdd(int n, int m) {
		// System.out.println("N : " + n + ", M : " + m);
		int sum;
		
		if(n == 0) {
			sum = n + m;
			System.out.println("Addition result is : " + sum);
		}
		else {
			n -= 1;
			m += 1;
			recursiveAdd(n, m);
		}	
	}
	
	static void recursiveDiff(int n, int m) {
		// System.out.println("N : " + n +  " M : " + m);
		int diff;
		
		if(n == 0) {
			diff = n - m;
			System.out.println("Difference result is : " + diff);
		}
		else {
			n -= 1;
			m -= 1;
			recursiveDiff(n, m);
		}
	}
	
	static int rangeSum(int n) {
		if(n == 1) {
			return 1;
		}
		else {
			return n + rangeSum(n-1);
		}
	}
	
	public static void main(String[] args) {
		Scanner inputScan = new Scanner(System.in);
		
		System.out.print("First number : ");
		int num1 = inputScan.nextInt();
		System.out.print("Second number : ");
		int num2 = inputScan.nextInt();
		recursiveAdd(num1, num2);
		recursiveDiff(num1, num2);
		
		System.out.print("Enter a number : ");
		int num3 = inputScan.nextInt();
		int result = rangeSum(num3);
		String printString = "";
		
		for(int i=num3; i>0; i--) {
			if(i == 1) {
				printString += (i + " = ");
			}
			else {
				printString += (i + " + ");
			}
		}
		
		System.out.println(printString + result);
		
		inputScan.close();	
	}
	
}
