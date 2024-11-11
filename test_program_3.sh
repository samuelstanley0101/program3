#!/usr/bin/bash

templates="program_3_templates"
example="program3"
grader="grader"

initialize_quiz() {
    if [[ $# == 0 || $@ =~ -*basic || $@ =~ -*normal ]]; then
        cp $templates/basic_quiz_template.txt quiz.txt
    elif [[ $@ =~ -*complex ]]; then
        cp $templates/complex_quiz_template.txt quiz.txt
    elif [[ $@ =~ -*eof ]]; then
        cp $templates/eof_template.txt quiz.txt
    elif [[ $@ =~ -*newline ]]; then
        cp $templates/multiple_newline_template.txt quiz.txt
    elif [[ $@ =~ -*empty ]]; then
        cp $templates/empty_template.txt quiz.txt
    else
        printf "Invalid parameter. These are the valid parameter options:\n"
        printf -- "-basic or -normal: Test with 4 names, all with 10 scores, and the file ending in one new line.\n"
        printf -- "-complex: Test edge cases for the number of scores with 6 names.\n"
        printf -- "-eof: Test when eof is found directly after the last line.\n"
        printf -- "-newline: Test when multiple newlines follow the last line before eof is found.\n"
        printf -- "-empty: Test when the file is empty.\n"
        printf -- "-all: Test all of the above options in sequence.\n"
        printf -- "-clean: Remove quiz.txt and average.txt.\n"
        exit 1
    fi
}

if [[ $@ =~ -*clean ]]; then
    rm -f quiz.txt average.txt
elif [[ $@ =~ -*all ]]; then
    printf "NORMAL TEST:\n"
    ./test_program_3.sh -normal
    printf "\n\nCOMPLEX TEST:\n"
    ./test_program_3.sh -complex
    printf "\n\nEOF TEST:\n"
    ./test_program_3.sh -eof
    printf "\n\nNEWLINE TEST:\n"
    ./test_program_3.sh -newline
    printf "\n\nEMPTY TEST:\n"
    ./test_program_3.sh -empty
else
    initialize_quiz $@
    cp $templates/empty_template.txt average.txt
    make $example
    make $grader
    printf "RUNNING EXAMPLE\n"
    ./$example
    printf "AVERAGE.TXT:\n"
    cat average.txt
    printf "QUIZ.TXT:\n"
    cat quiz.txt
    cp $templates/empty_template.txt average.txt
    initialize_quiz $@
    printf "\nRUNNING GRADER\n"
    ./$grader
    printf "AVERAGE.TXT:\n"
    cat average.txt
    printf "QUIZ.TXT:\n"
    cat quiz.txt
fi



