/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:55:43 by eperaita          #+#    #+#             */
/*   Updated: 2021/09/21 10:11:20 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int count;

	count = 0;
	while (str[count] && count < i)
	{
		if (str[count] == a)
			return (1);
		count++;
	}
	return (0);
}

int main (int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (!ft_check_repeat(argv[1], argv[1][i], i))
				write(1, &argv[1][i], 1);
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			if(!ft_check_repeat(argv[1], argv[2][i], ft_strlen(argv[1])) && !ft_check_repeat(argv[2], argv[2][i], i))
				write(1, &argv[2][i], 1);
			i++;
		}
	}		
	write(1, "\n", 1);
	return (0);					
}
