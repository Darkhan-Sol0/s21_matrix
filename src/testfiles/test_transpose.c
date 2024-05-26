#include "test_main.h"

START_TEST(transpose_1) {
  matrix_t matrix1;
  matrix_t matrix_test;
  matrix_t matrix_result;
  int return_value, rows = 3, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(2, 3, &matrix_test);
  return_value = s21_transpose(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, 0);
  return_value = s21_eq_matrix(&matrix_result, &matrix_test);
  ck_assert_int_eq(return_value, 1);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix_test);
  s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t matrix1;
  matrix_t matrix_result;
  int return_value, rows = 2, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  // matrix1.rows = 0;
  s21_set_rows(0, &matrix1);
  return_value = s21_transpose(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, 1);
  s21_set_rows(2, &matrix1);
  for (int i = 0; i < matrix1.rows; i++) free(matrix1.matrix[i]);
  free(matrix1.matrix);
  matrix1.matrix = NULL;
  // matrix1.columns = 0;
  s21_set_columns(0, &matrix1);
}
END_TEST

START_TEST(transpose_3) {
  matrix_t matrix1;
  matrix_t matrix_test;
  matrix_t matrix_result;
  int return_value, rows = 3, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(2, 3, &matrix_test);
  // matrix1
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 4;
  matrix1.matrix[1][0] = 2;
  matrix1.matrix[1][1] = 5;
  matrix1.matrix[2][0] = 3;
  matrix1.matrix[2][1] = 6;
  // matrix_test
  matrix_test.matrix[0][0] = 1;
  matrix_test.matrix[0][1] = 2;
  matrix_test.matrix[0][2] = 3;
  matrix_test.matrix[1][0] = 4;
  matrix_test.matrix[1][1] = 5;
  matrix_test.matrix[1][2] = 6;

  return_value = s21_transpose(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, 0);
  return_value = s21_eq_matrix(&matrix_result, &matrix_test);
  ck_assert_int_eq(return_value, 1);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix_test);
  s21_remove_matrix(&matrix_result);
}
END_TEST

Suite *test_transpose(void) {
  Suite *s = suite_create("s21_matrix transpose");
  TCase *tc = tcase_create("transpose_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, transpose_1);
  tcase_add_test(tc, transpose_2);
  tcase_add_test(tc, transpose_3);
  // tcase_add_test(tc, transpose_4);
  // tcase_add_test(tc, transpose_5);
  // tcase_add_test(tc, transpose_6);
  // tcase_add_test(tc, transpose_7);
  // tcase_add_test(tc, transpose_8);
  // tcase_add_test(tc, transpose_9);
  // tcase_add_test(tc, transpose_10);
  // tcase_add_test(tc, transpose_11);
  return s;
}
