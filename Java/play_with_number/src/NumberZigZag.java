import java.util.Scanner;

public class NumberZigZag {
	static void outputZigZag(int n, int k) {
		int sum = 0;
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<=i; j++) {
				sum = sum + 1;
				
				if(i == k - 1) {
					if (i % 2 == 0) {
						System.out.print(sum);
					}
					else {
						System.out.print(sum + (i - 2 * j));
					}
					
					if (j < i) {
						System.out.print("*");
					}
				}
			}
		}
		System.out.println();
	}
	
	public static void main(String args[]) {
		Scanner reader = new Scanner(System.in);
		int t = reader.nextInt();
		for (int i=0; i<t; i++) {
			int n = reader.nextInt();
			int k = reader.nextInt();
			
			outputZigZag(n, k);
		}
		reader.close();
	}
}
