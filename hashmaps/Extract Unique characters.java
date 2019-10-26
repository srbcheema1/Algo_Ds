/*Extract Unique characters
Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.
Input format :
String S
Output format :
Output String
Constraints :
1 <= Length of S <= 50000
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde
*/

public class solution {

	public static String uniqueChar(String str){
		// Write your code here
 String temp = "";
         for (int i = 0; i < str.length(); i++){
            if (temp.indexOf(str.charAt(i)) == - 1){
               temp = temp + str.charAt(i);
         }
      }

    return temp ;
    
	}
}
