#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	i = 0;
	size = max - min;
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * size);
	if (!range)
		return (-1);
	while (i < size)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);
}
/*int	main(void)
{
	int min;
	int max;
	int i;
	int *ms;

	min = 3;
	max = 7;
	i = 0;
	printf("%d\n\n", ft_ultimate_range(&ms, min, max));
	while (i < max - min)
	{
		printf("%d ", ms[i]);
		i++;
	}
	puts("");
	return (0);
}*/
