/*Print Array intersection

Given two random integer arrays, print their intersection. That is, print all the elements that are present in both the given arrays.
Input arrays can contain duplicate elements.
Note : Order of elements are not important
Input format :
Line 1 : Integer N, Array 1 Size
Line 2 : Array 1 elements (separated by space)
Line 3 : Integer M, Array 2 Size
Line 4 : Array 2 elements (separated by space)
Output format :
Print intersection elements in different lines
Constraints :
1 <= M, N <= 10^6
Sample Input 1 :
6
2 6 8 5 4 3
4
2 3 4 7 
Sample Output 1 :
2 
4 
3
Sample Input 2 :
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
2 
2
1
*/

import java.util.HashMap;
public class Intersection{
	
	public static void intersection(int[] arr1, int[] arr2){
		
HashMap<Integer,Integer>map=new HashMap<>();
      for(int i=0;i<arr1.length;i++){
       
           if(map.containsKey(arr1[i])){
             int oldValue=map.get(arr1[i]);
               map.put(arr1[i],oldValue+1);
           } else{
               map.put(arr1[i],1);
             }}
              for(int j=0;j<arr2.length;j++){
                 if(map.containsKey(arr2[j])){
                  int freq=map.get(arr2[j]); 
           
             if(freq>0){
               System.out.println(arr2[j]);
               map.put(arr2[j],freq-1);
             }
           }
      
      }
}
}