#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int main()
{
	int fd1 = open("./text1.txt", O_RDONLY);
	int fd2 = open("./text2.txt", O_RDONLY);

	char *str;

	str = get_next_line(fd1);
	printf("%d, %s\n", *str, str);

	str = get_next_line(fd2);
	printf("%d, %s\n", *str, str);

	str = get_next_line(fd1);
	printf("%d, %s\n", *str, str);

	str = get_next_line(fd2);
	printf("%d, %s\n", *str, str);

	str = get_next_line(fd1);
	printf("%d, %s\n", *str, str);

	str = get_next_line(fd1);
	printf("%d, %s\n", *str, str);

	str = get_next_line(fd1);
	printf("%d, %s\n", *str, str);

	str = get_next_line(fd1);
	printf("%d, %s\n", *str, str);

	// while(1)
	// {
	// 	char *str = get_next_line(fd);

	// 	if(!str)
	// 		break;

	// 	printf("%s\n", str);
	// }
	// return 0;
}

//yuza\ndanggo