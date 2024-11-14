/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:48:21 by seolee            #+#    #+#             */
/*   Updated: 2024/07/18 21:25:12 by seolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define TRUE 0
# define FALSE 1
# define SUCCESS 0
# define EVEN(NBR) (NBR % 2 == 0)
# define EVEN_MSG = "I have an even number of arguments.\n"
# define ODD_MSG = "I have an odd number of arguments.\n"

typedef int	t_bool;

#endif
