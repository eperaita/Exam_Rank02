/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:13:45 by eperaita          #+#    #+#             */
/*   Updated: 2021/09/22 10:14:50 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);
char *ft_read_to_temp(int fd, char *temp);
char *update_temp(char *temp, char *buff);
char *ft_final(char *final, char *temp);
char *ft_remain(char *temp, char *final);
char *ft_substr(char *str, int start, size_t len);
char *ft_join(char *temp, char *buff);
char *ft_line_break(char *str);
int ft_strlen(char *str);

#endif
