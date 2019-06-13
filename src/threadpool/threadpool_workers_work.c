/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadpool_workers_work.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 00:29:34 by mfischer          #+#    #+#             */
/*   Updated: 2019/06/13 12:12:43 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfthreadpool.h"

void	*thread_pool_workers_work(void *param)
{
	t_thread_pool		*pool;
	t_thread_pool_work	work;

	pool = param;
	while (pool->running)
	{
		pthread_mutex_lock(&pool->mtx_active);
		pthread_cond_wait(&pool->cnd_active, &pool->mtx_active);
		pthread_mutex_unlock(&pool->mtx_active);
		pthread_mutex_lock(&pool->mtx_work);
		work = work_pool_pop(pool);
		pthread_mutex_unlock(&pool->mtx_work);
		if (work.f)
			work.f(work.param);
	}
	return (NULL);
}
