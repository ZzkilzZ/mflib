/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_list_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 00:40:12 by mfischer          #+#    #+#             */
/*   Updated: 2019/09/22 13:21:09 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfveclist.h"

void		*vector_list_at(t_vector_list vector, size_t index)
{
	if (index < vector.size)
		return (vector.list + (index * vector.item_size));
	return (NULL);
}
