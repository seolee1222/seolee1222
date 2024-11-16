/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolee <seolee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:12:18 by seolee            #+#    #+#             */
/*   Updated: 2024/11/16 16:45:18 by seolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*cp;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
		i++;
	cp = malloc (i + 1);
	if (cp == NULL)
		return (NULL);
	ft_memcpy(cp, s, i + 1);
	cp[i] = '\0';
	return (cp);
}
#include <stdio.h>
#include <unistd.h>
char	*ft_strjoin(char const *s1, char const *s2, size_t len)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = len;
	join = (char *)malloc(i + j + 1);
	if (join == NULL)
		return (NULL);
	ft_memcpy(join, s1, i);
	ft_memcpy(join + i, s2, j);
	join[i + j] = '\0';
	// write(1, "test\n", 5);
	// write(1, join, i);
	// write(1, join + i, j);
	// write(1, "test end\n", 9);
	return (join);
}
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s = (const unsigned char *)src;
	unsigned char		*d;

	d = (unsigned char *)dest;
	if (n == 0 || d == s)
		return (dest);
	if (d < s)
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		s += n;
		d += n;
		while (n--)
			*(--d) = *(--s);
	}
	return (dest);
}
char	*ft_strchr(const char *str, int c)
{
	while (*str != 0)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}
void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	if (!dest && !src && num > 0)
		return (NULL);
	if (!dest || !src)
		return (dest);
	while (i < num)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}