#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define N 4

int	isValid(int matrix[N][N], int row, int col, int num)
{
	int i = 0;
	while (i < N) 
	{
		if (matrix[row][i] == num || matrix[i][col] == num)
		{
			return 0;
		}
 		i++;
	}
	return 1;
}

void printMatrix(int matrix[N][N])
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			char num_char = matrix[i][j] + '0'; // Convertir número a carácter
			write(STDOUT_FILENO, &num_char, 1); // Escribir un carácter
			if (j != N - 1)
			{
				write(STDOUT_FILENO, " ", 1); // Espacio entre números
			}
			j++;
		}
		write(STDOUT_FILENO, "\n", 1); // Nueva línea al final de la fila
		i++;
	}
}

int	checkClues(int matrix[N][N], int clues[4][N])
{
	int i = 0;
	while (i < N) {
		int	maxTop;
		int	maxBottom;
		int	maxLeft
		int	maxRight;
		int countTop = 0, countBottom = 0, countLeft = 0, countRight = 0;
        int j = 0;
        while (j < N) {
            if (matrix[i][j] > maxTop) {
                maxTop = matrix[i][j];
                countTop++;
            }
            if (matrix[i][N-j-1] > maxBottom) {
                maxBottom = matrix[i][N-j-1];
                countBottom++;
            }
            if (matrix[j][i] > maxLeft) {
                maxLeft = matrix[j][i];
                countLeft++;
            }
            if (matrix[N-j-1][i] > maxRight) {
                maxRight = matrix[N-j-1][i];
                countRight++;
            }
            j++;
        }
        if (clues[0][i] != countTop || clues[1][i] != countBottom || clues[2][i] != countLeft || clues[3][i] != countRight) {
            return 0;
        }
        i++;
    }
    return 1;
}
void swapMatrixValues(int matrix[N][N]) {
    int temp;

    temp = matrix[0][1];
    matrix[0][1] = matrix[1][0];
    matrix[1][0] = temp;

    temp = matrix[0][2];
    matrix[0][2] = matrix[2][0];
    matrix[2][0] = temp;

    temp = matrix[0][3];
    matrix[0][3] = matrix[3][0];
    matrix[3][0] = temp;

    temp = matrix[1][2];
    matrix[1][2] = matrix[2][1];
    matrix[2][1] = temp;

    temp = matrix[1][3];
    matrix[1][3] = matrix[3][1];
    matrix[3][1] = temp;

    temp = matrix[2][3];
    matrix[2][3] = matrix[3][2];
    matrix[3][2] = temp;
}

int solve(int matrix[N][N], int clues[4][N], int row, int col) {
    if (row == N) {
        if (checkClues(matrix, clues)) {
            return 1;
        } else {
            return 0;
        }
    }

    int num = 1;
    while (num <= N) {
        if (isValid(matrix, row, col, num)) {
            matrix[row][col] = num;
            int nextRow = col == N - 1 ? row + 1 : row;
            int nextCol = col == N - 1 ? 0 : col + 1;
            if (solve(matrix, clues, nextRow, nextCol)) {
                return 1;
            }
            matrix[row][col] = 0;
        }
        num++;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    int matrix[N][N] = {0};
    int clues[4][N];

    if (argc != 2) {
        write(STDOUT_FILENO, "Por favor, introduce 16 pistas.\n", 31);
        return 1;
    }

    char *clue_str = argv[1];
    int clue_count = 0;
    char *clue_start = clue_str;
    int i = 0;

    while (clue_str[i] != '\0') {
        if (clue_str[i] == ' ') {
            clue_str[i] = '\0';
            clues[clue_count / N][clue_count % N] = atoi(clue_start);
            clue_start = &clue_str[i+1];
            clue_count++;
        }
        i++;
    }
    clues[clue_count / N][clue_count % N] = atoi(clue_start);

    if (solve(matrix, clues, 0, 0)) {
        swapMatrixValues(matrix);  // Agrega esta línea para intercambiar los valores
        printMatrix(matrix);
    } else {
        write(STDOUT_FILENO, "Error.\n", 6);
    }

    return 0;
}


