/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:58:19 by abourdon          #+#    #+#             */
/*   Updated: 2022/11/23 12:45:51 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int	start(char const *s1, char const *set)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (set[0] == '\0')
		return (0);
	while (set[j] != '\0')
	{
		while (set[j] != s1[i] && set[j] != '\0')
			j++;
		if (set[j] != '\0')
			j = 0;
		i++;
	}
	if (len(s1) == i - 1)
		return (0);
	return (i - 1);
}

static int	end(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = len(s1) - 1;
	j = 0;
	if (set[0] == '\0')
		return (0);
	while (set[j] != '\0')
	{
		while (s1[i] != set[j] && set[j] != '\0')
			j++;
		if (set[j] != '\0')
			j = 0;
		i--;
	}
	if (len(s1) == (len(s1) - 1) - i - 1)
		return (len(s1));
	return ((len(s1) - 1) - i - 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int				i;
	int				j;
	int				lenmalloc;
	unsigned int	compt;
	char			*str;

	if (!s1)
		return (NULL);
	i = start(s1, set);
	j = 0;
	compt = 0;
	lenmalloc = (len(s1) - (start(s1, set) + end(s1, set)));
	str = malloc((lenmalloc + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	while (compt < len(s1) - (start(s1, set) + end(s1, set)))
	{
		str[j] = s1[i];
		i++;
		j++;
		compt++;
	}
	str[j] = '\0';
	return (str);
}
