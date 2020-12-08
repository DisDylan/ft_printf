#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%05d", argv[1]);
	printf("%0.d", argv[1]);
	printf("%0*d", argv[1]);
}