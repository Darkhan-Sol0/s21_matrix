#include "s21_matrix.h"

void s21_print_matrix(matrix_t *matrix) {
  if (!s21_check_correct_create_matrix(matrix->rows, matrix->columns)) {
    for (int i = 0; i < matrix->rows; i++) {
      for (int j = 0; j < matrix->columns; j++) {
        printf("%.7lf ", matrix->matrix[i][j]);
      }
      printf("\n");
    }
  }
}

// void s21_copy_matrix(matrix_t *matrix, matrix_t *result) {
//   s21_create_matrix(result->rows, result->columns, result);
//   result->rows = matrix->rows;
//   result->columns = matrix->columns;
//   result->matrix = matrix->matrix;
// }

// void s21_fully_matrix(matrix_t *result) {
//   double value = 0;
//   for (int i = 0; i < result->rows; i++) {
//     for (int j = 0; j < result->columns; j++) {
//       value++;
//       // s21_set_value((double)rand() / RAND_MAX, i, j, result);
//       s21_set_value(value, i, j, result);
//     }
//   }
// }

matrix_t *s21_create_minor(int row, int column, matrix_t *matrix) {
  matrix_t *minor = calloc(1, sizeof(matrix_t));
  if (minor != NULL) {
    if (s21_create_matrix(matrix->rows - 1, matrix->columns - 1, minor) ==
        S21_MATRIX_OK) {
      for (int i = 0, minor_row = 0; i < matrix->rows; i++) {
        if (i != row) {
          for (int j = 0, minor_column = 0; j < matrix->columns; j++) {
            if (j != column) {
              minor->matrix[minor_row][minor_column] = matrix->matrix[i][j];
              minor_column++;
            }
          }
          minor_row++;
        }
      }
    }
  }
  return minor;
}
