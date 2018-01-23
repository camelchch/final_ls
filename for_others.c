/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_others.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:55:37 by saxiao            #+#    #+#             */
/*   Updated: 2018/01/23 15:58:17 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include "ft_ls.h"

static	void	init_owngp(t_dir *list, t_max *max)
{
	t_dir	*cp;

	cp = list;
	while (list)
	{
		if (getpwuid(list->buf.st_uid))
			ft_strcpy((list->long_f).owner, (getpwuid(list->buf.st_uid)->pw_name));
		else
			ft_strcpy((list->long_f).owner, ft_itoa(list->buf.st_uid));
		list = list->next;
	}
}
