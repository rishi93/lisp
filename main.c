/*
    Interact with the language dynamically. This system is called a REPL.
    Read-Evaluate-Print-Loop.
*/
#include <stdio.h>
#include <string.h>

#include <editline/readline.h>
// It looks like add_history is defined in <editline/readline.h> itself
// #include <editline/history.h>
// #include <histedit.h>

// free() is in stdlib.h
#include <stdlib.h>

// Declare a buffer for user input of size 2048
// static char input[2048];
/*
    A static variable inside a function keeps its value between invocations.

    A static global variable or function is "seen" only in the file in which
    it's declared.
*/

int main(int argc, char** argv) {
    // Print version and exit information
    puts("Lispy version 0.0.1");
    puts("Type exit or quit to exit\n");

    /* In a never ending loop */
    while (1) {
        /*
            stdin and stdout are defined in stdio.h, and are special variables
            representing input from, and output to the command line.
        */

        // Output our prompt
        // fputs does not append a newline character
        // fputs("lispy> ", stdout);

        // Read a line of user input of maximum size 2048
        // fgets will store the newline character as well

        // When you press arrow keys, fputs prints weird characters like
        // ^[[D and ^[[C. What we really want is to be able to move around
        // on the line
        char *input = readline("lispy> ");

        // Add input to history, to record it
        add_history(input);

        // Both fgets and fputs require some file to read from, or write to
        // stdin and stdout are defined in <stdio.h> and are special
        // variables representing input to, output from the commandline 
        // fgets(input, 2048, stdin);

        // Replace the newline character with a null terminator
        // input[strlen(input) - 1] = '\0';
        // readline strips the trailing newline character from the input

        // Or replace wherever you find \n with \0
        // input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0) {
            // Exit from the REPL loop
            break;
        }

        // Echo input back to user
        /*
            printf has format specifiers like
            %d for integers,
            %f for floats,
            %s for strings, and so on...
        */
        printf("No you're a %s\n\n", input);

        // Unlike fgets, which writes to some existing buffer, the readline
        // function allocates new memory when it is called.
        // Free the memory used by input
        free(input);
    }

    return 0;
}