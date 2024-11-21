/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolee <seolee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:09:47 by seolee            #+#    #+#             */
/*   Updated: 2024/11/21 16:45:04 by seolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ptrmove(char *buffer, char *newline, ssize_t byte)
{
	byte = byte - ((newline - buffer) + 1);
	if (byte > 0)
		ft_memmove(buffer, newline + 1, byte);
	buffer[byte] = 0;
}

char	*update_stline(char *stline, char *buffer, ssize_t byte)
{
	char	*temp;

	temp = stline;
	stline = ft_strjoin(stline, buffer, byte);
	if (!stline)
	{
		free (temp);
		return (NULL);
	}
	free (temp);
	return (stline);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	static ssize_t	byte;
	char			*newline;
	char			*stline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stline = ft_strdup("");
	newline = ft_strchr(buffer, '\n');
	while (!newline)
	{	
		if (!newline)
        		stline = update_stline(stline, buffer, byte);
    		byte = read(fd, buffer, BUFFER_SIZE);
    		if (byte < 0 || (byte == 0 && (!stline || stline[0] == '\0')))
        		return (free(stline), NULL);
    		buffer[byte] = '\0';
    		if (byte == 0)
        		return (stline);
		newline = ft_strchr(buffer, '\n');
	}
	stline = update_stline(stline, buffer, (newline - buffer) + 1);
	return (ptrmove(buffer, newline, byte), stline);
}	

int main(int argc, char **argv)
{
	int fd;
	char *line;

	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		printf("open error\n");
		exit(1);
	}
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);

	}
}
