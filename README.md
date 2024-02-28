# PIPEX

## Use
Create an infile, run make, and process the folowing <infile "ls -l" "wc -l" outfile>
Bonus : make bonus => run : <./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2> OR <./pipex here_doc LIMITER cmd cmd1 file>

## Principle
Create pipes for to allow to process to communicate.
Create forks to create multiple process.
Duplicate infile as input, duplicate pipe write end as output, execute command IN child process.
Duplicate pipe read end as input, duplicate outfile as output, execute cmmand IN parent process.

## Documentation
https://stackoverflow.com/questions/8860895/how-do-you-use-dup2-and-fork-together
