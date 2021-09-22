char *remain(char *temp, char *final)
{
	char new;
	int start;
	int len;

	if (!ft_line_break(temp))//ojo! ultimo bucle! temp ya ha pasado a final!
	{
		free(temp);
		return (NULL);
	}
	start = ft_strlen(final);
	len = ft_strlen(temp) - ft_strlen(final)
	new = ft_substr(temp, start, len);
	free (temp);
}


char *ft_final(char *temp, char *final) //ojo! comprobar si hay o no hay salto d linea
{
	char *new;
	if (ft_line_break(temp))
		final = ft_substr(temp, 0, ft_strlen(temp) - ft_strlen(ft_line_break(temp)) + 1) //ojo! substr (temp , 0 , lentemp - len(break) + 1)
	else
		final = ft_substr(temp, 0, ft_strlen(temp));
	return (final);
}



char *update_temp(char *temp, char *buff)
{
	char *new;

	if (!temp) // ojo! primer bucle, temp no existe! minimalloc!
	{
		new = malloc(1);
		malloc[0] = '\0';
	}
	new = ft_join(temp, buff);
	free(temp);
	return (new);
}

char *read_to_temp(char *temp)
{
	char *buff;
	int nbytes;

	while (!ft_line_break(temp))
	{
		buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if(!buff)
			return (NULL);
		nbytes = read(fd, buff, BUFFER_SIZE);	//read(De donde, a donde, tamaño)
		if ((nbytes == -1) || (!temp && nbytes ==0)) //ojo! lectura erronea o bucle extra
		{
			free(buff);
			return (NULL);
		}
		buff[nbytes] = '\0'; //OJO! Cerrar buff
		temp = update_temp(temp, buff);
		free(buff);
    }
	return (temp);
}

char *get_next_line(int fd)
{
	char *final;
	static char *temp;
	
	final = NULL; //OJO, inicializar!
	if (fd < 1 || BUFFER_SIZE < 1)
		return (NULL);
	temp = ft_read_to_temp(temp);
	final = ft_final(temp, final);
	temp = ft_remain(temp, final);
	//ojo! no liberar!
	return (final)
}
