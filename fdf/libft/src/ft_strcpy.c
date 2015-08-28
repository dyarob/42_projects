/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:12:36 by avannest          #+#    #+#             */
/*   Updated: 2013/12/02 19:57:17 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char					*ft_strcpy(char *s1, const char *s2)
{
	int					i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		++ i;
	}
	s1[i] = s2[i];
	return (s1);
}

