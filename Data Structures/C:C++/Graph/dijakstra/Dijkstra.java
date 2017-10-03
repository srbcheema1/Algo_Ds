import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

/**
 * Input file example:
 *
 * 6
 * INF 7 9 INF INF 14
 * 7 INF 10 15 INF INF
 * 9 10 INF 11 INF 2
 * INF 15 11 INF 6 INF
 * INF INF INF 6 INF 9
 * 14 INF 2 INF 9 INF
 * 5 1
 *
 * First line is number of elements inn graph
 * Next n-lines is graph
 * Last line is begin and end point
 *
 * Output file:
 * Way from 5 to 1:
 * 5 -> 6 -> 3 -> 1
 * Length: 20
 *
 */
public class Dijkstra {

    private static final String INPUT_FILE_PATH = "input.txt";

    private static final String OUTPUT_FILE_PATH = "output.txt";

    private static final int INF = Integer.MAX_VALUE / 2;

    private static int begin;

    private static int end;

    public static void main(String[] args) {
        int[][] matrix = readMatrixFromFile();
        dijkstra(matrix);
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

            begin = scanner.nextInt();
            end = scanner.nextInt();
        } catch (IOException e) {
            e.printStackTrace();
        }

        return matrix;
    }

    private static void dijkstra(int[][] matrix) {
        boolean[] used = new boolean[matrix.length];
        int[] dist = new int[matrix.length];
        int[] way = new int[matrix.length];

        begin -= 1;
        end -= 1;

        Arrays.fill(dist, INF);
        Arrays.fill(way, 0);
        dist[begin] = 0;

        while (true) {
            int v = -1;
            for (int nv = 0; nv < matrix.length; nv++) {
                if (!used[nv] && (v == -1 || dist[nv] < dist[v])) {
                    v = nv;
                }
            }

            if (v == -1) {
                break;
            }

            used[v] = true;

            for (int nv = 0; nv < matrix.length; nv++) {
                if (!used[nv] && matrix[v][nv] + dist[v] < dist[nv]) {
                    dist[nv] = matrix[v][nv] + dist[v];
                    way[nv] = v;
                }
            }
        }

        printSolution(way, dist);
    }

    private static void printSolution(int[] trip, int[] dist) {
        Stack<Integer> stack = new Stack<>();
        StringBuilder answer = new StringBuilder();
        answer.append(String.format("Way from %d to %d:\n", begin + 1, end + 1));

        int lastPoint = end;

        while (lastPoint != begin) {
            stack.push(lastPoint);
            lastPoint = trip[lastPoint];
        }

        answer.append(begin + 1);
        while (!stack.isEmpty()) {
            answer.append(" -> ").append(stack.pop() + 1);
        }

        answer.append(String.format("\nLength: %d\n", dist[end]));

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(OUTPUT_FILE_PATH))) {
            writer.write(answer.toString());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
