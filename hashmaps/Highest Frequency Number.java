/*Highest Frequency Number

You are given with an array of integers that contain numbers in random order. Write a program to find and return the number which occurs maximum times in the given input.
If more than one element occurs same number of times in the input, return the element which is present in the input first.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Output Format :
Most frequent element
Constraints :
1 <= N <= 10^5
Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2
Sample Input 2 :
3
1 4 5
Sample Output 2 :
1
*/

import java.util.HashMap;
public class Solution {

	public static int maxFrequencyNumber(int[] arr){
		
		 int maxFreq=0;
      int num=0;
		HashMap<Integer,Integer>map=new HashMap<>();
      for(int i=0;i<arr.length;i++){
       
           if(map.containsKey(arr[i])){
             int oldValue=map.get(arr[i]);
              map.put(arr[i],oldValue+1);
           } else{
               map.put(arr[i],1);
             }
      if(maxFreq<map.get(arr[i])){
        maxFreq=map.get(arr[i]);
        num=arr[i];
      }
      //int maxFreq=0;
      //int num=0;
        //     for(int i:map.keySet()){
          //     int currentFreq=map.get(i);
         //      if(current)
           //    System.out.println(i);
             } 
      return num;
	}
}