#include"get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("file", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
}
