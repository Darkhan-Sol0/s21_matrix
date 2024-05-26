#include "test_main.h"

START_TEST(determinant_1) {
  matrix_t matrix1;
  double determinant = 0;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 3;
  matrix1.matrix[1][0] = 4;
  matrix1.matrix[1][1] = 5;
  matrix1.matrix[1][2] = 6;
  matrix1.matrix[2][0] = 7;
  matrix1.matrix[2][1] = 8;
  matrix1.matrix[2][2] = 9;
  return_value = s21_determinant(&matrix1, &determinant);
  ck_assert_int_eq(return_value, 0);
  ck_assert_double_eq(determinant, 0);
  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(determinant_2) {
  matrix_t matrix1;
  double determinant = 0;
  int return_value, rows = 3, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  // matrix1.matrix[0][0] = 1;
  // matrix1.matrix[0][1] = 2;
  // matrix1.matrix[0][2] = 3;
  // matrix1.matrix[1][0] = 4;
  // matrix1.matrix[1][1] = 5;
  // matrix1.matrix[1][2] = 6;
  // matrix1.matrix[2][0] = 7;
  // matrix1.matrix[2][1] = 8;
  // matrix1.matrix[2][2] = 9;
  return_value = s21_determinant(&matrix1, &determinant);
  ck_assert_int_eq(return_value, 2);
  // ck_assert_double_eq(determinant, 0);
  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(determinant_3) {
  matrix_t matrix1;
  double determinant = 0;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  matrix1.matrix[0][0] = 0;
  matrix1.matrix[0][1] = 0;
  matrix1.matrix[0][2] = 0;
  matrix1.matrix[1][0] = 0;
  matrix1.matrix[1][1] = 0;
  matrix1.matrix[1][2] = 0;
  matrix1.matrix[2][0] = 0;
  matrix1.matrix[2][1] = 0;
  matrix1.matrix[2][2] = 0;
  return_value = s21_determinant(&matrix1, &determinant);
  s21_remove_matrix(&matrix1);
  ck_assert_int_eq(return_value, 0);
  ck_assert_double_eq(determinant, 0);
}
END_TEST

START_TEST(determinant_4) {
  matrix_t matrix1;
  double determinant = 0;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  matrix1.matrix[0][0] = 0;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 4;
  matrix1.matrix[1][0] = 1;
  matrix1.matrix[1][1] = 3;
  matrix1.matrix[1][2] = 3;
  matrix1.matrix[2][0] = 2;
  matrix1.matrix[2][1] = 3;
  matrix1.matrix[2][2] = 1;
  return_value = s21_determinant(&matrix1, &determinant);
  s21_remove_matrix(&matrix1);
  ck_assert_int_eq(return_value, 0);
  ck_assert_double_eq(determinant, -2);
}
END_TEST

START_TEST(determinant_5) {
  matrix_t matrix1;
  double determinant = 0;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  s21_remove_matrix(&matrix1);
  // matrix1.matrix[0][0] = 0;
  // matrix1.matrix[0][1] = 0;
  // matrix1.matrix[0][2] = 0;
  // matrix1.matrix[1][0] = 0;
  // matrix1.matrix[1][1] = 0;
  // matrix1.matrix[1][2] = 0;
  // matrix1.matrix[2][0] = 0;
  // matrix1.matrix[2][1] = 0;
  // matrix1.matrix[2][2] = 0;
  return_value = s21_determinant(&matrix1, &determinant);
  ck_assert_int_eq(return_value, 1);
  // ck_assert_double_eq(determinant, 0);
}
END_TEST

Suite *test_determinant(void) {
  Suite *s = suite_create("s21_matrix determinant");
  TCase *tc = tcase_create("determinant_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, determinant_1);
  tcase_add_test(tc, determinant_2);
  tcase_add_test(tc, determinant_3);
  tcase_add_test(tc, determinant_4);
  tcase_add_test(tc, determinant_5);
  // tcase_add_test(tc, determinant_6);
  // tcase_add_test(tc, determinant_7);
  // tcase_add_test(tc, determinant_8);
  // tcase_add_test(tc, determinant_9);
  // tcase_add_test(tc, determinant_10);
  // tcase_add_test(tc, determinant_11);
  return s;
}
