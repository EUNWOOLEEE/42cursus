# get_next_line
Reading a line from a fd is way too tedious

## Summary
This project is about programming a function that returns a line read from a file descriptor.

## Usage
```cpp
int main() {
    fd = open("example.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("Failed to open file");
        return 0;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    return 0;
}
```
