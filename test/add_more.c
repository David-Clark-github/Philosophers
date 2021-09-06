/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_more.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:31:09 by dclark            #+#    #+#             */
/*   Updated: 2021/09/06 13:59:08 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	*ft_1(void *arg)
{
	int *a = arg;
	printf("%d", *a);
	printf("Hey!\n");
	return NULL;
}

int main(void) {
	pthread_t pth1;
	pthread_t pth2;

	int a = 1;
	int b = 2;

	pthread_create(&pth1, NULL, ft_1, &a);
	pthread_create(&pth2, NULL, ft_1, &b);
	pthread_join(pth1, NULL);
	pthread_join(pth2, NULL);
}
