#include "test_main.h"

START_TEST(sum_matrix_1) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value, rows = 2, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  return_value = s21_sum_matrix(&matrix1, &matrix2, &matrix_result);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&matrix_result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(sum_matrix_2) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  matrix_t matrix_test;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  s21_create_matrix(rows, cols, &matrix_test);
  // matrix1
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 3;
  matrix1.matrix[1][0] = 0;
  matrix1.matrix[1][1] = 4;
  matrix1.matrix[1][2] = 5;
  matrix1.matrix[2][0] = 0;
  matrix1.matrix[2][1] = 0;
  matrix1.matrix[2][2] = 6;
  // matrix2
  matrix2.matrix[0][0] = 1;
  matrix2.matrix[0][1] = 0;
  matrix2.matrix[0][2] = 0;
  matrix2.matrix[1][0] = 2;
  matrix2.matrix[1][1] = 0;
  matrix2.matrix[1][2] = 0;
  matrix2.matrix[2][0] = 3;
  matrix2.matrix[2][1] = 4;
  matrix2.matrix[2][2] = 1;
  // matrix_test
  matrix_test.matrix[0][0] = 2;
  matrix_test.matrix[0][1] = 2;
  matrix_test.matrix[0][2] = 3;
  matrix_test.matrix[1][0] = 2;
  matrix_test.matrix[1][1] = 4;
  matrix_test.matrix[1][2] = 5;
  matrix_test.matrix[2][0] = 3;
  matrix_test.matrix[2][1] = 4;
  matrix_test.matrix[2][2] = 7;

  return_value = s21_sum_matrix(&matrix1, &matrix2, &matrix_result);
  ck_assert_int_eq(return_value, 0);
  return_value = s21_eq_matrix(&matrix_test, &matrix_result);
  ck_assert_int_eq(return_value, 1);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&matrix_test);
  s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(sum_matrix_3) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value = 0;
  s21_create_matrix(1, 1, &matrix1);
  s21_create_matrix(1, 1, &matrix2);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  return_value = s21_sum_matrix(&matrix1, &matrix2, &matrix_result);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(sum_matrix_4) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value = 0;
  s21_create_matrix(1, 1, &matrix1);
  s21_create_matrix(1, 1, &matrix2);
  s21_remove_matrix(&matrix2);
  return_value = s21_sum_matrix(&matrix1, &matrix2, &matrix_result);
  ck_assert_int_eq(return_value, 1);
  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(sum_matrix_5) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value = 0;
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(3, 3, &matrix2);
  return_value = s21_sum_matrix(&matrix1, &matrix2, &matrix_result);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(sum_matrix_6) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value = 0;
  s21_create_matrix(3, 3, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  return_value = s21_sum_matrix(&matrix1, &matrix2, &matrix_result);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

Suite *test_sum_matrix(void) {
  Suite *s = suite_create("s21_matrix sum_matrix");
  TCase *tc = tcase_create("sum_matrix_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, sum_matrix_1);
  tcase_add_test(tc, sum_matrix_2);
  tcase_add_test(tc, sum_matrix_3);
  tcase_add_test(tc, sum_matrix_4);
  tcase_add_test(tc, sum_matrix_5);
  tcase_add_test(tc, sum_matrix_6);
  // tcase_add_test(tc, sum_matrix_7);
  // tcase_add_test(tc, sum_matrix_8);
  // tcase_add_test(tc, sum_matrix_9);
  // tcase_add_test(tc, sum_matrix_10);
  // tcase_add_test(tc, sum_matrix_11);
  return s;
}
