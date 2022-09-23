#include "my_mastermind.h"


int main(int argc, char** argv){
    
    // int* random_code;
    // random_code = random_code_generator(1111, 7777);
    
    char *random_code = malloc(CODE_LEN*sizeof(char));
    char *code = malloc(CODE_LEN*sizeof(char));
    random_code = random_code_generator(CODE_LEN, code);
    
    int rounds = 10;
    
    // first, we need to check what is passed into the cli

    // we need to go through the arguments passed in the cli, validate them, then assign them appropriately
    
    for (int i = 1; i < argc-1; i++){
        
        // if there is a -c flag
        if(my_strcmp(argv[i], "-c") == 0){
            
            // check if the following string of integers is valid
            if(is_valid_input(argv[i+1]) == true){
                secret_code_transform(argv, random_code, i);
            
            } else if (is_valid_input(argv[i+1]) == false) {
            
                printf("Please enter a valid code\n");
            
            } 
        }

        // if there is a -t flag
        if(my_strcmp(argv[i], "-t") == 0){
            
            // check if it is a valid integer for rounds
            if(integer_check(argv[i+1]) == true){
                
                // set rounds to equal the number 
                rounds = atoi(argv[i+1]);

            } else {
                printf("Invalid '-t' value, must be an integer > 0\nRounds will be set at 10\n");
            } 
        }
    }
    

    // now lets play the game
    printf("Will you find the secret code?\nPlease enter a valid guess\n");

    for(int attempts = 0; attempts < rounds; attempts++){
        
        printf("------\nROUND: %d\n", attempts);

        char code[128];
        int size;
        label: 
        size = read(0, code, sizeof(code));
        
        if(atoi(code) == 0){
            return EXIT_FAILURE;
        }
        
        if(input_validate(code) != 0){

            if(check_code(code, random_code) == EXIT_SUCCESS){
                return EXIT_SUCCESS;
            } 

        } else {
            printf("Wrong input!\n");
            goto label;
        }
    }
    int i = 0;
    printf("KO! Game over!\nThe secret code was: ");
    while(i < CODE_LEN){
        printf("%d", random_code[i]);    
        i++;
    }
    printf("\n");
    
    return EXIT_SUCCESS;
}

