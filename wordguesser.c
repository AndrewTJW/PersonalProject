#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <time.h>

int main(void) { 

    //greet player
    printf("*******************************************************************************\n");
    printf("*                                                                             *\n");
    printf("*                                                                             *\n");
    printf("*                   Welcome to the WORD GUESSING mini game!                   *\n");
    printf("*                                                                             *\n");
    printf("*                                                                             *\n");
    printf("*******************************************************************************\n\n");

    //Display intructions 
    printf("INTRUCTIONS\n");
    printf("=====================================================================================================================================\n");

    printf("1. You are granted with 20 seconds to guess the scrambled word given\n");
    printf("2. Every CORRECT guesses you make, you will obtain extra 2 seconds and 1 point! Keep in mind, the time will be capped at 20 seconds!\n");
    printf("3. For every WRONG guesses you make, 2 seconds will be deducted from your remaining time!\n");
    printf("4. If you reach 30 points before your time runs out, you win!\n");
    printf("5. Have fun!\n");

    printf("=====================================================================================================================================\n");
    //ask player if they are ready
    char user_ready [50];
    bool ready = false;  
    printf("Type ""READY"" when you are ready to take on this challenge!\n");
    printf("Status: ");
    printf("test");
    printf("%s", &user_ready);

    if (strcasecmp(user_ready, "READY") == 0)
    {
        int time_remaining = 20;
        ready = true;
        while (ready == true)   
        {
            while (time_remaining > 0)
            {
                printf("%d", time_remaining);
                sleep(1);
                time_remaining --;
            }
            ready = false; 
        }
    }
return 0; 
}