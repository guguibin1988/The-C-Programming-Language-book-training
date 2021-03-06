/* 
    <The C programming language> - 2nd Edition by K&R
    Example 1.5: Character Input and Output
    copy input to output one character at a time:
    //----------------------------------------------------
        read a character
            while (character is not end-of-file indicator)
            output the characterjust read
            read a character
    //----------------------------------------------------

    compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-3-28
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

main() {
    int c;// not type of char, because type of int contains the value of EOF(commonly -1)

    /* 1.5.1: file copy; 1st version
    c = getchar();
    while (c != EOF) {
        putchar(c);
        printf("in processing...\n");// for test
        c = getchar();
    } */ 

    /* 1.5.1: file copy; 2nd version: 
       assignment "c = getchar()" as a part of the expression which is more compact
    while ((c = getchar()) != EOF) {
        putchar(c);
        printf("in processing...\n");// for test
    } */

    /* 1. chars counting 
       2. words counting 
       3. output the char string 
    */
    bool restart = true;
    bool inTheWord = false;
    double nChars = 0;
    double nWords = 0;
    while((c = getchar()) != EOF) {
        if (c == '\n' || c == 26) {// end of the text. see the comment below
            printf("\n");
            printf("the number of chars is: %.0f\n", nChars);
            printf("the number of words is: %.0f\n", nWords);
            restart = true;
            nChars = 0;
            inTheWord = false;
            nWords = 0;
        }
        else {
            if (restart) {
                restart = false;
                printf("the input chars is    :");
            }

            putchar(c);
            nChars++;

            if (c == ' ' || c == '\t' || c == '\n') {
                inTheWord = false;
            }
            else {
                if (!inTheWord) {
                    nWords++;
                    inTheWord = true;
                }
            }
        }
    }
    printf("EOF is inputed, stop running\n");

    /* Test reason for reaching EOF. 
    if (feof(stdin)) {         // if failure caused by end-of-file condition
       puts("End of file reached");
    }
    else if (ferror(stdin))   // if failure caused by some other error
    {
       perror("getchar()");
       fprintf(stderr,"getchar() failed in file %s at line # %d\n", __FILE__,__LINE__-9);
       exit(EXIT_FAILURE);
    }*/

}