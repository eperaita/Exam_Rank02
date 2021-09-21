#include <unistd.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_check_repeat(char *str, char a, int i)
{
	int j;

	j = 0;
	while (str[j] && j < i)
	{
		if (str[j] == a)
			return (1);
		j++;
	}
	return (0);
}

int main (int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 3)
	{
		while(argv[1][i])
		{
			if (ft_check_repeat(argv[2], argv[1][i], ft_strlen(argv[2])) && !ft_check_repeat(argv[1], argv[1][i], i))
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
