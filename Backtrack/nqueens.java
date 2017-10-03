package Lecture9;

import java.util.ArrayList;

public class RecursionCtd {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int boardSize = 8;
		boolean[][] board = new boolean[boardSize][boardSize];

		System.out.println(countNQueens(board, 0));
		System.out.println(returnNQueens(board, 0));

	}

	public static int countNQueens(boolean[][] board, int row) {
		if (row == board.length) {
			return 1;
		}

		int count = 0;
		for (int col = 0; col < board[0].length; col++) {
			if (isItSafeToPlaceQueen(board, row, col)) {
				board[row][col] = true;
				
				int countOnThisPath = countNQueens(board, row + 1);
				count += countOnThisPath;
				
				board[row][col] = false;
			}
		}

		return count;
	}

	public static ArrayList<String> returnNQueens(boolean[][] board, int row) {
		if (row == board.length) {
			ArrayList<String> baseResult = new ArrayList<>();
			
			String result = "\n";
			for(int r = 0; r < board.length; r++){
				for(int c = 0; c < board[r].length; c++){
					if(board[r][c]){
						result += "[" + r + "-" + c + "], ";
					}
				}
			}
			result += "END\n";
			baseResult.add(result);
			
			return baseResult;
		}

		ArrayList<String> result = new ArrayList<>();
		for (int col = 0; col < board[0].length; col++) {
			if (isItSafeToPlaceQueen(board, row, col)) {
				board[row][col] = true;
				
				ArrayList<String> resultOnThisPath = returnNQueens(board, row + 1);
				result.addAll(resultOnThisPath);
				
				board[row][col] = false;
			}
		}

		return result;
	}

	public static boolean isItSafeToPlaceQueen(boolean[][] board, int row, int col) {
		// test col
		for (int i = row, j = col; i >= 0; i--) {
			if (board[i][j]) {
				return false;
			}
		}

		// test diag1
		for (int i = row, j = col; i >= 0 && j < board[row].length; i--, j++) {
			if (board[i][j]) {
				return false;
			}
		}

		// test diag2
		for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
			if (board[i][j]) {
				return false;
			}
		}

		return true;
	}

	
}
