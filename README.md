# PIPEX
The main goal of this project is to create a simplified version of the Unix command line pipe command, enabling multiple processes to communicate with each other through pipes.

## Overview
Pipex allows you to implement a command line utility that mimics the functionality of piping commands together using:

1. Process creation using fork().
2. Executing commands using execve().
3. Handling standard input/output redirection.
4. Using pipes to connect the output of one process to the input of another.

## Features
1. Multiple Commands: Execute a sequence of commands connected by pipes.
2. Input/Output Redirection: Read from a file and write output to another file.
3. Error Handling: Properly handle errors related to system calls and invalid commands.
