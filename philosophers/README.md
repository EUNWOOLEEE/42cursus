# philosophers
I never thought philosophy would be so deadly

## Summary
In this project, you will learn the basics of threading a process.  
You will see how to create threads and you will discover mutexes.

## Install
```sh
# in philo directory
make         # comfile ./philo
make clean   # remove temporary files
make fclean  # remove all files
make re      # make fclean and make

# in philo_bonus directory
make         # comfile ./philo_bonus
make clean  
make fclean  
make re
```

## Usage
```sh
./philo <num_of_philosophers>
```

### Check data race
```sh
# Edit Makefile
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread -g
```
