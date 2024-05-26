#include "test_main.h"

START_TEST(matrix_1) {
  matrix_t matrix1;
  int return_value, rows = 2, cols = 2;
  return_value = s21_create_matrix(rows, cols, &matrix1);
  ck_assert_int_eq(return_value, 0);
  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(matrix_2) {
  matrix_t matrix1;
  int return_value, rows = 0, cols = 0;
  return_value = s21_create_matrix(rows, cols, &matrix1);
  ck_assert_int_eq(return_value, 1);
  // s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(matrix_3) {
  matrix_t matrix1;
  int return_value, rows = 1, cols = 0;
  return_value = s21_create_matrix(rows, cols, &matrix1);
  ck_assert_int_eq(return_value, 1);
  // s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(matrix_4) {
  matrix_t matrix1;
  int return_value, rows = 0, cols = 1;
  return_value = s21_create_matrix(rows, cols, &matrix1);
  ck_assert_int_eq(return_value, 1);
  // s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(matrix_5) {
  matrix_t matrix1;
  int return_value, rows = -1, cols = -1;
  return_value = s21_create_matrix(rows, cols, &matrix1);
  ck_assert_int_eq(return_value, 1);
  // s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(matrix_6) {
  matrix_t matrix1;
  int return_value, rows = -1, cols = 0;
  return_value = s21_create_matrix(rows, cols, &matrix1);
  ck_assert_int_eq(return_value, 1);
  // s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(matrix_7) {
  matrix_t matrix1;
  int return_value, rows = 2, cols = 2;
  return_value = s21_create_matrix(rows, cols, &matrix1);
  ck_assert_int_eq(return_value, 0);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(matrix_8) {
  matrix_t matrix1;
  int return_value, rows = 2, cols = 2;
  return_value = s21_create_matrix(rows, cols, &matrix1);
  ck_assert_int_eq(return_value, 0);
  // matrix1.rows = 0;
  s21_remove_matrix(&matrix1);
  matrix1.columns = 0;
  free(matrix1.matrix);
}
END_TEST

START_TEST(matrix_9) {
  matrix_t matrix1;
  int return_value, rows = 2, cols = 2;
  return_value = s21_create_matrix(rows, cols, &matrix1);
  ck_assert_int_eq(return_value, 0);
  matrix1.columns = 0;
  s21_remove_matrix(&matrix1);
  matrix1.rows = 0;
  free(matrix1.matrix);
}
END_TEST

Suite *test_matrix(void) {
  Suite *s = suite_create("s21_matrix matrix");
  TCase *tc = tcase_create("matrix_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, matrix_1);
  tcase_add_test(tc, matrix_2);
  tcase_add_test(tc, matrix_3);
  tcase_add_test(tc, matrix_4);
  tcase_add_test(tc, matrix_5);
  tcase_add_test(tc, matrix_6);
  tcase_add_test(tc, matrix_7);
  tcase_add_test(tc, matrix_8);
  tcase_add_test(tc, matrix_9);
  // tcase_add_test(tc, matrix_10);
  // tcase_add_test(tc, matrix_11);
  return s;
}
