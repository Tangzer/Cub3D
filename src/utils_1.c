/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Verdoodt <Verdoodt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:19:14 by devoma            #+#    #+#             */
/*   Updated: 2023/05/21 20:01:29 by Verdoodt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_strlen(char	*s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*ptr;
	int		i;
	int		size;
	int		mlen;

	size = ft_strlen(s);
	if (len == 0 || start > size)
		mlen = 0;
	else if (size - start + 1 > len)
		mlen = len;
	else
		mlen = size - start;
	ptr = (char *)malloc((mlen + 1) * sizeof(char));
	protect_malloc(ptr);
	i = 0;
	while (s[i] && len && size > start)
	{
		ptr[i] = s[start];
		i++;
		start++;
		len--;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_strcmp(char	*s1, char	*s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strchr(char	*str, int c)
{
	int		i;
	char	sym;

	i = 0;
	sym = c;
	while (str[i] && str[i] != sym)
		i++;
	if (str[i] == sym)
		return ((char *)(str + i));
	return (NULL);
}

int	ft_atoi(const char	*str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (sign * num);
}
