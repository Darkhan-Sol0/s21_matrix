#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

typedef enum s21_matrix_return {
  S21_MATRIX_OK = 0,
  S21_MATRIX_UNCORRECT = 1,
  S21_MATRIX_ERROR_ARIFMETICS = 2,
} s21_matrix_return;

typedef enum s21_eq_matrix_return {
  S21_MATRIX_FAILURE = 0,
  S21_MATRIX_SUCCESS = 1,
} s21_eq_matrix_return;

//---Операции над матрицами---
int s21_create_matrix(int rows, int columns,
                      matrix_t *result);      // Создание матриц
void s21_remove_matrix(matrix_t *A);          // Очистка матриц
int s21_eq_matrix(matrix_t *A, matrix_t *B);  // Сравнение матриц
int s21_sum_matrix(matrix_t *A, matrix_t *B,
                   matrix_t *result);  // Сложение матриц
int s21_sub_matrix(matrix_t *A, matrix_t *B,
                   matrix_t *result);  // Вычитание матриц
int s21_mult_number(matrix_t *A, double number,
                    matrix_t *result);  // Умножение матрицы на число
int s21_mult_matrix(matrix_t *A, matrix_t *B,
                    matrix_t *result);  // Умножение двух матриц
int s21_transpose(matrix_t *A, matrix_t *result);  // Транспонирование матрицы
int s21_calc_complements(
    matrix_t *A,
    matrix_t *result);  // Минор матрицы и матрица алгебраических дополнений
int s21_determinant(matrix_t *A, double *result);  // Определитель матрицы
int s21_inverse_matrix(matrix_t *A, matrix_t *result);  // Обратная матрица

//---Support Functions---
void s21_print_matrix(matrix_t *matrix);
int s21_get_rows(matrix_t *matrix);
void s21_set_rows(int rows, matrix_t *matrix);
int s21_get_columns(matrix_t *matrix);
void s21_set_columns(int columns, matrix_t *matrix);
double s21_get_value(int row, int column, matrix_t *matrix);
void s21_set_value(double value, int row, int column, matrix_t *matrix);
void s21_copy_matrix(matrix_t *matrix, matrix_t *result);
void s21_fully_matrix(matrix_t *result);
void s21_get_minor(int row, int column, matrix_t *matrix, matrix_t *result);
int s21_is_matrix_square(matrix_t *matrix);
matrix_t *s21_create_minor(int row, int column, matrix_t *matrix);

int s21_check_correct_create_matrix(int rows, int columns);
int s21_check_correct_matrix(matrix_t *matrix);
int s21_check_correct_matrix_result(matrix_t *matrix);
int s21_eq_size_matrix(matrix_t *matrix1, matrix_t *matrix2);
int s21_eq_rol_col_matrix(matrix_t *matrix1, matrix_t *matrix2);

int s21_get_max_columns(matrix_t *matrix1, matrix_t *matrix2);
int s21_get_min_columns(matrix_t *matrix1, matrix_t *matrix2);

#endif