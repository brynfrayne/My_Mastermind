#include "my_mastermind.h"

int my_strcmp(char* str1, char* str2){
        int i = 0;
        while(str1[i] != '\0'){
         if(str1[i] > str2[i]){
             return 1;
         } 
         if (str1[i]<str2[i]){
             return -1;
         } 
         i++;
      }
    return 0;
}

char* random_code_generator(int code_length, char *code){
    int i = 0;
    
    srand(time(NULL));
    while(i < code_length){
        
        code[i]=random_number_generator(0,7);
        printf("code[%d]: %d\n", i, code[i]);
        i++;
    }
    printf("\n");
    return code;
}

int random_number_generator(int min, int max){
   int num = (rand() % (max - min + 1)) + min;
   return num;
}


bool is_valid_input(char *str){
    
    int i = 0;
    while (str[i] != 0)
    {
        if (str[i] >= 48 && str[i] <= 55)
        {
            i += 1;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool integer_check(char *attempts){
    int i = 0;

    while(attempts[i]!='\0'){
        
        if(attempts[i]<48 || attempts[i]>55){
            return false;
        }
        i++;
    }
    return true;
}

int my_strlen(char* string)
 {
    int i = 0;
    while (string[i] != 10) {       
        i++;
    }
     return i;
 }

int check_code(char* code, char* random_code){
    int misplaced_pieces = 0;
    int wellplaced_pieces = 0;
    int i = 0;
    int j = 0;
    
    while(i < my_strlen(code)){
    
        atoi(&code[i]);
    
        if(code[i] - '0' == random_code[i]){
            wellplaced_pieces++;
        } else {
            
            j = 0;

            while(random_code[j] != '\0'){
                
                if(i != j && code[i] - '0' == random_code[j]){
                    misplaced_pieces++;
                    break;
                }
                j++;
            }
        }
        i++;
    }
    
    if(wellplaced_pieces == 4){
    
        printf("Congratz! You did it!\n");
        return EXIT_SUCCESS;
    
    } else {

        printf("Well placed pieces: %d\n", wellplaced_pieces);
        printf("Misplaced pieces: %d\n", misplaced_pieces);
        return EXIT_FAILURE;
    }
}

bool input_validate(char* code){
    
    if(my_strlen(code) != CODE_LEN){
        return false;
    }
    
    int i = 0;

    while(i < my_strlen(code)){
    
        if(code[i]<48 || code[i]>55){

            return false;
        } 
        i++;
    }
    return true;
}

char* secret_code_transform(char** argv, char* random_code, int i){
    int j = 0;
    while(argv[i+1][j] != '\0'){
        random_code[j] = argv[i+1][j]; 
        atoi(&random_code[j]);
        random_code[j] -= '0';
        j++;
    }
    return random_code;
}