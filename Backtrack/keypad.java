package lecture8;

import java.util.ArrayList;

public class keypad {

	public static void main(String[] args) {

	}
	public static String getcod(char c){
		String result="";
		switch (c){
		case '1':
			result="abc";
			break;
		case '2':
			result="def";
			break;
		case '3':
			result="ghi";
			break;
		case '4':
			result="jkl";
			break;
		case '5':
			result="mno";
			break;
		case '6':
			result="pqr";
			break;
		case '7':
			result="stu";
			break;
		case '8':
			result="vwx";
			break;
		case '9':
			result="xy";
			break;
		}
	return result; }
	public static ArrayList<String> keypad(String s) {
		int counter = 0;
		if (s.length() == 1) {
			ArrayList<String> base = new ArrayList<>();
			base.add(s);
			return base;
		}
		ArrayList<String> al = keypad(s.substring(1));
		ArrayList<String> result = new ArrayList<>();
		for (int i = 0; i < al.size(); i++) {
			String item = al.get(i);
			String k = "";
			for (int j = 0; j <= item.length(); j++) {
				k = item.substring(0, j);
				k = k + s.charAt(0);
				k = k + item.substring(j);

					result.add(k);
					counter = 0;
				
			}
		}
		return result;
	}

}
