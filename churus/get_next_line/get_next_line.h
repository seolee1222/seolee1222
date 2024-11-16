/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolee <seolee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:49:04 by seolee            #+#    #+#             */
/*   Updated: 2024/11/16 18:43:52 by seolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#define BUFFER_SIZE 1

char    *get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2, size_t len);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *str, int c);
void ptrmove(char *buffer, char *newline);
void	*ft_memcpy(void *dest, const void *src, size_t num);

#endif