import java.util.Scanner;

public class NumberPyramid {
	static void outputPyramid(int n, int k) {
		for (int i=0; i<n; i++) {
			if (i + 1 == k) {
				int sum = i + 1;
				System.out.print(sum);
				
				for (int j=0; j<i; j++) {
					sum = sum + n - (j + 1);
					System.out.print("*" + sum);
				}
				
				break;
			}
			else {
				continue;
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner inputReader = new Scanner(System.in);
		System.out.print("How many times to try? > ");
		int t = inputReader.nextInt();
		
		for(int i=0; i<t; i++) {
			System.out.print("How many lines to create? > ");
			int n = inputReader.nextInt();
			System.out.print("Enter a line number to print. > ");
			int k = inputReader.nextInt();
			
			outputPyramid(n, k);
			System.out.println();
		}
	}
}