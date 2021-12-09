# C - Simple Shell Project.
<h1 align ="center">
<img src="https://assets.website-files.com/6105315644a26f77912a1ada/610540e8b4cd6969794fe673_Holberton_School_logo-04-04.svg" height="40%" width="30%">
</h1>

## Overview
Simple_shell repository contains files of our version of Shell
which is a simple UNIX shell based on bash and Sh. Our command
line version of the interpreter is written in C language.

## Description
Simple Shell is a program that emulates a shell (bash) in an
interactive mode. This is a command language interpreter
that executes commands read from standard input.

## Files Contained on this repository

| File | Description |
|--|--|
| **AUTHORS** | Contains the authors of the Simple Shell program. |
| **README.md** | Contains an overview of Simple Shell. Important things that you should know before executes our Simple Shell program. |
| **built-in.c** | **built_in:** Checks cmd structure and prints their system calls. **my_getline:** Reads and store the input console. **_strtok:** Divides the buffer in tokens when it finds spaces. **flag_0:** Checks if there are errors on the first buffer. **flag_1:** Checks if there is more than 1 buffer. |
| **function_match_1.c** |  **print_env:** Prints the enviroment. **shell_printenv:** Prints a single line of the enviroment. **shell_setenv:** Creates a value at the enviroment. **shell_unsetenv:** Deletes a value at the enviroment. |
| **function_match_2.c** | **shell_clear:** Clears the console. **change_directory:** Changes the directory. **change_path:** Changes the PATH. |
| **functions_help_1** | **_concat:** Concatenates the buffer with 'n' arguments. |
| **functions_help_2** | **my_getenv:** Searches a key string into the enviroment. **_dstrlen:** Calculates the size of the string of a double pointer. **_free:** Frees the double pointer. **_drealloc:** Reallocates memory depending on flags. |
| **header.h** | Contains the structures used in our code. Also contains all libraries needed. |
| **main.c** | **main:** Creates a simple shell. **exit_time:** Compares buffer with 'exit' ignoring spaces. **bypass:** Controls the routes of the structure of cmd. **signal_betty:** Prints \nCisfun$ after signal with betty style. |
| **match.c** | **match:** Matches the input with the stored string. **function_fork:** Divides the process before executes the system call execve(). |

## Compilation

Usage: **Shell**
Simple shell is started with the standard input connected to the terminal. To start, compile all .c located in this repository by using this command:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o Shell
```
## Example

Usage: **hsh**
```c
jairocast2@ubuntu:~/shell$ ./Shell
#Cisfun$
#Cisfun$ ls
AUTHORS      function_match_1.c   functions_help_1.c   header.h   match.c        README.md
 built-in.c   function_match_2.c   functions_help_2.c   main.c
#Cisfun$ exit
jairocast2@ubuntu:~/shell$
````



## Command List

| Commands | Description |
|--|--|
| `ls` | ls (from list), allows you to list the contents of a directory or file. |
| `pwd` | Pwd (from print working directory) is a convenient command that prints our path or location when executed, so we avoid getting lost if we are working with multiple directories and folders. |
| `touch` | touch creates an empty file, if the file exists it updates the modification time. |
| `rm` | rm (from remove) is the command needed to delete a file or directory. |
| `mkdir` | mkdir (from make directory) creates a new directory taking into account the current location. |
| `cp` | cp (from copy) copies a source file or directory to a target fileor directory. |
| `rmdir` | rmdir (from ReMove DIRectory) This command is used to delete empty directories or subdirectories. |
| `cd` | cd (from change directory) you will need this command to access a path other than the one you are in. basically it is for navigating from directory to directory. |
| `exit` | exits the current shell. 0 status value indicates successful execution, another value represents unsuccessful execution. |
| `cat` | cat (from concatenate), is a wonderful utility that allows us to visualize the content of a text file in the standard output, without the need of an editor. |

## Authors and Github

* **Please, read the [AUTHORS](https://github.com/Ineffable22/simple_shell/blob/main/AUTHORS) file**
* **https://github.com/Ineffable22/simple_shell**