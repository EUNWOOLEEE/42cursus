# push_swap
Because Swap_push isn’t as natural

## Summary
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.  
To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

## Install
```sh
make         # comfile ./push_swap
make bonus   # comfile with ./checker
make clean   # remove temporary files
make fclean  # remove all files
make re      # make fclean and make
```

## Usage
```sh
jot -r 100 1 500 | sort -uR | xargs ./push_swap        # make random numbers and remove duplicates
seq 500 | sort -R | xargs ./push_swap                  # make unsorted numbers from 1 to 500

wc -l  # count the number of commands

ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG  # check sorting
```
