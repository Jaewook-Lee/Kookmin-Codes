import java.io.FileReader;
import java.io.IOException;

public class InputOutput {
	public static void main(String[] args) {
		FileReader reader = null;
		String chars = "";
		String nums = "";
		
		try {
			reader = new FileReader("lab0-1.dat");
			int c;
			
			while((c = reader.read()) != -1) {
				
				if(c == 32 || c == 10) {
					nums += "*";
				}
				else {
					nums += (c + ",");
				}

				chars += (char)c;
			}
			
			reader.close();
		}
		catch(IOException e) {
			System.out.println("I/O Error!");
		}
		
		System.out.println(chars);
		System.out.println(nums);
	}
}
