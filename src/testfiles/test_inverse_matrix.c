#include "test_main.h"

START_TEST(inverse_matrix_1) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  // matrix 1
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 5;
  matrix1.matrix[0][2] = 7;
  matrix1.matrix[1][0] = 6;
  matrix1.matrix[1][1] = 3;
  matrix1.matrix[1][2] = 4;
  matrix1.matrix[2][0] = 5;
  matrix1.matrix[2][1] = -2;
  matrix1.matrix[2][2] = -3;
  // matrix 2
  matrix2.matrix[0][0] = 1;
  matrix2.matrix[0][1] = -1;
  matrix2.matrix[0][2] = 1;
  matrix2.matrix[1][0] = -38;
  matrix2.matrix[1][1] = 41;
  matrix2.matrix[1][2] = -34;
  matrix2.matrix[2][0] = 27;
  matrix2.matrix[2][1] = -29;
  matrix2.matrix[2][2] = 24;
  return_value = s21_inverse_matrix(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, 0);
  return_value = s21_eq_matrix(&matrix2, &matrix_result);
  ck_assert_int_eq(return_value, 1);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(inverse_matrix_2) {
  matrix_t matrix1;
  matrix_t matrix_result;
  int return_value, rows = 3, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  return_value = s21_inverse_matrix(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, 2);

  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(inverse_matrix_3) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  s21_remove_matrix(&matrix1);
  return_value = s21_inverse_matrix(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, 1);
  s21_remove_matrix(&matrix2);
  // s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(inverse_matrix_4) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value, rows = 2, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  return_value = s21_inverse_matrix(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, 2);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  // s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(inverse_matrix_5) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value, rows = 3, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  return_value = s21_inverse_matrix(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, 2);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  // s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(inverse_matrix_6) {
  matrix_t matrix1;
  matrix_t matrix_result;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  // matrix 1
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 3;
  matrix1.matrix[1][0] = 4;
  matrix1.matrix[1][1] = 5;
  matrix1.matrix[1][2] = 6;
  matrix1.matrix[2][0] = 7;
  matrix1.matrix[2][1] = 8;
  matrix1.matrix[2][2] = 9;
  return_value = s21_inverse_matrix(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, 2);
  s21_remove_matrix(&matrix1);
  // s21_remove_matrix(&matrix_result);
}
END_TEST

Suite *test_inverse_matrix(void) {
  Suite *s = suite_create("s21_matrix inverse_matrix");
  TCase *tc = tcase_create("inverse_matrix_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, inverse_matrix_1);
  tcase_add_test(tc, inverse_matrix_2);
  tcase_add_test(tc, inverse_matrix_3);
  tcase_add_test(tc, inverse_matrix_4);
  tcase_add_test(tc, inverse_matrix_5);
  tcase_add_test(tc, inverse_matrix_6);
  // tcase_add_test(tc, inverse_matrix_7);
  // tcase_add_test(tc, inverse_matrix_8);
  // tcase_add_test(tc, inverse_matrix_9);
  // tcase_add_test(tc, inverse_matrix_10);
  // tcase_add_test(tc, inverse_matrix_11);
  return s;
}
