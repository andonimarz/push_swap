/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:21:43 by amarzana          #+#    #+#             */
/*   Updated: 2022/07/15 12:33:45 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	result;
	size_t	i;

	i = 0;
	result = 0;
	while (src[result])
		result++;
	if (dst == NULL || src == NULL)
		return (0);
	if (dstsize != 0)
	{
		while (i < (dstsize - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
		i++;
	if (len <= 0 || start >= ft_strlen(s))
	{
		str = (char *)malloc(1);
		*str = '\0';
		return (str);
	}
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s[start], i + 1);
	return (str);
}

static int	ft_coincidences(char const *s, char c)
{
	int	coin;
	int	i;

	i = 0;
	coin = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			coin++;
		while (s[i] != c && s[i])
		i++;
	}
	return (coin);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	int		i;
	int		start;
	int		coin;
	char	**str;

	coin = 0;
	i = -1;
	start = -1;
	len = ft_strlen(s);
	str = (char **) malloc(sizeof(char *) * (ft_coincidences(s, c) + 1));
	if (str == NULL || sizeof(str) == 0)
		return (NULL);
	while (++i <= len)
	{
		if (s[i] != c && start < 0)
			start = i;
		else if (start >= 0 && (s[i] == c || i == len))
		{
			str[coin++] = ft_substr(s, start, i - start);
			start = -1;
		}
	}
	str[coin] = NULL;
	return (str);
}
