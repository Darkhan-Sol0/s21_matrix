#include "test_main.h"

START_TEST(calc_complements_1) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  // matrix 1
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 3;
  matrix1.matrix[1][0] = 0;
  matrix1.matrix[1][1] = 4;
  matrix1.matrix[1][2] = 2;
  matrix1.matrix[2][0] = 5;
  matrix1.matrix[2][1] = 2;
  matrix1.matrix[2][2] = 1;
  // matrix_result
  matrix2.matrix[0][0] = 0;
  matrix2.matrix[0][1] = 10;
  matrix2.matrix[0][2] = -20;
  matrix2.matrix[1][0] = 4;
  matrix2.matrix[1][1] = -14;
  matrix2.matrix[1][2] = 8;
  matrix2.matrix[2][0] = -8;
  matrix2.matrix[2][1] = -2;
  matrix2.matrix[2][2] = 4;
  return_value = s21_calc_complements(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, 0);
  return_value = s21_eq_matrix(&matrix2, &matrix_result);
  ck_assert_int_eq(return_value, 1);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(calc_complements_2) {
  matrix_t matrix1;
  matrix_t matrix_result;
  int return_value, rows = 3, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  return_value = s21_calc_complements(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, 2);

  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(calc_complements_3) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  // matrix 1
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 3;
  matrix1.matrix[1][0] = 0;
  matrix1.matrix[1][1] = 4;
  matrix1.matrix[1][2] = 2;
  matrix1.matrix[2][0] = 5;
  matrix1.matrix[2][1] = 2;
  matrix1.matrix[2][2] = 1;
  // matrix_result
  matrix2.matrix[0][0] = 0;
  matrix2.matrix[0][1] = 10;
  matrix2.matrix[0][2] = -20;
  matrix2.matrix[1][0] = 4;
  matrix2.matrix[1][1] = -14;
  matrix2.matrix[1][2] = 8;
  matrix2.matrix[2][0] = -8;
  matrix2.matrix[2][1] = -2;
  matrix2.matrix[2][2] = 4;
  return_value = s21_calc_complements(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, 0);
  return_value = s21_eq_matrix(&matrix2, &matrix_result);
  ck_assert_int_eq(return_value, 1);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(calc_complements_4) {
  matrix_t matrix1;
  matrix_t matrix_result;
  int return_value, rows = 1, cols = 1;
  s21_create_matrix(rows, cols, &matrix1);
  return_value = s21_calc_complements(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, 0);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(calc_complements_5) {
  matrix_t matrix1;
  matrix_t matrix_result;
  int return_value, rows = 1, cols = 1;
  s21_create_matrix(rows, cols, &matrix1);
  s21_remove_matrix(&matrix1);
  return_value = s21_calc_complements(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, 1);
  // s21_remove_matrix(&matrix_result);
}
END_TEST

Suite *test_calc_complements(void) {
  Suite *s = suite_create("s21_matrix calc_complements");
  TCase *tc = tcase_create("calc_complements_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, calc_complements_1);
  tcase_add_test(tc, calc_complements_2);
  tcase_add_test(tc, calc_complements_3);
  tcase_add_test(tc, calc_complements_4);
  tcase_add_test(tc, calc_complements_5);
  // tcase_add_test(tc, calc_complements_6);
  // tcase_add_test(tc, calc_complements_7);
  // tcase_add_test(tc, calc_complements_8);
  // tcase_add_test(tc, calc_complements_9);
  // tcase_add_test(tc, calc_complements_10);
  // tcase_add_test(tc, calc_complements_11);
  return s;
}
