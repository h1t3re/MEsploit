void dd_0(void *ptr, int c, int length);
long unsigned int strlen(const char *str);
const int strcmp(const char *str0, const char *str1);
char *strdup(const char *str);
char *strstrip(const char *s, const char *x);
char *strstrip_v1(const char *s, const char *x);
const int *strcontains(const char *str0, const char *str1);
char *strconcatenate(const char *str0, const char *str1);
int find_string_position(char *buffer, char *string, int position);
char **get_data_by_key(char *buffer, char *key, int number_of_lines);
char **strsplit(char *str, char *spliter);
char **strsplit_v1(char *str, char *spliter);
char *get_data_by_key_until_end0(char *buffer, char *key, char *end);
char *read_io();
char *read_file(const char *restrict file_name);
char *read_file_v1(const char *restrict file_name);
const int shift_left(const int mask, const int i);
const int and_operation(const int number, const int mask_shifted);
const int shift_right(const int number, const int i);
int *convert_integer_to_binary(int *restrict array, const int number, const int mask, const int length);
int convert_hexa_to_int(char hexa);
int *convert_hexa_to_binary(int *restrict array, char hexa, int mask);
long convert_char_to_int(char *c);
char convert_int_to_char(long n);
int convert_binary_to_integer(int *array, int architecture);
void print(const char *str, const char *type);
int *concatenate_int_arrays(int *restrict array0, int length0, int *restrict array1, int length1);
void write_to_file(char *file_name, char *buffer);
