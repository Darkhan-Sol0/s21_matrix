#ifndef SRC_TESTS_MAIN_H
#define SRC_TESTS_MAIN_H

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "../s21_matrix.h"

Suite *test_sum_matrix(void);
Suite *test_sub_matrix(void);
Suite *test_matrix(void);
Suite *test_mult_num(void);
Suite *test_mult_matrix(void);
Suite *test_eq_matrix(void);
Suite *test_transpose(void);
Suite *test_determinant(void);
Suite *test_calc_complements(void);
Suite *test_inverse_matrix(void);

#endif  // SRC_TESTS_MAIN_H
