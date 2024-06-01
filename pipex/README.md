# pipex

## Summary
This project will let you discover in detail a UNIX mechanism that you already know by using it in your program.

## Install
```sh
make         # comfile ./pipex
make bonus   # comfile bonus ./pipex
make clean   # remove temporary files
make fclean  # remove all files
make re      # make fclean and make
```

## Usage
__Basic usage__
```sh
# input
$> ./pipex file1 cmd1 cmd2 file2

# expect
$> < file1 cmd1 | cmd2 > file2

# examples
$> ./pipex infile ls -l'' wc -l'' outfile
$> ./pipex infile grep a1'' wc -w'' outfile
```
__Bonus usage: multiple pipe__
```sh
# input
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2

# expect
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```
__Bonus usage: here_doc__
```sh
# input
$> ./pipex here_doc LIMITER cmd cmd1 file

# expect
cmd << LIMITER | cmd1 >> file
```
