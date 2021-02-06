import java.util.*;
import java.lang.*;
import java.io.*;

public class main {
	public static void main(String [] args) throws IOException {
	BufferedReader br = new BufferedReader(
			    new InputStreamReader(System.in)); //use buffer reader instead of scanf because I'm cool
	int keyPad = 2; //this is the pad that a letter will be assigned too start from 2 because no letters assigned to 1	
	int subPad = 1; //how many time to press the key bad; max up to 3 most of the keys only store 3 letters the exception is the 7th and the 9th key
	Map<String, String> dic = new HashMap<String,String>();

	dic.put(" ","0");
	for (char key = 'a'; key <='y'; ++key) {//this will allow cycling of ascii chars...
		dic.put(String.valueOf(key), String.valueOf(keyPad).repeat(subPad));
		if (subPad > 2) {
			if (keyPad == 7 && subPad < 4) { //to allow the 7th key to hold 4 letters...
				subPad++;
			} else {
				subPad = 1;
				keyPad++; 
			}
		} else {
			subPad++;
		}
	}
	dic.put("z", "9999"); //hardcode the last letter in because its easier than adding the acception like the 7th key

	int numLines = Integer.parseInt(br.readLine());	//to count how many lines we are to take in
	String outputStr = "";
	String keypressStr = "";
	String input[] = new String[365]; //store all  the strings to parse
	for(int i = 0; i < numLines; i++) {
		input[i] = br.readLine();	
	}
	for(int i = 0; i < numLines; i++) { //parsing
		char[] inputArr = input[i].toCharArray();	
		for(char letter : inputArr) {
			keypressStr = dic.get(String.valueOf(letter));
			if((!outputStr.isEmpty()) && (outputStr.charAt(outputStr.length() - 1) == keypressStr.charAt(0))){ //to add a space when we have to use the same key again
				outputStr = outputStr + " ";
				outputStr = outputStr + keypressStr;
			}else{
				outputStr = outputStr + keypressStr;
			}
		} 
		System.out.print("Case #" + String.valueOf(i + 1) + ": " + outputStr + "\n");
		outputStr = "";
}
}
}
