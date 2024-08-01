/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:25:46 by minkim3           #+#    #+#             */
/*   Updated: 2022/12/09 19:23:59 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dummy_src;
	unsigned char	*dummy_dst;

	dummy_src = (unsigned char *)src;
	dummy_dst = (unsigned char *)dst;
	if (dummy_dst == NULL && dummy_src == NULL)
		return (NULL);
	if (len == 0)
		return (dst);
	if (dummy_src > dummy_dst)
		return (ft_memcpy(dummy_dst, dummy_src, len));
	while (len--)
		*(dummy_dst + len) = *(dummy_src + len);
	return (dst);
}