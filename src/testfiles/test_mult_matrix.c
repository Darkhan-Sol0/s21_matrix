#include "test_main.h"

START_TEST(mult_matrix_1) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value, rows = 2, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  return_value = s21_mult_matrix(&matrix1, &matrix2, &matrix_result);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&matrix_result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(mult_matrix_2) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  matrix_t matrix_test;
  int return_value;
  s21_create_matrix(3, 2, &matrix1);
  s21_create_matrix(2, 3, &matrix2);
  s21_create_matrix(3, 3, &matrix_test);
  // matrix1
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 4;
  matrix1.matrix[1][0] = 2;
  matrix1.matrix[1][1] = 5;
  matrix1.matrix[2][0] = 3;
  matrix1.matrix[2][1] = 6;
  // matrix2
  matrix2.matrix[0][0] = 1;
  matrix2.matrix[0][1] = -1;
  matrix2.matrix[0][2] = 1;
  matrix2.matrix[1][0] = 2;
  matrix2.matrix[1][1] = 3;
  matrix2.matrix[1][2] = 4;
  // matrix_test
  matrix_test.matrix[0][0] = 9;
  matrix_test.matrix[0][1] = 11;
  matrix_test.matrix[0][2] = 17;
  matrix_test.matrix[1][0] = 12;
  matrix_test.matrix[1][1] = 13;
  matrix_test.matrix[1][2] = 22;
  matrix_test.matrix[2][0] = 15;
  matrix_test.matrix[2][1] = 15;
  matrix_test.matrix[2][2] = 27;

  return_value = s21_mult_matrix(&matrix1, &matrix2, &matrix_result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      ck_assert_double_eq(matrix_result.matrix[i][j], matrix_test.matrix[i][j]);
  }
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&matrix_test);
  s21_remove_matrix(&matrix_result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(mult_matrix_3) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value, rows = 2, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  s21_remove_matrix(&matrix1);
  return_value = s21_mult_matrix(&matrix1, &matrix2, &matrix_result);
  s21_remove_matrix(&matrix2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(mult_matrix_4) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value, rows = 2, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  s21_remove_matrix(&matrix2);
  return_value = s21_mult_matrix(&matrix1, &matrix2, &matrix_result);
  s21_remove_matrix(&matrix1);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

Suite *test_mult_matrix(void) {
  Suite *s = suite_create("s21_matrix mult_matrix");
  TCase *tc = tcase_create("mult_matrix_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, mult_matrix_1);
  tcase_add_test(tc, mult_matrix_2);
  tcase_add_test(tc, mult_matrix_3);
  tcase_add_test(tc, mult_matrix_4);
  // tcase_add_test(tc, mult_matrix_5);
  // tcase_add_test(tc, mult_matrix_6);
  // tcase_add_test(tc, mult_matrix_7);
  // tcase_add_test(tc, mult_matrix_8);
  // tcase_add_test(tc, mult_matrix_9);
  // tcase_add_test(tc, mult_matrix_10);
  // tcase_add_test(tc, mult_matrix_11);
  return s;
}
