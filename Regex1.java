/*
 * This program looks for the variable 'a' and replaces it with 'A' but doesn't affect anything else that has an 'a' in it.
 *  In line 14, in the string to replace the pattern with, there is $1 and $2, which refer to 
 *  group 1 and 2(the contents inside parentheses in the regular expression) respectively.  
 */

import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Regex1 {
	public static void main(String[] args) {
		Pattern pt = Pattern.compile("([^a-zA-Z])a([^a-zA-Z])");
		Matcher mt = pt.matcher("((a*e*(math.cos(ai+la))^(2))/(l))+((a*12*e*i*(math.sin(ai+ni))^(2))/(l^(3)))...");
		
		System.out.println(mt.replaceAll("$1A$2"));
	}
}
