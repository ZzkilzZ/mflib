/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfveclist.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 22:39:51 by mfischer          #+#    #+#             */
/*   Updated: 2019/09/22 13:16:45 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MFVECLIST_H
# define MFVECLIST_H

# include <stdlib.h>
# include "boolean.h"
# include "mfmemory.h"

# define VECTOR_LIST_INIT_CAPACITY	4

typedef struct	s_vector_list
{
	size_t		capacity;
	size_t		size;
	size_t		item_size;
	char		*list;
}				t_vector_list;

t_bool			vector_list_init(t_vector_list *vector, size_t item_size);
t_bool			vector_list_push(t_vector_list *vector, void *data);
void			vector_list_delete(t_vector_list *vector, size_t index);
void			vector_list_destroy(t_vector_list *vector);
void			*vector_list_at(t_vector_list vector, size_t index);

#endif
