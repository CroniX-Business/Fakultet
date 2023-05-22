package zad5;

import java.util.Scanner;

public class Matrix {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int M;
        do {
            System.out.print("Unesite broj M (2-10): ");
            M = input.nextInt();
        } while (M < 2 || M > 10);

        int[][] matrix = new int[M][M];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                matrix[i][j] = input.nextInt();
            }
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }

        for (int i = 0; i < M; i++) {
            final int row = i;
            int finalM = M;
            new Thread(() -> {
                int max = Integer.MIN_VALUE;
                for (int j = 0; j < finalM; j++) {
                    if (matrix[row][j] > max) {
                        max = matrix[row][j];
                    }
                }
                System.out.println("Nit" + (row + 1) + " je završila s radom, najveći broj u retku je: " + max);
            }).start();
        }
    }
}
