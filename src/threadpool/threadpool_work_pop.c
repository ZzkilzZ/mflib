/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadpool_work_pop.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 11:48:18 by mfischer          #+#    #+#             */
/*   Updated: 2019/06/13 13:43:27 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfthreadpool.h"

t_thread_pool_work		work_pool_pop(t_thread_pool *pool)
{
	t_thread_pool_work	work;
	work.f = NULL;
	pthread_mutex_lock(&pool->mtx_work);
	if (pool->work_pool.top != -1)
	{
		work = pool->work_pool.data[pool->work_pool.top];
		pool->work_pool.top--;
	}
	else
	{
		pthread_mutex_lock(&pool->mtx_wait);
		pthread_cond_signal(&pool->cnd_wait);
		pthread_mutex_unlock(&pool->mtx_wait);
	}
	pthread_mutex_unlock(&pool->mtx_work);
	return (work);
}