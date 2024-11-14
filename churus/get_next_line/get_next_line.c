/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolee <seolee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:09:47 by seolee            #+#    #+#             */
/*   Updated: 2024/11/14 17:51:04 by seolee           ###   ########.fr       */
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

	stline = ft_strdup("");
	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	newline = ft_strchr(buffer, '\n');
	int i = 0;
	while (1)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte <= 0)
		{
			if (byte < 0)
				return (NULL);
			buffer[byte] ='\0';
			break;
		}
		newline = ft_strchr(buffer, '\n');
		if (newline)
		{
			stline = ft_strjoin(stline, buffer, byte);
			*buffer = 0;
		}
	}
	stline = ft_strjoin(stline, buffer, (newline - buffer)); //strjoin 수정해야함 첫개행만나는 길이만큼 합치게 수정해야함
	ptrmove(buffer, newline);
	return (stline);
}

void ptrmove(char *buffer, char *newline)
{
	ft_memmove(buffer, newline + 1, BUFFER_SIZE - (newline - buffer +1));
	buffer[BUFFER_SIZE - (newline - buffer + 1)] = '\0';
}

int main(int argc, char **argv)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
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