# ft_printf
Because ft_putnbr() and ft_putstr() aren’t enough

## Summary
The goal of this project is pretty straightforward. You will recode printf().  
You will mainly learn about using a variable number of arguments. How cool is that??  
It is actually pretty cool :)

## Install
```sh
gcc -Wall -Wextra -Werror main.c /path/libftprintf.a
```

## Usage
```sh
int main()
{
    int num = 42;
    char *str = "Hello, world!";
    void *ptr = &num;

    int size = ft_printf("Number: %d\n", num);
    size += ft_printf("String: %s\n", str);
    size += ft_printf("Pointer: %p\n", ptr);

    printf("Total size: %d\n", size);

    return 0;
}
```

## Format specifier
`%c` : Single character  
`%s` : String  
`%p` : Pointer adress  
`%d``%i` : Decimal number  
`%x` : Number in hexadecimal using lowercase letters  
`%X` : Number in hexadecimal using uppercase letters  
`%%` : Print the percent symbol.
