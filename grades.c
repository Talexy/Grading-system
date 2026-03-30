#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char firstname[50], surname[50], score_str[50];
    int score;
    char grade;
    
    printf("Firstname Surname Score Grade\n");
    
    while (fgets(score_str, sizeof(score_str), stdin) != NULL) {
        // Parse the input line
        if (sscanf(score_str, "%s %s %s", firstname, surname, score_str) < 3) {
            // If we have firstname and surname but no score (blank), print Y
            if (sscanf(score_str, "%s %s", firstname, surname) == 2) {
                printf("%s %s - Y\n", firstname, surname);
            }
            continue;
        }
        
        //try to parse score
        char *endptr;
        score = strtol(score_str, &endptr, 10);
        
        // Check if score is a valid number
        if (*endptr != '\0' && *endptr != '\n') {
            // Invalid input
            printf("%s %s %s Y\n", firstname, surname, score_str);
            continue;
        }
        
        // Determine grade based on score
        if (score < 0 || score > 100) {
            grade = 'X';
        } else if (score < 40) {
            grade = 'F';
        } else if (score < 50) {
            grade = 'E';
        } else if (score < 60) {
            grade = 'D';
        } else if (score < 70) {
            grade = 'C';
        } else if (score < 80) {
            grade = 'B';
        } else {
            grade = 'A';
        }
        
        printf("%s %s %d %c\n", firstname, surname, score, grade);
    }
    
    return 0;
}
