/**
 * Input file example:
 *
 * 8
 * INF 1 1 INF INF INF INF INF
 * 1 INF INF 1 1 INF INF INF
 * 1 INF INF INF INF 1 1 INF
 * INF 1 INF INF INF INF INF INF
 * INF 1 INF INF INF INF INF 1
 * INF INF 1 INF INF INF INF INF
 * INF INF 1 INF INF INF INF INF
 * INF INF INF INF 1 INF INF INF
 * 1
 *
 * First line is number of elements in graph
 * Next n-lines is graph
 * Last line is begin point
 *
 * Output file:
 * 1 -> 2 -> 4 -> 5 -> 8 -> 3 -> 6 -> 7
 *
 */

package dfs;

import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class DFS {

    private static final String INPUT_FILE_PATH = "input.txt";

    private static final String OUTPUT_FILE_PATH = "output.txt";

    private static final int INF = Integer.MAX_VALUE / 2;

    private static boolean used[];

    private static int begin;

    public static void main(String[] args) {
        int[][] matrix = readMatrixFromFile();
        used = new boolean[matrix.length];
        String answer = dfs(matrix, begin);
        printSolution(answer);
    }

    private static int[][] readMatrixFromFile() {
        int[][] matrix = null;

        try (Scanner scanner = new Scanner(new FileInputStream(INPUT_FILE_PATH))) {
            int matrixSize = Integer.parseInt(scanner.nextLine());
            matrix = new int[matrixSize][matrixSize];

            for (int row = 0; row < matrixSize; row++) {
                String[] numbers = scanner.nextLine().split(" ");
                for (int col = 0; col < matrixSize; col++) {
                    if (numbers[col].equals("INF")) {
                        matrix[row][col] = INF;
                    } else {
                        matrix[row][col] = Integer.parseInt(numbers[col]);
                    }
                }
            }

            begin = scanner.nextInt() - 1;
        } catch (IOException e) {
            e.printStackTrace();
        }

        return matrix;
    }

    private static String dfs(int[][] matrix, int v) {
        StringBuilder answer = new StringBuilder();

        used[v] = true;
        answer.append(v + 1).append(" ");
        for (int nv = 0; nv < matrix.length; nv++) {
            if (!used[nv] && matrix[v][nv] != INF) {
                answer.append(dfs(matrix, nv));
            }
        }

        return answer.toString();
    }

    private static void printSolution(String answer) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(OUTPUT_FILE_PATH))) {
            String[] points = answer.split(" ");
            writer.write(points[0]);

            for (int i = 1; i < points.length; i++) {
                writer.write(" -> " + points[i]);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
