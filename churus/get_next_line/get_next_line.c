/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolee <seolee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:09:47 by seolee            #+#    #+#             */
/*   Updated: 2024/11/16 18:44:05 by seolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void ptrmove(char *buffer, char *newline);

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	ssize_t	byte;
	char *newline;
	char *stline;
	char *temp;
	
	stline = ft_strdup("");
	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	newline = ft_strchr(buffer, '\n');
	while (!newline)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte < 0)
		{
			free (stline);
			return(NULL);
		}
		if (byte == 0)
		{
			if (stline[0] == '\0')
			{
				free(stline);
				return (NULL);
			}
			return(stline);
		}
		newline = ft_strchr(buffer, '\n');
		if (!newline)
		{
			buffer[byte] = '\0';
			stline = ft_strjoin(stline, buffer, byte); 
		}
		//printf("testtest: %s", stline);
		//printf("\n");
	}
	buffer[byte] = '\0';
	temp = stline;
	stline = ft_strjoin(stline, buffer, (newline - buffer) + 1);
	ptrmove(buffer, newline);
	free(temp);
	return (stline);
}

void ptrmove(char *buffer, char *newline)
{
	ssize_t mv;

	mv = BUFFER_SIZE - ((newline - buffer ) + 1);
	ft_memmove(buffer, newline + 1, mv);
	buffer[mv] = '\0';
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


// 1. \n을 포함한 한 문장을 return 해야함
// 2. 출력은 main에서 알아서 처리해줌
