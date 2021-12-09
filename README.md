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
| **built-in.c** |  |
| **function_match_1.c** | |
| **function_match_2.c** | |
| **functions_help_1** | |
| **functions_help_2** | |
| **header.h** | |
| **main.c** | |
| **match.c** | |

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

* **Please, read the AUTHORS file**
* **https://github.com/Ineffable22/simple_shell**