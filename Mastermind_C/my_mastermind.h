#ifndef MY_MASTERMIND_H
#define MY_MASTERMIND_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define CODE_LEN 4

int my_strcmp(char* str1, char* str2);
char* random_code_generator(int code_length, char *code);
int random_number_generator(int min, int max);
bool is_valid_input(char *str);
bool integer_check(char *attempts);
int my_strlen(char* str);
int check_code(char* code, char* random_code);
bool input_validate(char* code);
char* secret_code_transform(char** argv, char* random_code, int i);
#endif