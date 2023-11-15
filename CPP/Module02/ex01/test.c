#include <stdio.h>

int main()
{
	float f = 10860;
	u_int32_t* binary = (u_int32_t*)&f;


    // 각 비트 출력
	printf("float %lf\n", f);
    for (int i = 31; i >= 0; i--) {
        printf("%d", (*binary >> i) & 1);
        if (i % 8 == 0)  // 8비트씩 끊어서 출력
            printf(" ");
    }
	printf("\n\n");

	for(int j = 0; j < 8; j++)
	{
		f *= (1 << 1);
		printf("float %lf\n", f);
		for (int i = 31; i >= 0; i--) {
			printf("%d", (*binary >> i) & 1);
			if (i % 8 == 0)
				printf(" ");
		}
		printf("\n");

		int n = (int)f;
		printf("int %d\n", n);
		for (int i = 31; i >= 0; i--) {
			printf("%d", (n >> i) & 1);
			if (i % 8 == 0)
				printf(" ");
		}

		printf("\n\n");
	}

	return (0);
}