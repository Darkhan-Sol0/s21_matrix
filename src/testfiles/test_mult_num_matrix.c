#include "test_main.h"

START_TEST(mult_num_1) {
  matrix_t matrix1;
  matrix_t matrix_result;
  double number = 1;
  int return_value, rows = 2, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  // s21_create_matrix(rows, cols, &matrix_result);
  return_value = s21_mult_number(&matrix1, number, &matrix_result);
  ck_assert_int_eq(return_value, 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      ck_assert_double_eq(matrix_result.matrix[i][j], matrix1.matrix[i][j]);
  }
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(mult_num_2) {
  matrix_t matrix1;
  matrix_t matrix_result;
  matrix_t matrix_test;
  double number = 2;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  // s21_create_matrix(rows, cols, &matrix_result);
  s21_create_matrix(rows, cols, &matrix_test);
  // matrix1
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 3;
  matrix1.matrix[1][0] = 4;
  matrix1.matrix[1][1] = 5;
  matrix1.matrix[1][2] = 6;
  matrix1.matrix[2][0] = 7;
  matrix1.matrix[2][1] = 8;
  matrix1.matrix[2][2] = 9;
  // matrix_test
  matrix_test.matrix[0][0] = 2;
  matrix_test.matrix[0][1] = 4;
  matrix_test.matrix[0][2] = 6;
  matrix_test.matrix[1][0] = 8;
  matrix_test.matrix[1][1] = 10;
  matrix_test.matrix[1][2] = 12;
  matrix_test.matrix[2][0] = 14;
  matrix_test.matrix[2][1] = 16;
  matrix_test.matrix[2][2] = 18;

  return_value = s21_mult_number(&matrix1, number, &matrix_result);
  ck_assert_int_eq(return_value, 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      ck_assert_double_eq(matrix_result.matrix[i][j], matrix_test.matrix[i][j]);
  }
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix_result);
  s21_remove_matrix(&matrix_test);
}
END_TEST

START_TEST(mult_num_3) {
  matrix_t matrix1;
  matrix_t matrix_result;
  matrix_t matrix_test;
  double number = 0;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  // s21_create_matrix(rows, cols, &matrix_result);
  s21_create_matrix(rows, cols, &matrix_test);
  // matrix1
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 3;
  matrix1.matrix[1][0] = 4;
  matrix1.matrix[1][1] = 5;
  matrix1.matrix[1][2] = 6;
  matrix1.matrix[2][0] = 7;
  matrix1.matrix[2][1] = 8;
  matrix1.matrix[2][2] = 9;
  // matrix_test
  matrix_test.matrix[0][0] = 0;
  matrix_test.matrix[0][1] = 0;
  matrix_test.matrix[0][2] = 0;
  matrix_test.matrix[1][0] = 0;
  matrix_test.matrix[1][1] = 0;
  matrix_test.matrix[1][2] = 0;
  matrix_test.matrix[2][0] = 0;
  matrix_test.matrix[2][1] = 0;
  matrix_test.matrix[2][2] = 0;

  return_value = s21_mult_number(&matrix1, number, &matrix_result);
  ck_assert_int_eq(return_value, 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      ck_assert_double_eq(matrix_result.matrix[i][j], matrix_test.matrix[i][j]);
  }
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix_result);
  s21_remove_matrix(&matrix_test);
}
END_TEST

START_TEST(mult_num_4) {
  matrix_t matrix1;
  matrix_t matrix_result;
  double number = 1;
  int return_value, rows = 2, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  // s21_create_matrix(rows, cols, &matrix_result);
  s21_remove_matrix(&matrix1);
  return_value = s21_mult_number(&matrix1, number, &matrix_result);
  ck_assert_int_eq(return_value, 1);
  // s21_remove_matrix(&matrix_result);
}
END_TEST

Suite *test_mult_num(void) {
  Suite *s = suite_create("s21_matrix mult_num");
  TCase *tc = tcase_create("mult_num_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, mult_num_1);
  tcase_add_test(tc, mult_num_2);
  tcase_add_test(tc, mult_num_3);
  tcase_add_test(tc, mult_num_4);
  // tcase_add_test(tc, mult_num_5);
  // tcase_add_test(tc, mult_num_6);
  // tcase_add_test(tc, mult_num_7);
  // tcase_add_test(tc, mult_num_8);
  // tcase_add_test(tc, mult_num_9);
  // tcase_add_test(tc, mult_num_10);
  // tcase_add_test(tc, mult_num_11);
  return s;
}
