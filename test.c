#include "parser.h"

int main ()
{
	char *line = ft_strdup("adjane");
	char *line_2 = ft_strdup("khawla");
	line = ft_strjoin(line, line_2);
	free (line_2);
	printf("line == %s\n", line);
}