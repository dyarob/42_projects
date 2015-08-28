/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 17:50:13 by avannest          #+#    #+#             */
/*   Updated: 2013/12/01 19:17:13 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Why does this function creates a string even when size is 0? And why add an
** extra '\0' in addition to the size given in the parameters ?
** 	One may think a string with no characters is stupid and size == 0 should
** only result in a NULL return.
** 	However, there are three reasons not to do it that way:
** - NULL is the conventional return value for mem allocation failure in the 
**   whole libc.
** - Just because we don't think right now of a possible use of a string with
**   lenght 0 doesn't mean there isn't. If the user wants to create an empty
**   string, so be it.
** - Getting rid of the burden of writing size + 1 everywhere in our main code
**   and get everything dirty and hardly readable. After all this function
**   exists precisely in order to free one's mind about string creation
**   subtilities...
*/
char					*ft_strnew(size_t size)
{
	char				*result;

	result = (char *)malloc(size + 1);
	if (!result)
		return (NULL);
	ft_bzero(result, size + 1);
	return (result);
}

