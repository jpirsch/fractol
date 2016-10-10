/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 03:55:25 by jpirsch           #+#    #+#             */
/*   Updated: 2014/11/11 10:56:37 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	size_t	i;
	char	*str;

	i = 0;
	if (!(str = ft_strnew(sizeof(s))) || !s || !f)
		return ;
	while (*s)
	{
		*str = f(*(char*)s);
		s++;
		str++;
		i++;
	}
	return (str - i);
}
