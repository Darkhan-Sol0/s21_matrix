#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  s21_matrix_return error = S21_MATRIX_OK;
  if (s21_check_correct_matrix_result(result)) {
    error = S21_MATRIX_UNCORRECT;
  } else {
    if (s21_check_correct_create_matrix(rows, columns)) {
      error = S21_MATRIX_UNCORRECT;
    } else {
      s21_set_rows(rows, result);
      s21_set_columns(columns, result);
      result->matrix = (double **)calloc(rows, sizeof(double *));
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
      }
    }
  }
  return error;
}

void s21_remove_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) free(A->matrix[i]);
  free(A->matrix);
  A->matrix = NULL;
  A->rows = 0;
  A->columns = 0;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  s21_eq_matrix_return error = S21_MATRIX_SUCCESS;
  if (s21_check_correct_matrix(A) || s21_check_correct_matrix(B)) {
    error = S21_MATRIX_FAILURE;
  } else {
    if (s21_eq_size_matrix(A, B)) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-7) {
            error = S21_MATRIX_FAILURE;
          }
        }
      }
    } else
      error = S21_MATRIX_FAILURE;
  }
  return error;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  s21_matrix_return error = S21_MATRIX_OK;
  int rows = 0, columns = 0;
  if (s21_check_correct_matrix(A) || s21_check_correct_matrix(B) ||
      s21_check_correct_matrix_result(result)) {
    error = S21_MATRIX_UNCORRECT;
  } else {
    if (s21_eq_size_matrix(A, B)) {
      rows = s21_get_rows(A);
      columns = s21_get_columns(A);
      s21_create_matrix(rows, columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          s21_set_value(A->matrix[i][j] + B->matrix[i][j], i, j, result);
        }
      }
    } else
      error = S21_MATRIX_ERROR_ARIFMETICS;
  }
  return error;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  s21_matrix_return error = S21_MATRIX_OK;
  int rows = 0, columns = 0;

  if (s21_check_correct_matrix(A) || s21_check_correct_matrix(B) ||
      s21_check_correct_matrix_result(result)) {
    error = S21_MATRIX_UNCORRECT;
  } else {
    if (s21_eq_size_matrix(A, B)) {
      rows = s21_get_rows(A);
      columns = s21_get_columns(A);
      s21_create_matrix(rows, columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          s21_set_value(A->matrix[i][j] - B->matrix[i][j], i, j, result);
        }
      }
    } else
      error = S21_MATRIX_ERROR_ARIFMETICS;
  }
  return error;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  s21_matrix_return error = S21_MATRIX_OK;
  int rows = 0, columns = 0;

  if (s21_check_correct_matrix(A) || s21_check_correct_matrix_result(result)) {
    error = S21_MATRIX_UNCORRECT;
  } else {
    rows = s21_get_rows(A);
    columns = s21_get_columns(A);
    s21_create_matrix(rows, columns, result);

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        s21_set_value(A->matrix[i][j] * number, i, j, result);
      }
    }
  }
  return error;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  s21_matrix_return error = S21_MATRIX_OK;
  int rows = 0, columns = 0, temp_n = 0;
  double temp_value = 0;

  if (s21_check_correct_matrix(A) || s21_check_correct_matrix(B) ||
      s21_check_correct_matrix_result(result)) {
    error = S21_MATRIX_UNCORRECT;
  } else {
    if (s21_eq_rol_col_matrix(A, B)) {
      rows = s21_get_rows(A);
      columns = s21_get_columns(B);
      temp_n = s21_get_rows(B);
      s21_create_matrix(rows, columns, result);
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          temp_value = 0;
          for (int k = 0; k < temp_n; k++) {
            temp_value += A->matrix[i][k] * B->matrix[k][j];
          }
          s21_set_value(temp_value, i, j, result);
        }
      }
    } else
      error = S21_MATRIX_ERROR_ARIFMETICS;
  }
  return error;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  s21_matrix_return error = S21_MATRIX_OK;
  int rows = 0, columns = 0;
  if (s21_check_correct_matrix(A) || s21_check_correct_matrix_result(result)) {
    error = S21_MATRIX_UNCORRECT;
  } else {
    rows = s21_get_columns(A);
    columns = s21_get_rows(A);
    s21_create_matrix(rows, columns, result);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        s21_set_value(A->matrix[j][i], i, j, result);
      }
    }
  }
  return error;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  s21_matrix_return error = S21_MATRIX_OK;

  if (s21_check_correct_matrix(A) || result == NULL) {
    error = S21_MATRIX_UNCORRECT;
  } else if (!s21_is_matrix_square(A)) {
    error = S21_MATRIX_ERROR_ARIFMETICS;
  } else {
    error = s21_create_matrix(A->rows, A->columns, result);
    if (result->rows == 1) {
      result->matrix[0][0] = 1;
    } else {
      if (!error) {
        for (int i = 0; i < A->rows && error == S21_MATRIX_OK; i++) {
          int sign = i % 2 == 0 ? 1 : -1;
          for (int j = 0; j < A->columns && error == S21_MATRIX_OK; j++) {
            matrix_t *minor = s21_create_minor(i, j, A);
            if (minor == NULL) {
              error = S21_MATRIX_UNCORRECT;
            } else {
              double det = 0;
              error = s21_determinant(minor, &det);
              if (!isfinite(det)) {
                error = S21_MATRIX_ERROR_ARIFMETICS;
              }
              if (!error) {
                result->matrix[i][j] = sign * det;
                sign = -sign;
              }
              s21_remove_matrix(minor);
              free(minor);
              minor = NULL;
            }
          }
        }
      }
    }
  }

  return error;
}

int s21_determinant(matrix_t *A, double *result) {
  s21_matrix_return error = S21_MATRIX_OK;
  if (s21_check_correct_matrix(A) || result == NULL) {
    error = S21_MATRIX_UNCORRECT;
  } else if (!s21_is_matrix_square(A)) {
    error = S21_MATRIX_ERROR_ARIFMETICS;
  } else {
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else if (A->rows == 2) {
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
    } else if (A->rows > 2) {
      int sign = 1;
      *result = 0;
      for (int i = 0; i < A->columns && error == S21_MATRIX_OK; i++) {
        matrix_t *minor = s21_create_minor(0, i, A);
        if (minor == NULL) {
          error = S21_MATRIX_UNCORRECT;
        } else {
          double minor_det = 0;
          error = s21_determinant(minor, &minor_det);
          if (!error) {
            *result += sign * A->matrix[0][i] * minor_det;
            sign = -sign;
          }
          s21_remove_matrix(minor);
          free(minor);
          minor = NULL;
        }
      }
    }
  }
  return error;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  s21_matrix_return error = S21_MATRIX_OK;

  if (s21_check_correct_matrix(A) || s21_check_correct_matrix_result(result)) {
    error = S21_MATRIX_UNCORRECT;
  } else {
    double det = 0;
    error = s21_determinant(A, &det);
    if (!error && det != 0 && s21_is_matrix_square(A)) {
      if (A->rows == 1) {
        error = s21_create_matrix(A->rows, A->columns, result);
        if (!error) {
          result->matrix[0][0] = 1 / A->matrix[0][0];
        }
      } else {
        matrix_t temp_algebraic_complements;
        matrix_t transposed_temp_algebraic_complements;
        error = s21_calc_complements(A, &temp_algebraic_complements);
        if (!error) {
          error = s21_transpose(&temp_algebraic_complements,
                                &transposed_temp_algebraic_complements);
        }
        if (!error) {
          error = s21_mult_number(&transposed_temp_algebraic_complements,
                                  1 / det, result);
        }
        s21_remove_matrix(&temp_algebraic_complements);
        s21_remove_matrix(&transposed_temp_algebraic_complements);
      }
    } else {
      error = S21_MATRIX_ERROR_ARIFMETICS;
    }
  }
  return error;
}
