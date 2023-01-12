#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int main()
{
	int fd1 = open("./text1.txt", O_RDONLY);
	// int fd2 = open("./text2.txt", O_RDONLY);

	char *str;

	str = get_next_line(fd1);
	printf("%s\n", str);

	close(fd1);
	str = get_next_line(fd1);
	printf("%s\n", str);
	


	fd1 = open("./text1.txt", O_RDONLY);
	str = get_next_line(fd1);
	printf("%s\n", str);

	str = get_next_line(fd1);
	printf("%s\n", str);




	// str = get_next_line(fd2);
	// printf("%s\n", str);

	// str = get_next_line(fd1);
	// printf("%s\n", str);

	// str = get_next_line(fd1);
	// printf("%s\n", str);

	// str = get_next_line(fd2);
	// printf("%s\n", str);
}
