#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*res;

	i = 0;
	while (src[i])
		i++;
	if (!i)
		return (NULL);
	res = malloc(sizeof(char) * (i + 1));
	while (i >= 0)
	{
		res[i] = src[i];
		i--;
	}
	return (res);
}
/*int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	printf("%s\n", argv[1]);
	printf("%s\n", ft_strdup(argv[1]));
	return (0);
}*/
