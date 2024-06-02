# minishell
As beautiful as a shell

## Summary
This project is about creating a simple shell.  
Yes, your own little bash.  
You will learn a lot about processes and file descriptors.

## Install
```sh
make         # comfile ./minishell
make clean   # remove temporary files
make fclean  # remove all files
make re      # make fclean and make
```

## Usage
__Built-in commands__
```sh
# start minishell
./minishell
```

```sh
# echo -n
echo "Hello, World!"
echo -n "Hello, World!"
```

```sh
# cd
cd ..
cd /usr/local/bin
```

```sh
# pwd
pwd
```

```sh
# export
export TEST_VAR="Test Value"
```

```sh
# unset
unset TEST_VAR
```

```sh
# env
env
```

```sh
# exit minishell
exit
```

__Extra features__
```sh
# Redirection
echo "Hello, World!" > hello.txt
```

```sh
# Pipe
echo "Hello, World!" | grep "World"
```

```sh
# heredoc
cat << EOF
> Hello, World!
> EOF
```

```sh
# Environment variable expansion
echo $USER
```

```sh
# Exit status
echo $?
```

```sh
# Ctrl+C, Ctrl+D, Ctrl+\
Ctrl+C  # reset prompt
Ctrl+D  # exit shell
Ctrl+\  # do nothing
```

__External commands__
```sh
Anything you want
```
