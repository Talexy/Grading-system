#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char firstname[50], surname[50];
    char input[20];
    int score;
    char grade;
    char more = 'y';

    // ---NEW: open file ---
    FILE *fp = fopen("grades.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    while(more == 'y' || more == 'Y') {
    printf("Enter firstname and surname: ");
    scanf("%s %s", firstname, surname);

    getchar();   // clears leftover newline

    printf("Enter score: ");
    fgets(input, sizeof(input), stdin);

    if (input[0] == '\n') {
        grade = 'Y';
        score = 0;
    }
    else {
        score = atoi(input);

        if (score < 0 || score > 100)
            grade = 'X';
        else if (score < 40)
            grade = 'F';
        else if (score < 50)
            grade = 'E';
        else if (score < 60)
            grade = 'D';
        else if (score < 70)
            grade = 'C';
        else if (score < 80)
            grade = 'B';
        else
            grade = 'A';
    }

    printf("%s %s %d Grade:%c\n", firstname, surname, score, grade);

    // ---NEW: write to file ---
    fprintf(fp, "%s %s %d Grade:%c\n", firstname, surname, score, grade);

    printf("Do you want to enter another student? (y/n): ");
    scanf(" %c", &more);
    }
    fclose(fp); //close file
    printf("All grades saved to grades.txt!\n");

    return 0;
}