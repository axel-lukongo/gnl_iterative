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
	/*str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	int ret;
	char buf[7];
	ret = read(fd, buf, 5);
	printf("ret1 = %d \n",ret);
	buf[ret] = '\0';
	printf("ret1 = %d \n",ret);*/
}