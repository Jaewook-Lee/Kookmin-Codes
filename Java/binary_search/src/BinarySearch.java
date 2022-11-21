package binary_search;

import java.util.Scanner;

public class BinarySearch {
	
	static int iterateSearch(int[] array, int target) {
		int idx = -1;
		int leftIdx = 0;
		int rightIdx = array.length - 1;
		
		while(leftIdx <= rightIdx) {
			int midIdx = (leftIdx + rightIdx) / 2;
			
			if (array[midIdx] == target) {
				return midIdx;
			}
			else if (array[midIdx] > target) {
				rightIdx = midIdx - 1;
			}
			else {
				leftIdx = midIdx + 1;
			}
		}
		return idx;
	}

	static int binarySearch(int[] array, int target, int left, int right) {
		int idx = -1;
		
		if(left <= right) {
			int midIdx = (left + right) / 2;
			
			if(array[midIdx] == target) {
				return midIdx;
			}
			else if(array[midIdx] > target) {
				return binarySearch(array, target, left, midIdx-1);
			}
			else {
				return binarySearch(array, target, midIdx+1, right);
			}
		}
		
		return idx;
	}
	
	public static void main(String[] args) {
		int[] data = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
		int position = -1;
		Scanner inputScan = new Scanner(System.in);
		
		while(true) {
			System.out.print("Enter an integer number : ");
			int findNum = inputScan.nextInt();
			
			System.out.print("Choose method to use(1. Iterative    2. Recursive) : ");
			int choose = inputScan.nextInt();
			
			if(choose == 1) {
				position = iterateSearch(data, findNum);
			}
			else if(choose == 2) {
				position = binarySearch(data, findNum, 0, data.length-1);
			}
			else {
				System.out.println("Wrong Order!");
				continue;
			}
			
			if(position == -1) {
				System.out.println("Data NOT FOUND!");
				break;
			}
			else {
				System.out.println(findNum + " is at index " + position);
			}
		}
		
		inputScan.close();
		
	}
	
}
