#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char* quiz_file = "quiz.txt";
const char* average_file = "average.txt";

// extract a single string surrounded by whitespace from input, place it in str, and null
// terminate it. Characters will be read until whitespace is found after the string or until
// size - 1 characters are read. The noc from the last scanf is returned
int read_string(FILE* input, char* str, int size);

// extract a first and last name from input and write them to output as "last, first". If EOF
// is reached before both names can be read, nothing will be written to output. The noc from
// the last scanf is returned
int extract_name(FILE* input, FILE* output);

// extract all quiz scores before a newline or EOF from input and write them to output, each
// right justified in 4 characters space. Write the average of the quiz scores to output right
// justified in 10 characters space. The noc from the last scanf is returned.
int extract_scores(FILE* input, FILE* output);

int main(void) {
    // open files
    FILE* quiz = fopen(quiz_file, "r");
    FILE* average = fopen(average_file, "w");

    // print header
    fprintf(average, "%-20s", "Name");
    for (int i = 1; i <= 10; i++) {
        fprintf(average, "%4d", i);
    }
    fprintf(average, "%10s\n", "Average");

    // write information
    int noc = extract_name(quiz, average);
    while (noc != EOF) {
        noc = extract_scores(quiz, average);
        fprintf(average, "\n");
        noc = extract_name(quiz, average);
    }
    
    // close files
    fclose(quiz);
    fclose(average);

    // copy average to quiz
    quiz = fopen(quiz_file, "w");
    average = fopen(average_file, "r");
    char c;
    noc = fscanf(average, "%c", &c);
    while (noc != EOF) {
        fprintf(quiz, "%c", c);
        noc = fscanf(average, "%c", &c);
    }
    fclose(quiz);
    fclose(average);

    return 0;
}

int read_string(FILE* input, char* str, int size) {
    char c;
    int noc = fscanf(input, "%c", &c);
    // skip whitespace
    while (noc != EOF && isspace(c)) {
        noc = fscanf(input, "%c", &c);
    }
    // read string
    int i = 0;
    while (noc != EOF && !isspace(c) && i < size - 1) {
        str[i] = c;
        i++;
        noc = fscanf(input, "%c", &c);
    }
    // null terminate string
    if (i < size)
        str[i] = '\0';
    return noc;
}

int extract_name(FILE* input, FILE* output) {
    char firstname[21];
    char fullname[21];
    int noc = read_string(input, firstname, sizeof(firstname));
    noc = read_string(input, fullname, sizeof(fullname));
    if (noc != EOF) {
        strncat(fullname, ", ", sizeof(fullname) - (strlen(fullname) + 1));
        strncat(fullname, firstname, sizeof(fullname) - (strlen(fullname) + 1));
        fprintf(output, "%-20s", fullname);
    }
    return noc;
}

int extract_scores(FILE* input, FILE* output) {
    int score, total = 0, noc, i = 0;
    noc = fscanf(input, "%d", &score);
    while (noc > 0 && i < 10) {
        fprintf(output, "%4d", score);
        total += score;
        i++;
        noc = fscanf(input, "%d", &score);
    }
    while (i < 10) {
        fprintf(output, "%4d", 0);
        i++;
    }
    fprintf(output, "%10.4f", total / 10.0);
    return noc;
}