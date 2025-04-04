#include <stdlib.h>
#include <stdio.h>

int	ft_size(char *str, char *sep)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = 0;
	while (str[i])
	{
		while (sep[j] && str[i + j] && sep[j] == str[i + j])
			j++;
		if (!sep[j])
			size++;
		i++;
		j = 0;
	}
	return (size);
}

int	*ft_pos(char *str, char *sep)
{
	int	i;
	int	j;
	int	size;
	int	len;
	int	*ms;

	i = 0;
	j = 0;
	size = ft_size(str, sep);
	len = size;
	ms = malloc(sizeof(int) * size);
	while (str[i])
	{
		while (sep[j] && str[i + j] && sep[j] == str[i + j])
			j++;
		if (!sep[j])
		{
			ms[len - size] = i;
			size--;
		}
		i++;
		j = 0;
	}
	return (ms);
}

int	ft_msize(int *ms, char *mms, int size)
{
	int	i;
	int	j;
	int	k;
	int	res;

	i = 0;
	j = 0;
	k = 0;
	res = 0;
	while (mms[j])
	{
		while (j++ <= ms[i])
			k++;
		if (k - 1 > 0)
			res++;
		i++;
		if (i == size && mms[j])
		{
			res++;
			break ;
		}
		k = 0;
	}
	return (res);
}

int	ft_strlen(char *st)
{
	int	i;

	i = 0;
	while (st[i])
		i++;
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	**ms;

	j = 0;
	k = 0;
	i = ft_msize(ft_pos(str, charset), str, ft_size(str, charset));
	ms = malloc(sizeof(char*) * i + 1);
	while (i > 0)
		ms[i-- - 1] = malloc(sizeof(char) * 100);
	while (str[i])
	{
		if (i == ft_pos(str, charset)[k])
		{
			if ((i && !k) || (i && i - ft_strlen(charset) != ft_pos(str, charset)[k - 1]))
			j++;
			k++;
			i += ft_strlen(charset);
			continue ;
		}
		ms[j][i] = str[i++];/////////////
	}
	ms[ft_msize(ft_pos(str, charset), str, ft_size(str, charset))] = 0;
	return (ms);
}
int	main(void)
{
	int	i = 0;
	char *st = "Danila  Vozniuk  1993 ";
	char *sep = "";
	int size = ft_size(st, sep);
	int *ms = ft_pos(st, sep);
	int msize = ft_msize(ms, st, size);
	char **mms = ft_split(st, sep);
	puts(st);
	printf("%d\t%d\n", size, msize);
	puts(mms[0]);
	puts(mms[1]);
	puts(mms[2]);
	/*while (mms[i])
		puts(mms[i++]);*/
	return (0);
}
