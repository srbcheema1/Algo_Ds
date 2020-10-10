import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.Stack;

class parenthesisChecker {
	public static void main (String[] args) {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		    try{
		            //int n=Integer.parseInt(br.readLine());
		        	String s=br.readLine().trim();
		        	Stack<Character> sc=new Stack<>();
		        	int i=0;
		        	int n=s.length();
		        	boolean b=true;
		        	for(i=0;i<n;i++){
		        	    if(s.charAt(i)=='('|| s.charAt(i)=='[' || s.charAt(i)=='{'){
		        	        sc.push(s.charAt(i));
		        	    }
		        	    else{
		        	        if(sc.size()==0){
		        	            b=false;
		        	            break;
		        	        }
		        	        else{
		        	            char top=sc.peek();
		        	            if(s.charAt(i)==')' && top=='('){
		        	                sc.pop();
		        	            }
		        	            else if(s.charAt(i)==']' && top=='['){
		        	                sc.pop();
		        	            }
		        	            else if(s.charAt(i)=='}' && top=='{'){
		        	                sc.pop();
		        	            }
		        	            else{
		        	                b=false;
		        	                break;
		        	            }
		        	        }
		        	    }
		        	}
		        	if(sc.size()!=0 || b==false){
		        	    System.out.println("not balanced");
		        	}
		        	else{
		        	    System.out.println("balanced");
		        	} 
		        
		    }catch(IOException e){
		        System.out.println(e.getMessage());
		    }
		    finally{
		        try{
		            br.close();
		           // System.out.println("hiii");
		        }
		        catch(IOException e){
		        System.out.println(e.getMessage());
		    }
		    }
	}
}

/*
  Time Complexity - O(N)
  Space Complexity - O(N)
  
  Input - 
  {([])}
  Output - 
  balanced
*/
