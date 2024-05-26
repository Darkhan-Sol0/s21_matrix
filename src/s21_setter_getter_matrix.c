#include "s21_matrix.h"

int s21_get_rows(matrix_t *matrix) {
  int rows = 0;
  rows = matrix->rows;
  return rows;
}

void s21_set_rows(int rows, matrix_t *matrix) { matrix->rows = rows; }

int s21_get_columns(matrix_t *matrix) {
  int columns = 0;
  columns = matrix->columns;
  return columns;
}

void s21_set_columns(int columns, matrix_t *matrix) {
  matrix->columns = columns;
}

// double s21_get_value(int row, int column, matrix_t *matrix) {
//   double value = 0;
//   value = matrix->matrix[row][column];
//   return value;
// }

void s21_set_value(double value, int row, int column, matrix_t *matrix) {
  matrix->matrix[row][column] = value;
}

// int s21_get_max_rows(matrix_t *matrix1, matrix_t *matrix2) {
//   int rows = 0, rows1 = 0, rows2 = 0;
//   rows1 = s21_get_rows(matrix1);
//   rows2 = s21_get_rows(matrix2);
//   if (rows1 >= rows2)
//     rows = rows1;
//   else
//     rows = rows2;
//   return rows;
// }

// int s21_get_max_columns(matrix_t *matrix1, matrix_t *matrix2) {
//   int columns = 0, columns1 = 0, columns2 = 0;
//   columns1 = s21_get_columns(matrix1);
//   columns2 = s21_get_columns(matrix2);
//   if (columns1 >= columns2)
//     columns = columns1;
//   else
//     columns = columns2;
//   return columns;
// }

// int s21_get_min_columns(matrix_t *matrix1, matrix_t *matrix2) {
//   int columns = 0, columns1 = 0, columns2 = 0;
//   columns1 = s21_get_columns(matrix1);
//   columns2 = s21_get_columns(matrix2);
//   if (columns1 <= columns2)
//     columns = columns1;
//   else
//     columns = columns2;
//   return columns;
// }