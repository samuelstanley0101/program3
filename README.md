# Program 3
This assignment deals with file I/O, and thus requires test input from several sets of files. This can be rather inconvenient, since test input must be copied from file to file for each individual test. Therefore I have created a set of template input files and a script to test the student's code using all of them.

## Usage
Copy the student's full code into main.c.

`./test_program_3.sh [parameter]`

For each individual test, the example solution found in *program3.c* will be run on the input first and *average.txt* and *quiz.txt* will be printed to show the intended result of the program. Then the input files will be reset, the student's code from *main.c* will be run, and *average.txt* and *quiz.txt* will be printed again to be compared to the intended output.

### Parameters
`-basic` or `-normal` : Test using 4 lines of input, each with a name and 10 quiz scores, and the file ending in one new line.

`-complex` : Test using 6 lines of input, each with a name and various amounts of quiz scores.

`-eof` : Test when eof is found directly after the last line of input.

`-newline` : Test when multiple newlines follow the last line of input before eof is found.

`-empty` : Test when the file is empty.

`-all` : Test all of the above options in sequence.

`-clean` : Remove quiz.txt and average.txt.

## Requirements
This script will only work if you have access to a bash shell. If you are running on Linux or Mac OS you should have access by default, although you may need to change the first line in *test_program_3.sh* to the correct path to bash on your computer (`#![your file path]`). If you are running on Windows you can [download Windows Subsystem for Linux (WSL)](https://learn.microsoft.com/en-us/windows/wsl/install) for a more permanent solution or, for a short-term and slightly less convenient solution, you can [SSH to your UML CS account](https://www.uml.edu/sciences/computer-science/cs-infrastructure/unix-connectivity.aspx).