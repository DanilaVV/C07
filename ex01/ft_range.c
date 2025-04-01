#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*ms;
	int	i;

	i = min;
	if (min >= max)
		return (NULL);
	ms = malloc(sizeof(int) * (max - min));
	while (i < max)
	{
		ms[i - min] = i;
		i++;
	}
	return (ms);
}
/*int	main(void)
{
	int	i;
	int	size;
	int	*ms;

	i = 0;
	size = 9 - 3;
	ms = ft_range(3, 9);
	while (i < size)
	{
		printf("%d ", ms[i]);
		i++;
	}
	puts("");
	return(0);
}*/
