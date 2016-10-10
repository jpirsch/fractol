/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:11:39 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/09 03:09:40 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src <= dst)
		while (len--)
			((unsigned char*)dst)[len] = ((unsigned char*)src)[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
