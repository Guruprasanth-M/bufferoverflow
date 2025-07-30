/*
 * File: main.c
 * Description: Demonstrates a classic buffer overflow vulnerability where
 * writing to a char buffer overwrites a nearby integer on the stack.
 * This showcases an old compiler bug (seen in GCC 3.x or under certain flags)
 * where char is written first and adjacent int gets corrupted.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Vulnerable function where overflow occurs
void process_input(char *user_input) {
    char buffer[8];         // Small character buffer (8 bytes)
    int is_admin = 0;       // Sensitive variable, should remain 0

    printf("[Before] is_admin: %d (should be 0)\n", is_admin);

    // Dangerous function: No bounds check!
    // If input > 8 bytes, it overwrites is_admin on stack.
    strcpy(buffer, user_input);

    printf("[After]  is_admin: %d\n", is_admin);

    if (is_admin != 0) {
        printf("[!] Privilege Escalation Detected: You are now admin!\n");
    } else {
        printf("[*] Regular user privileges.\n");
    }
}

// Main function to handle CLI arguments
int main(int argc, char *argv[]) {
    printf("=== Buffer Overflow Demo ===\n");

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    process_input(argv[1]);

    return 0;
}
