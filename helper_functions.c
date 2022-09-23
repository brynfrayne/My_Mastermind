#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int random_number(int min, int max)
{
    int result = 0;
    int low_nbr = 0;
    int hi_nbr = 0;
    low_nbr = min;
    hi_nbr = max + 1;
    srand(time(NULL));
    result = (rand() % (hi_nbr-low_nbr)) + low_nbr;
    return result;
}

int mastermind(int* secret_code, int attempts){

    for(int i = 1; i < attempts; i++){
        char code[128];
        int size = read(0, code, sizeof(code));
        // bool input_check_result;

        if(size == 5){

            // check to see if all inputs are digits from 1-7
            if(input_validate(code) == true){
                // player wins!!
                if(code_check == EXIT_SUCCESS){
                    printf("You won!!!");
                }
            } else {
                printf("Code should be 4 digits in range [0 to 7]\nPlease, start again!\n");
                return EXIT_FAILURE; 
            }
             if (round >= attempts)
                {
                    printf("KO! Game over!\n");
                    print_secret_code(&options);
                    return EXIT_SUCCESS;
                }
                print_rounds(round);
            }
   }
   else
   {
        printf("My_Mastermind accepts only: [-c] + a code of 4 digits in range [0 to 7] + [-t] + a number bigger than zero.\nExample: ./my_mastermind -c 1234 -t 8\n");
   }
   return EXIT_SUCCESS;
        }

    }
}
bool input_validate(char* code){
    for(int i = 0; i < my_str_len(code); i++){
        if(code[i]>=48 && code[i]<=55){
            return true;
        } else {
            printf("All input items must be integers from 1-7(inclusive)!");
            return false;
        }
    }
}

int code_check(char* input_code, bool c, bool t, int attempts, int random_code){
    int misplaced_pieces = 0;
    int wellplaced_pieces = 0;
    int i = 0;
    int j = 0;
    char* secret_code = malloc(sizeof(char) * CODE_SIZE+1);

    if(c = true){
        secret_code = user_created_code;
    } else {
        snprintf(secret_code, sizeof(char)*5, "%d", random_code);
    }
    while(input_code != '\0'){
        if(input_code[i] == secret_code[i]){
            wellplaced_pieces ++;
        }
        j = 0;
        while(secret_code[j] != '/0'){
            if( i!=j && input_code[i] == secret_code[j]){
                misplaced_pieces++;
            }
            j++;
        }
        i++;
    }
    if(wellplaced_pieces == 4){
        printf("Congratz! You won!\n");
        return EXIT_SUCCESS;
    } else {
        printf("Well placed pieces: %d\n", wellplaced_pieces);
        printf("Misplaced pieces: %d\n", misplaced_pieces);
        return EXIT_FAILURE;
    }

}

int input_validate(int argument_length, char* argument_list){
    for (int i = 1; i < argument_length; i++){

        // if there is a -c flag
        if(my_strcmp(argument_list[i], "-c")==0){
            
            // check if the following string of integers is valid
            if(is_valid_code(argument_list[i+1]) == 0){
                
                // if so, assign them to the random_code
                random_code = argument_list[i+1];
            
            // otherwise, ask the user to input a valid code
            } else {
                printf("Please enter a valid code");
                return EXIT_FAILURE;
            } 
        }
        // if there is a -t flag
        if(my_strcmp(argument_list[i], "-t") == 0){
            
            // check if it is a valid integer for rounds
            if(is_valid_attempt(atoi(argument_list[i+1]) == 0)){
                
                // set rounds to equal the number
                rounds = atoi(argument_list[i+1]);
            } else {
                printf("Please enter a valid integer for attempts > 0");
                return EXIT_FAILURE;
            } 
        }
    }
    return EXIT_SUCCESS;
}