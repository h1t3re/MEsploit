compile_stdlib:
	cd ..; make install; cd test

compile_test_strlen: ../lib/stdlib.o ../include/stdlib.h test_strlen.c
	gcc -Wall -g ../lib/stdlib.o test_strlen.c -o test_strlen

compile_test_strcmp: ../lib/stdlib.o ../include/stdlib.h test_strcmp.c
	gcc -Wall -g ../lib/stdlib.o test_strcmp.c -o test_strcmp 

compile_test_strdup: ../lib/stdlib.o ../include/stdlib.h test_strdup.c
	gcc -Wall -g ../lib/stdlib.o test_strdup.c -o test_strdup

compile_test_strstrip: ../lib/stdlib.o ../include/stdlib.h test_strstrip.c
	gcc -Wall -g ../lib/stdlib.o test_strstrip.c -o test_strstrip

compile_test_strcontains: ../lib/stdlib.o ../include/stdlib.h test_strcontains.c
	gcc -Wall -g ../lib/stdlib.o test_strcontains.c -o test_strcontains

compile_test_find_string_position: ../lib/stdlib.o ../include/stdlib.h test_find_string_position.c
	gcc -Wall -g ../lib/stdlib.o test_find_string_position.c -o test_find_string_position

compile_test_strsplit: ../lib/stdlib.o ../include/stdlib.h test_strsplit.c
	gcc -Wall -g ../lib/stdlib.o test_strsplit.c -o test_strsplit

compile_test_read_io: ../lib/stdlib.o ../include/stdlib.h test_read_io.c
	gcc -Wall -g ../lib/stdlib.o test_read_io.c -o test_read_io

compile_test_read_file: ../lib/stdlib.o ../include/stdlib.h test_read_file.c
	gcc -Wall -g ../lib/stdlib.o test_read_file.c -o test_read_file

compile_test_strconcatenate: ../lib/stdlib.o ../include/stdlib.h test_strconcatenate.c
	gcc -Wall -g ../lib/stdlib.o test_strconcatenate.c -o test_strconcatenate

compile_test_get_data_by_key: ../lib/stdlib.o ../include/stdlib.h test_get_data_by_key.c
	gcc -Wall -g ../lib/stdlib.o test_get_data_by_key.c -o test_get_data_by_key

compile_test_get_data_by_key_until_end: ../lib/stdlib.o ../include/stdlib.h test_get_data_by_key_until_end.c
	gcc -Wall -g ../lib/stdlib.o test_get_data_by_key_until_end.c -o test_get_data_by_key_until_end

test_strlen: compile_stdlib compile_test_strlen
	./test_strlen

test_strcmp: compile_stdlib compile_test_strcmp
	./test_strcmp

test_strdup: compile_stdlib compile_test_strdup
	./test_strdup

test_strstrip: compile_stdlib compile_test_strstrip
	./test_strstrip

test_strcontains: compile_stdlib compile_test_strcontains 
	./test_strcontains

test_find_string_position: compile_stdlib compile_test_find_string_position
	./test_find_string_position

test_strsplit: compile_stdlib compile_test_strsplit
	./test_strsplit

test_read_io: compile_stdlib compile_test_read_io
	./test_read_io

test_read_file: compile_stdlib compile_test_read_file
	./test_read_file

test_strconcatenate: compile_stdlib compile_test_strconcatenate
	./test_strconcatenate

test_get_data_by_key: compile_stdlib compile_test_get_data_by_key
	./test_get_data_by_key

test_get_data_by_key_until_end: compile_stdlib compile_test_get_data_by_key_until_end
	./test_get_data_by_key_until_end

test: test_strlen test_strcmp test_strdup test_strstrip test_strcontains test_strconcatenate test_find_string_position test_strsplit test_read_io test_read_file test_get_data_by_key test_get_data_by_key_until_end
	echo "Tests done.\n"
