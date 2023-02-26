#include "parser.h"

int main ()
{
	char **line = ft_split("F 220,100,0", ' ');
	printf("*******> %s\n", line[0]);
}