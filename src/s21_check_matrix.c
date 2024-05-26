#include "s21_matrix.h"

int s21_check_correct_create_matrix(int rows, int columns) {
  s21_matrix_return error = S21_MATRIX_OK;
  if (rows <= 0 || columns <= 0) {
    error = S21_MATRIX_UNCORRECT;
  }
  return error;
}

int s21_check_correct_matrix_result(matrix_t *matrix) {
  s21_matrix_return error = S21_MATRIX_OK;
  if (matrix == NULL) {
    error = S21_MATRIX_UNCORRECT;
  }
  return error;
}

int s21_check_correct_matrix(matrix_t *matrix) {
  s21_matrix_return error = S21_MATRIX_OK;
  if (matrix == NULL || matrix->matrix == NULL || matrix->rows <= 0 ||
      matrix->columns <= 0) {
    error = S21_MATRIX_UNCORRECT;
  }
  return error;
}

int s21_eq_size_matrix(matrix_t *matrix_1, matrix_t *matrix_2) {
  s21_eq_matrix_return error = S21_MATRIX_SUCCESS;
  int rows_1 = 0, columns_1 = 0, rows_2 = 0, columns_2 = 0;
  rows_1 = s21_get_rows(matrix_1);
  columns_1 = s21_get_columns(matrix_1);
  rows_2 = s21_get_rows(matrix_2);
  columns_2 = s21_get_columns(matrix_2);
  if (rows_1 != rows_2 || columns_1 != columns_2) {
    error = S21_MATRIX_FAILURE;
  }
  return error;
}

int s21_eq_rol_col_matrix(matrix_t *matrix_1, matrix_t *matrix_2) {
  s21_eq_matrix_return error = S21_MATRIX_SUCCESS;
  int columns_1 = 0, rows_2 = 0;
  rows_2 = s21_get_rows(matrix_2);
  columns_1 = s21_get_columns(matrix_1);
  if (rows_2 != columns_1) {
    error = S21_MATRIX_FAILURE;
  }
  return error;
}

int s21_is_matrix_square(matrix_t *matrix) {
  s21_eq_matrix_return error = S21_MATRIX_SUCCESS;
  if (matrix->rows != matrix->columns) {
    error = S21_MATRIX_FAILURE;
  }
  return error;
}