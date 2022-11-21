import java.util.Scanner;

public class MagicSquare {
	static int[][] magicSquare(int size) {
		int[][] intArray = new int[size][size];
		int val = 2;
		int row = 0;
		int col = size / 2;
		
		intArray[row][col] = 1;
		while (val <= size*size) {
			if (val % size == 1) {
				row += 1;
				intArray[row][col] = val;
				val += 1;
				continue;
			}
			
			if (row - 1 < 0) {
				row = size - 1;
			}
			else {
				row -= 1;
			}
			if(col -1 < 0) {
				col = size - 1;
			}
			else {
				col -= 1;
			}
			
			intArray[row][col] = val;
			val += 1;
		}
		
		return intArray;
	}
	
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int n = reader.nextInt();
		int[][] answer = magicSquare(n);
		
		for (int i=0; i<answer.length; i++) {
			for (int j=0; j<answer[i].length; j++) {
				System.out.print(answer[i][j] + " ");
			}
			System.out.println();
		}
		
		reader.close();
	}
}