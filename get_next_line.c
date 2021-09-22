/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:03:57 by eperaita          #+#    #+#             */
/*   Updated: 2021/09/22 10:15:06 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *ft_remain(char *temp, char *final)
{
	char *new_temp;
	int	len;
	int	start;

	if (!ft_line_break(temp))
	{
		free (temp);
		return (NULL);
	}
	len = ft_strlen(temp) - ft_strlen(final);
	start = ft_strlen(final);
	new_temp = ft_substr(temp, start, len); 
	free (temp);
	return (new_temp);
}

char *ft_final(char *final, char *temp)
{
	size_t	len;

	len = 0;
	if(ft_line_break(temp))
		final = ft_substr(temp, 0, ft_strlen(temp) - ft_strlen(ft_line_break(temp)) + 1);
	else
		final = ft_substr(temp, 0, ft_strlen(temp));
	return (final);
}

char *update_temp(char *temp, char *buff)
{
	char *new;
	int i;

	i = 0;
	if (!temp)
	{
		temp = malloc (1);
		temp[0] = '\0';
	}
	new = ft_join(temp, buff);
	free (temp);
	return (new);	
}

char *ft_read_to_temp(int fd, char *temp)
{
	char *buff;
	int nbytes;

	nbytes = 1;
	while (!ft_line_break(temp) && nbytes > 0)
	{
		buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return (0);
		nbytes = read(fd, buff, BUFFER_SIZE);
		if ((nbytes == 0 && !temp) || nbytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[nbytes] = '\0';
		temp = update_temp(temp, buff);
		free (buff);
	}
	return (temp);
}

char *get_next_line(int fd)
{
	char *final;
	static char *temp;

	final = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp = ft_read_to_temp(fd, temp);
	final = ft_final(final, temp);
	temp = ft_remain(temp, final);
	return (final);
}

