import java.util.Scanner;

public class NearestNumber {
	static int abs(int k) {
		if (k < 0) {
			return k * -1;
		}
		else {
			return k;
		}
	}
	
	static int closestNumber(int n, int m) {
		int postN = n - 1;
		int preN = n + 1;
		int nearNum = n;
		
		while (true) {
			if (postN % m != 0 && preN % m != 0) {
				postN = postN - 1;
				preN = preN + 1;
				continue;
			}
			else if (postN % m == 0 && preN % m == 0) {
				int tmpPost = abs(postN);
				int tmpPre = abs(preN);
				
				if (tmpPost > tmpPre) {
					nearNum = postN;
				}
				else {
					nearNum = preN;
				}
				break;
			}
			else if (postN % m == 0) {
				nearNum = postN;
				break;
			}
			else {
				nearNum = preN;
				break;
			}
		}
		
		return nearNum;
	}
	
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int t = reader.nextInt();
		for (int i=0; i<t; i++) {
			int n = reader.nextInt();
			int m = reader.nextInt();
			System.out.println(closestNumber(n, m));
		}
		reader.close();
	}
}
