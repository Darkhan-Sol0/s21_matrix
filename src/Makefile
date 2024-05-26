C = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
OBJECT = s21_matrix.a
LIBSFLAGS = -lcheck -lm -lsubunit -lrt -lpthread -D_GNU_SOURCE
# LIBSFLAGS = -lcheck -lm -lrt -lpthread -D_GNU_SOURCE
SANITIZER = -fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable
TEST_FILES_OUR = testfiles/*.c
# TEST_FILES = test.c
SOURCE = $(wildcard s21_*.c)
VALGRIND_LOG =  valgrind --tool=memcheck --leak-check=yes -q --log-file="log_valgrind.txt"
VALGRIND =  valgrind --tool=memcheck --leak-check=yes
CLANG = clang-format -style=Google

all: clean $(OBJECT)

$(OBJECT): clean
	$(CC) $(CFLAGS) -c $(SOURCE)
	ar r $(OBJECT) *.o
	ranlib $(OBJECT)
	rm -rf *.o

sanitizer: clean_test
	$(CC) $(CFLAGS) $(SANITIZER) -o test $(TEST_FILES) $(OBJECT) $(LIBSFLAGS)
	./test

main:
	$(CC) $(CFLAGS) -o main main.c $(OBJECT) $(LIBSFLAGS)

clean: clean_report clean_test
	rm -rf $(OBJECT) *.o main

format:
	$(CLANG) -n *.c *.h 

setformat:
	$(CLANG) -i *.c *.h

test: clean_test $(OBJECT)
	$(CC) $(CFLAGS) -o test $(TEST_FILES_OUR) $(OBJECT) $(LIBSFLAGS)
	./test

test_valgrind: clean_test $(OBJECT)
	$(CC) $(CFLAGS) -o test $(TEST_FILES_OUR) $(OBJECT) $(LIBSFLAGS)
	$(VALGRIND) ./test

test_valgrind_log: clean_test $(OBJECT)
	$(CC) $(CFLAGS) -o test $(TEST_FILES_OUR) $(OBJECT) $(LIBSFLAGS)
	$(VALGRIND_LOG) ./test

clean_test:
	rm -rf test

clean_report:
	rm -rf *.gcno *.gcda *.html *.css GCOVRreport

report: gcov_report

openreport:
	firefox GCOVRreport/gcov_report.html

gcov_report: clean_test clean_report
	gcc --coverage $(SOURCE) ${TEST_FILES_OUR} -o test $(OBJECT) $(LIBSFLAGS)
	./test
	gcov *.c
	~/.local/bin/gcovr -r . --html-details -o gcov_report.html
	mkdir GCOVRreport
	mv *.html *.css GCOVRreport
	rm -rf *.gcno *.gcda

# test2: clean_test $(OBJECT)
# 	$(CC) $(CFLAGS) -o test $(TEST_FILES) $(OBJECT) $(LIBSFLAGS)
# 	$(VALGRIND_LOG) ./test

# report2: gcov_report2

# gcov_report2: clean_test clean_report
# 	gcc --coverage $(SOURCE) ${TEST_FILES} -o test $(OBJECT) $(LIBSFLAGS)
# 	./test
# 	gcov *.c
# 	~/.local/bin/gcovr -r . --html-details -o gcov_report.html
# 	mkdir GCOVRreport
# 	mv *.html *.css GCOVRreport
# 	rm -rf *.gcno *.gcda