#include <stdlib.h>
#include <stdio.h>

int	wh_sp(char *c);

int	ft_condition(char *base);

int	ft_convert_base2(char *str, char *base);

int	ft_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_size(int nm, int base)
{
	int	size;

	size = 0;
	if (nm < 0)
		size++;
	while (nm)
	{
		nm /= base;
		size++;
	}
	size++;
	return (size);
}

char	ft_numb(int c)
{
	if (c >= 0 && c <= 9)
		return (c + '0');
	return (c - 10 + 'A');
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nm;
	int		i;
	int		size;
	char	*res;

	if (!ft_condition(base_from) || !ft_condition(base_to))
		return (NULL);
	nm = ft_convert_base2(nbr, base_from);
	size = ft_size(nm, ft_base(base_to));
	res = malloc(sizeof(char) * size);
	res[size - 1] = '\0';
	i = size - 2;
	if (nm < 0)
		res[0] = '-';
	while (i > 0)
	{
		res[i] = ft_numb(ft_abs(nm % ft_base(base_to)));
		nm /= ft_base(base_to);
		i--;
	}
	if (nm)
		res[0] = ft_numb(ft_abs(nm % ft_base(base_to)));
	return (res);
}
/*int	main(void)
{
	printf("%s\n", ft_convert_base("  -++--0101001", "01", "0123456789"));
	printf("%d\n", ft_base("01"));
	return (0);
}*/
