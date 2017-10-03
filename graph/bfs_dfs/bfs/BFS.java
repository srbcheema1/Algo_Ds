/**
 * Input file example:
 *
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
 * 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
 *
 */

import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

class BFS {

    private static final String INPUT_FILE_PATH = "input.txt";

    private static final String OUTPUT_FILE_PATH = "output.txt";

    private static final int INF = Integer.MAX_VALUE / 2;

    private static int begin;

    public static void main(String[] args) {
        int[][] matrix = readMatrixFromFile();
        List<Integer> way = bfs(matrix);
        printSolution(way);
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

    private static List<Integer> bfs(int[][] matrix) {
        boolean[] used = new boolean[matrix.length];
        List<Integer> way = new ArrayList<>();
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(begin);

        while (!queue.isEmpty()) {
            int v = queue.poll();
            used[v] = true;
            way.add(v + 1);

            for (int nv = 0; nv < matrix.length; nv++) {
                if (!used[nv] && matrix[v][nv] != INF) {
                    queue.offer(nv);
                }
            }
        }
        return way;
    }

    private static void printSolution(List<Integer> way) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(OUTPUT_FILE_PATH))) {
            writer.write(Integer.toString(way.get(0)));

            for (int i = 1; i < way.size(); i++) {
                writer.write(" -> " + way.get(i));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}