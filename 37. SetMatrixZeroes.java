import java.util.Arrays;

public class setMatrixZeroes {

    public static void setZeroes(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;

        // We use first row/first column as marker storage.
        // These flags remember whether they originally had a zero,
        // because marker writes may overwrite that info.
        boolean firstRowZero = false;
        boolean firstColZero = false;

        // Check if first row needs to be zeroed in the final step.
        for (int c = 0; c < cols; c++) {
            if (matrix[0][c] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // Check if first column needs to be zeroed in the final step.
        for (int r = 0; r < rows; r++) {
            if (matrix[r][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // For each inner cell, if it is zero, mark its row and column
        // by setting the first element of that row/column to zero.
        for (int r = 1; r < rows; r++) {
            for (int c = 1; c < cols; c++) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }

        // Zero all marked rows (skip row 0 for now).
        for (int r = 1; r < rows; r++) {
            if (matrix[r][0] == 0) {
                for (int c = 1; c < cols; c++) {
                    matrix[r][c] = 0;
                }
            }
        }

        // Zero all marked columns (skip col 0 for now).
        for (int c = 1; c < cols; c++) {
            if (matrix[0][c] == 0) {
                for (int r = 1; r < rows; r++) {
                    matrix[r][c] = 0;
                }
            }
        }

        // Finally handle first row/first column based on original state.
        if (firstRowZero) {
            for (int c = 0; c < cols; c++) {
                matrix[0][c] = 0;
            }
        }

        if (firstColZero) {
            for (int r = 0; r < rows; r++) {
                matrix[r][0] = 0;
            }
        }
    }

    private static void printMatrix(int[][] matrix) {
        for (int[] row : matrix) {
            System.out.println(Arrays.toString(row));
        }
    }

    public static void main(String[] args) {
        int[][] matrix1 = {
            {1, 1, 1},
            {1, 0, 1},
            {1, 1, 1}
        };

        int[][] matrix2 = {
            {0, 1, 2, 0},
            {3, 4, 5, 2},
            {1, 3, 1, 5}
        };

        setZeroes(matrix1);
        setZeroes(matrix2);

        printMatrix(matrix1);
        System.out.println();
        printMatrix(matrix2);
    }
}
