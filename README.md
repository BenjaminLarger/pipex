# pipex

`pipex` is a project in the 42 curriculum that involves replicating the functionality of shell pipelines. This project helps you understand inter-process communication, system calls, and the use of pipes in Unix-like operating systems.

## Overview

`pipex` is designed to simulate the behavior of shell pipelines, enabling the redirection of the output of one program to the input of another. This project covers important concepts such as process creation, file descriptors, and the use of the `pipe` and `exec` family of functions.

## Features

- **Input and Output Redirection:** Implement input and output redirection using file descriptors.
- **Pipe Creation:** Create and manage pipes to connect the output of one process to the input of another.
- **Process Creation:** Use `fork` to create child processes and `exec` to replace the process image.
- **Error Handling:** Properly handle errors and edge cases, ensuring robust and reliable behavior.

## Getting Started

To get started with `pipex`, clone the repository and compile the program using the provided Makefile:

```bash
git clone https://github.com/BenjaminLarger/pipex.git
cd pipex
make
