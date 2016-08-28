/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 19:06:25 by rpereira          #+#    #+#             */
/*   Updated: 2015/01/18 12:02:20 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrlen(const wchar_t *s)
{
	const wchar_t *p;

	p = s;
	while (*p)
		p = p + 1;
	return (p - s);
}

size_t	ft_wcrtomb(char *s, wchar_t wc)
{
	if (wc <= 0x7FF)
	{
		s[0] = 0xC0L;
		return (2);
	}
	else if (wc <= 0xFFFFL)
	{
		s[0] = 0xE0;
		return (3);
	}
	else if (wc <= 0x1FFFFFL)
	{
		s[0] = 0xF0;
		return (4);
	}
	return (0);
}

int		ft_putwc(wchar_t wc)
{
	char	buffer[4];
	int		i;
	int		octet_count;

	if (wc <= 0x7F)
	{
		write(1, &wc, 1);
		return (1);
	}
	if ((octet_count = ft_wcrtomb(buffer, wc)) == 0)
		return (0);
	i = octet_count - 1;
	while (i--)
	{
		buffer[i + 1] = 0x80 | (wc & 0x3F);
		wc = wc >> 6;
	}
	buffer[0] = buffer[0] | wc;
	write(1, buffer, octet_count);
	return (octet_count - 1);
}

int		ft_putws(wchar_t *ws)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (ws[i])
	{
		size += ft_putwc(ws[i]);
		i++;
	}
	return (size);
}
