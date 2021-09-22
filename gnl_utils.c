int ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char *ft_join(char *temp, char *buff)
{
	char *new;
	int i;

	i = 0;
	if (!temp || !buff) //OJO! Comprobar!
		return (NULL);
	new = malloc((ft_strlen(temp) + ft_strlen(buff) + 1) * sizeof(char));
	if(!new)
		return (NULL);
	while (*temp)
		new[i++] = *temp++;
	while (*buff)
		new[i++] = *buff++;
	new[i] = '\0';
	return (new);
}

char *ft_substr(char *str, int start, size_t len)
{
	char *new;
	int i;

	i = 0;
	if (!str || len <= 0)
		return (NULL)
	new = malloc((len + 1) * sizeof(char))
	if (!new)
		return (NULL);
	while (len) //ojo! mietras haya len
	{
		new[i++] = str[start++]; //sumatorios dentro
		len--;
	}
	new[i] = '\0';
}

char *ft_line_break(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (NULL);
	while (*str)
	{
		if (str[i] == '\n')
			return (&str[i])
		i++;
	}
	return (NULL); //ojo! return null! no ha encontrado nada 
}
