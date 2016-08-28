/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <rpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:01:04 by rpereira          #+#    #+#             */
/*   Updated: 2014/12/30 12:37:53 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	int		len;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if ((ret = ft_strnew(len - i + 1)) == NULL)
		return (NULL);
	while (len > 0 && (s[len] == '\n' || s[len] == ' ' || s[len] == '\t'))
		len--;
	len = len - i + 1;
	len < 0 ? len = 0 : 0;
	return (ft_memcpy(ret, s + i, len));
}
