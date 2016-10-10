/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 04:11:31 by jpirsch           #+#    #+#             */
/*   Updated: 2014/11/11 10:57:09 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	i = 0;
	str = ft_strnew(sizeof(s));
	if (!s)
		return ;
	if (!f)
		return ;
	while (*s)
	{
		*str = f(i, *(char*)s);
		s++;
		str++;
		i++;
	}
	return (str - i);
}
