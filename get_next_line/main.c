#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd = open("./text.txt", O_RDONLY);
	while(1)
	{
		char *str = get_next_line(fd);
		
		if(!*str)
			break;

		printf("%s\n", str);
	}
}