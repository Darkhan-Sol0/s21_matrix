#include "test_main.h"

START_TEST(eq_matrix_1) {
  matrix_t matrix1;
  matrix_t matrix2;
  int return_value, rows = 2, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  return_value = s21_eq_matrix(&matrix1, &matrix2);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(eq_matrix_2) {
  matrix_t matrix1;
  matrix_t matrix2;
  int return_value, rows = 2, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  // matrix1
  // matrix1.matrix[0][0] = 1;
  // matrix1.matrix[0][1] = 4;
  // matrix1.matrix[1][0] = 2;
  // matrix1.matrix[1][1] = 5;
  s21_set_value(1, 0, 0, &matrix1);
  s21_set_value(4, 0, 1, &matrix1);
  s21_set_value(2, 1, 0, &matrix1);
  s21_set_value(5, 1, 1, &matrix1);
  // matrix2
  // matrix2.matrix[0][0] = 1;
  // matrix2.matrix[0][1] = -1;
  // matrix2.matrix[0][2] = 1;
  // matrix2.matrix[1][0] = 2;
  s21_set_value(1, 0, 0, &matrix2);
  s21_set_value(-1, 0, 1, &matrix2);
  s21_set_value(1, 1, 0, &matrix2);
  s21_set_value(2, 1, 1, &matrix2);

  return_value = s21_eq_matrix(&matrix1, &matrix2);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(eq_matrix_3) {
  matrix_t matrix1;
  matrix_t matrix2;
  int return_value, rows = 2, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  s21_remove_matrix(&matrix1);
  return_value = s21_eq_matrix(&matrix1, &matrix2);
  s21_remove_matrix(&matrix2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(eq_matrix_4) {
  matrix_t matrix1;
  matrix_t matrix2;
  int return_value, rows = 2, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  s21_remove_matrix(&matrix2);
  return_value = s21_eq_matrix(&matrix1, &matrix2);
  s21_remove_matrix(&matrix1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(eq_matrix_5) {
  matrix_t matrix1;
  matrix_t matrix2;
  int return_value;
  s21_create_matrix(2, 3, &matrix1);
  s21_create_matrix(3, 2, &matrix2);
  return_value = s21_eq_matrix(&matrix1, &matrix2);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(eq_matrix_6) {
  matrix_t matrix1;
  matrix_t matrix2;
  int return_value;
  s21_create_matrix(2, 3, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  return_value = s21_eq_matrix(&matrix1, &matrix2);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

Suite *test_eq_matrix(void) {
  Suite *s = suite_create("s21_matrix eq_matrix");
  TCase *tc = tcase_create("eq_matrix_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, eq_matrix_1);
  tcase_add_test(tc, eq_matrix_2);
  tcase_add_test(tc, eq_matrix_3);
  tcase_add_test(tc, eq_matrix_4);
  tcase_add_test(tc, eq_matrix_5);
  tcase_add_test(tc, eq_matrix_6);
  // tcase_add_test(tc, eq_matrix_7);
  // tcase_add_test(tc, eq_matrix_8);
  // tcase_add_test(tc, eq_matrix_9);
  // tcase_add_test(tc, eq_matrix_10);
  // tcase_add_test(tc, eq_matrix_11);
  return s;
}
