import java.io.FileReader;
import java.io.IOException;

public class WordCount {
	static int count(String fileName) {
		FileReader reader = null;
		int words = 0;
		
		try {
			reader = new FileReader(fileName);
			int c;
			
			while((c = reader.read()) != -1) {
				if(c == 32 || c == 10) {    //32 -> " ", 10 -> change line.
					words += 1;
				}
				else {
					continue;
				}
			}
			
			reader.close();
		}
		catch(IOException e) {
			words = -1;
			System.out.println("I/O Error!");
		}
		
		return words;
	}
	
	public static void main(String[] args) {
		int wordNum = count("lab0-1.dat");
		System.out.println(wordNum);
	}
	
}
