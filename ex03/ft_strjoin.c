#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(int size, char **strs, char *sep)
{
	int	lng;
	int	i;
	int	j;

	lng = 0;
	i = 0;
	j = 0;
	while (i < size)
	{
		while (strs[i][j++])
			lng++;
		i++;
		j = 0;
		if (i == size)
			break ;
		while (sep[j++])
			lng++;
		j = 0;
	}
	return (lng);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	int		i;
	int		k;
	int		j;
	char	*ms;

	len = ft_strlen(size, strs, sep);
	ms = malloc(sizeof(char) * (len + 1));
	j = 0;
	i = 0;
	k = 0;
	while (i < size)
	{
		while (strs[i][k])
			ms[j++] = strs[i][k++];
		k = 0;
		i++;
		if (i == size)
			break ;
		while (sep[k])
			ms[j++] = sep[k++];
		k = 0;
	}
	ms[j] = '\0';
	return (ms);
}
/*int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	printf("%s\n", ft_strjoin(argc - 1, &argv[1], "_HER_"));
	return (0);
}*/
