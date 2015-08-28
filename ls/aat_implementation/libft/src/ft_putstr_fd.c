/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:31:25 by avannest          #+#    #+#             */
/*   Updated: 2013/12/15 22:00:44 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void					ft_putstr_fd(char const *s, int fd)
{
	int					len;

	len = ft_strlen(s);
	write(fd, s, len);
}

