#include <unistd.h>
#include <stdio.h>

int	wh_sp(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	if (c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

int	ft_condition(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || wh_sp(base[i]))
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	numb(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (c + 10 - 'A' );
}

int	negative(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

int	ft_convert_base2(char *str, char *base)
{
	int	i;
	int	sign;
	int	res;

	res = 0;
	i = 0;
	sign = 1;
	if (!ft_condition(base))
		return (0);
	while (str[i++])
	{
		if (wh_sp(str[i - 1]) || str[i - 1] == '+' || str[i - 1] == '-')
		{
			if ((str[i - 1] == '-' || str[i - 1] == '+') && wh_sp(str[i]))
				break ;
			sign *= negative(str[i - 1]);
			continue ;
		}
		if (numb(str[i - 1]) >= ft_condition(base) || numb(str[i - 1]) < 0)
			break ;
		res = res * ft_condition(base) + sign * numb(str[i - 1]);
		if (numb(str[i]) >= ft_condition(base) || numb(str[i]) < 0)
			break ;
	}
	return (res);
}
/*int	main(void)
{
	int	res;

	res = ft_convert_base2("  +--++-100101fsdf ", "01");
	printf("%d", res);
	return (0);
}*/
