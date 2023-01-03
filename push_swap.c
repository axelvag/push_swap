/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:58:01 by avaganay          #+#    #+#             */
/*   Updated: 2022/12/26 16:31:34 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> 

/////////////////////////////////////////////////////////////////////ATOI

static int	limit(long long n, const char str, int sign)
{
	long long	reslong;

	reslong = ((n * 10) + (str - '0')) * sign;
	if (reslong < -2147483648)
		return (0);
	if (reslong > 2147483647)
		return (-1);
	return (1);
}

void	init0(int *i, int *res, int *sign)
{
	*i = 0;
	*res = 0;
	*sign = 1;
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;
	int	limit_test;

	init0(&i, &res, &sign);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while ((str[i] == '+' || str[i] == '-')
		&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		limit_test = limit(res, *str, sign);
		if (limit_test == 0 || limit_test == -1)
			return (limit_test);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

/////////////////////////////////////////////////////////////////////SPLIT

int	ft_nbtab(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			|| (i == 0 && s[i] != c))
		{
			count++;
		}
		i++;
	}
	return (count);
}

char	*ft_filltab(char const *s, char c, int *index)
{
	int		len;
	char	*res;
	int		i;

	i = 0;
	len = 0;
	while (s[*index] == c)
		(*index)++;
	while (s[*index + len] != c && s[*index + len])
		len++;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i++] = s[*index];
		*index = *index + 1;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		nbtab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	nbtab = ft_nbtab(s, c);
	res = malloc((nbtab + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	j = 0;
	while (i < nbtab)
	{
		res[i] = ft_filltab(s, c, &j);
		i++;
	}
	res[i] = 0;
	return (res);
}

/////////////////////////////////////////////////////////////////////////////PILE
t_pile	*ft_pilelast(t_pile *pile)
{
	while (pile)
	{
		if (!pile->next)
			return (pile);
		pile = pile->next;
	}
	return (pile);
}

t_pile	*ft_pilenew(int content)
{
	t_pile	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
    node->prev = NULL;
	return (node);
}

void	ft_pileadd_back(t_pile **pile, t_pile *new)
{
	t_pile	*back;

	if (!(*pile))
	{
		*pile = new;
		return ;
	}
	back = ft_pilelast(*pile);
	back->next = new;
    new->prev = back;
}

void	ft_pileadd_front(t_pile **pile, t_pile *new)
{
	new->next = *pile;
	*pile = new;
}

int	ft_pilesize(t_pile *pile)
{
	int	size;

	size = 0;
	while (pile)
	{
		pile = pile->next;
		size++;
	}
	return (size);
}

int	ft_pileissort(t_pile *pile)
{
	t_pile	*head;

	head = pile;
	while (head && head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_pilefree(t_pile *pile)
{
	t_pile	*head;
	t_pile	*tmp;

	head = pile;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(pile);
}
//////////////////////////////////////////////////////////////////////////////////////////////////

void ft_sa(t_pile *pile, char c)
{
	int temp;
    
    if (pile->next != NULL)
    {
        temp = pile->content;
        pile->content = pile->next->content;
        pile->next->content = temp;
    }
	if (c == 'a')
		printf("%s\n","sa");
	else
		printf("%s\n","sb"); 
}

void ft_ss(t_pile *pilea, t_pile *pileb)
{
	ft_sa(pilea, 'a');
	ft_sa(pileb, 'b');
}

void	ft_pa(t_pile **pilea, t_pile **pileb, char c)
{
	t_pile *tmp;
	t_pile *tmpa;
	
	tmp = *pileb;
	*pileb = tmp->next;
	tmpa = *pilea;
	*pilea = tmp;
	tmp->next = tmpa;
	if (c == 'a')
		printf("%s\n","pa");
	else
		printf("%s\n","pb"); 
}

void ft_ra(t_pile *pile, char c)
{
	int temp;
	
	if (pile->next == NULL)
		return ;
	if (pile->next->next == NULL)
	{
		temp = pile->content;
		pile->content = pile->next->content;
		pile->next->content = temp;
		return;
	}
	temp = pile->content;
	pile = pile->next;
	while (pile->next)
	{
		pile->prev->content = pile->content;
		pile = pile->next;
	}
	pile->prev->content = pile->content;
	pile->content = temp;
	if (c == 'a')
		printf("%s\n","ra");
	else
		printf("%s\n","rb"); 
}

void ft_rr(t_pile *pilea, t_pile *pileb)
{
	ft_ra(pilea, 'a');
	ft_ra(pileb, 'b');
}

t_pile    *ft_rra(t_pile *pile, char c)
{
    t_pile	*new;
    t_pile	*new_list;
	int temp;

    new_list = 0;
	if (pile->next == NULL)
		return (pile);
	if (pile->next->next == NULL)
	{
		temp = pile->content;
		pile->content = pile->next->content;
		pile->next->content = temp;
		return (pile);
	}
    while (pile->next)
    {
        new = ft_pilenew(pile->content);
        ft_pileadd_back(&new_list, new);
        pile = pile->next;
    }
    new = ft_pilenew(pile->content);
    ft_pileadd_front(&new_list, new);
	if (c == 'a')
		printf("%s\n","rra");
	else
		printf("%s\n","rrb"); 
    return (new_list);
}

t_pile *ft_rrr(t_pile *pilea, t_pile *pileb)
{
	pilea = ft_rra(pilea, 'a');
	pileb = ft_rra(pileb, 'b');
	return (pilea);
}

////////////////////////////////////////////////////////////////////INDEX

/////////fonct return a pile qui a des index
/////appel une fonction qui return un tab** de chiffre [0,n]
////appel une autre fonct qui convert en binaire les index puis les place dans la pile

int ft_checkdouble(int *tab, t_pile *pile)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	size = ft_pilesize(pile);
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab [j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int ft_checkchar(char **s, int argc)                  ////////////////////////////////PROBLEME
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < argc - 1)
	{
		// printf("%s\n",s[i]);
		while (s[i][j])
		{
			if (!((s[i][j] >= '0' && s[i][j] <= '9') || s[i][j] == '-' || s[i][j] == '+'))
			{
				// if (s[i][j] != '-' || (s[i][j] == '-' && (s[i][j + 1] <= '0' || s[i][j + 1] >= '9')))
				// {	
				printf("%c\n", s[i][j]);
				write(2,"Error char\n",11);
				return (1);
				// }
			}
			j++;
		}
		i++;
	}
	return (0);
}

int *ft_pileclonetab(t_pile *pile)
{
	int *tab;
	int size;
	int i;

	i = 0;
	size = ft_pilesize(pile);
	tab = malloc(sizeof(int) * size);
	while(i < size)
	{
		tab[i] = pile->content;
		pile = pile->next;
		i++;
	}
	return (tab);
}

void ft_sorttab(int *tab, int taille)
{
	int i;
	int j;
	int content;

	i = 1;
	j = 0;
	while (i < taille)
	{
		content = tab[i];
		j = i - 1;
		while (j >= 0 && content < tab[j])
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = content;
		i++;
	}
}

t_pile *ft_tabtopile(t_pile *pile, int *tab, int size)
{
	int index;
	int value;

	index = 0;
	while (index < size)
	{
		value = tab[index];
		while (pile)
		{
			if (pile->content == value)
			{
				pile->content = index;
				while (pile->prev != NULL)
				{
					pile = pile->prev;
				}
				break;
			}
			pile = pile->next;
		}
		index++;
	}
	return (pile);
}

int ft_indexpile(t_pile *pile)
{
	int *tab;
	int size;

	size = ft_pilesize(pile);
	tab = ft_pileclonetab(pile);
	ft_sorttab(tab, size);
	if (ft_checkdouble(tab, pile))
		return (1);
	pile = ft_tabtopile(pile, tab, size);
	return (0);
}

//////////////////////////////////////////////////////////////////////INIT
t_pile *ft_fillpilesplit(char **argv)
{
	t_pile *pile;
	t_pile *node;
	char **tabsplit;
	int i;

	i = 0;
	tabsplit = ft_split(argv[1], ' ');
	pile = NULL;
	node = NULL;
	while (tabsplit[i])
	{
		//printf("%s\n",tabsplit[i]);
		node = ft_pilenew(ft_atoi(tabsplit[i]));
        ft_pileadd_back(&pile, node);
		i++;
	}
	return (pile);
}

t_pile *ft_fillpile(int argc, char **argv, t_pile *pile)
{
	t_pile *node;
	int i;

	i = 1;
	node = NULL;
	if (argc == 1)
	{
        write(2,"Error\n",6);
		return (NULL);
	}
	if (argc == 2)
	{
		pile = ft_fillpilesplit(argv);
		return (pile);
	}
	// if (ft_checkchar(argv , argc))               ////////////////////////////////PROBLEME
	// 	return (NULL);
    while (argc > i)
    {
        node = ft_pilenew(ft_atoi(argv[i]));
        ft_pileadd_back(&pile, node);
        i++;   
	}
	return (pile);
}

////////////////////////////////////////////////////////////////////////TRI

int	get_distance(t_pile *pile, int index)
{
	t_pile	*head;
	int		distance;

	distance = 0;
	head = pile;
	while (head)
	{
		if (head->content == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

int	get_min(t_pile *pile, int val)
{
	t_pile	*head;
	int		min;

	head = pile;
	min = head->content;
	while (head->next)
	{
		head = head->next;
		if ((head->content < min) && head->content != val)
			min = head->content;
	}
	return (min);
}

void	ft_sort3(t_pile *pilea)
{
	t_pile	*head;
	int		min;
	int		next_min;

	head = pilea;
	min = get_min(pilea, -1);
	next_min = get_min(pilea, min);
	if (ft_pileissort(pilea))
		return ;
	if (head->content == min && head->next->content != next_min)
	{
		ft_ra(pilea, 'a');
		ft_sa(pilea, 'a');
		ft_rra(pilea, 'a');
	}
	else if (head->content == next_min)
	{
		if (head->next->content == min)
			ft_sa(pilea, 'a');
		else
			ft_rra(pilea, 'a');
	}
	else
	{
		if (head->next->content == min)
			ft_ra(pilea, 'a');
		else
		{
			ft_sa(pilea, 'a');
			ft_rra(pilea, 'a');
		}
	}
}

void	ft_sort4(t_pile *pilea, t_pile *pileb)
{
	int	distance;

	if (ft_pileissort(pilea))
		return ;
	distance = get_distance(pilea, get_min(pilea, -1));
	if (distance == 1)
		ft_ra(pilea, 'a');
	else if (distance == 2)
	{
		ft_ra(pilea, 'a');
		ft_ra(pilea, 'a');
	}
	else if (distance == 3)
		ft_rra(pilea, 'a');
	if (ft_pileissort(pilea))
		return ;
	ft_pa(&pileb, &pilea, 'b');
	ft_sort3(pilea);
	ft_pa(&pilea, &pileb, 'a');
}

void	ft_sort5(t_pile *pilea, t_pile *pileb)
{
	int	distance;

	distance = get_distance(pilea, get_min(pilea, -1));
	if (distance == 1)
		ft_ra(pilea, 'a');
	else if (distance == 2)
	{
		ft_ra(pilea, 'a');
		ft_ra(pilea, 'a');
	}
	else if (distance == 3)
	{
		ft_rra(pilea, 'a');
		ft_rra(pilea, 'a');
	}
	else if (distance == 4)
		ft_rra(pilea, 'a');
	if (ft_pileissort(pilea))
		return ;
	ft_pa(&pileb, &pilea, 'b');
	ft_sort4(pilea, pileb);
	ft_pa(&pilea, &pileb, 'a');
}

void	ft_minialgosort(t_pile *pilea, t_pile *pileb)
{
	int	size;

	if (ft_pileissort(pilea) || ft_pilesize(pilea) == 0 || ft_pilesize(pilea) == 1)
		return ;
	size = ft_pilesize(pilea);
	if (size == 2)
		ft_sa(pilea, 'a');
	else if (size == 3)
		ft_sort3(pilea);
	else if (size == 4)
		ft_sort4(pilea, pileb);
	else if (size == 5)
		ft_sort5(pilea, pileb);
}

// void ft_bigalgosort(t_pile *pilea, t_pile *pileb)
// {
// 	int size;
// 	int max_num;
// 	int max_bits;
// 	int i;
// 	int j;
// 	int num;

// 	i = 0;
// 	j = 0;
// 	size = ft_pilesize(pilea);
// 	max_num = size - 1;
// 	max_bits = 0;
// 	while ((max_num >> max_bits) != 0)
// 		++max_bits;
// 	while (i < max_bits)
// 	{
// 		j = 0;
// 		while (j++ < size)
// 		{
// 			num = pilea->content;
// 			if (((num >> i)&1) == 1)
// 				ft_ra(pilea);
// 			else
// 				ft_pa(&pileb, &pilea, 'b');
// 		}
// 		i++;
// 	}
// 	while (pileb)
// 		ft_pa(&pilea, &pileb, 'a');
// }

static int	ft_getmax(t_pile *pile)
{
	t_pile	*head;
	int		max;
	int		max_bits;

	head = pile;
	max = head->content;
	max_bits = 0;
	while (head)
	{
		if (head->content > max)
			max = head->content;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	ft_bigalgosort(t_pile *pilea, t_pile *pileb)
{
	t_pile	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = pilea;
	size = ft_pilesize(head_a);
	max_bits = ft_getmax(pilea);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = pilea;
			if (((head_a->content >> i) & 1) == 1)
				ft_ra(pilea, 'a');
			else
				ft_pa(&pileb, &pilea, 'b');
		}
		while (ft_pilesize(pileb) != 0)
			ft_pa(&pilea, &pileb, 'a');
		i++;
	}
}

void	ft_algosort(t_pile *pilea, t_pile *pileb)
{
	if (ft_pilesize(pilea) <= 5)
	{
		ft_bigalgosort(pilea, pileb);
	}
	else
	{
		ft_bigalgosort(pilea, pileb);
	}
}

///////////////////////////////////////////////////////////////////////////PRINT

void    ft_printpile(t_pile *pile, char c)
{
    while (pile != NULL)
    {
        printf("%d\n", pile->content);
        pile = pile->next;
    }
    printf("%s\n", "------");
    printf("%c\n", c);
	printf("\n");
}

int	ft_printtab(t_pile *pile, int *tab)
{
	int size;
	
	size = ft_pilesize(pile);
	for(int k=0;k < size;k++)
	{
		printf("%d\n",tab[k]);
	}
	ft_sorttab(tab, size);
	printf("%s\n","--------");
	for(int k=0;k < size;k++)
	{
		printf("%d\n",tab[k]);
	}
	return (0);
}

////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
    t_pile *pile;     //pile a
	t_pile *pileb;
	//int *tab;
    
	pile = NULL;
	pileb = NULL;
	pile = ft_fillpile(argc, argv, pile);
	if (!pile)
		return (0);
	// pileb = ft_pilenew(5);          //pileb
	// pileb->next = ft_pilenew(6);
	
	// ft_sa(pile, 'a');
	// ft_sa(pileb, 'b');
	// ft_ss(pile, pileb);
	// ft_pa(&pile, &pileb, 'a');
	// ft_pa(&pileb, &pile, 'b');
	// ft_ra(pile, 'a');
	// ft_ra(pileb, 'b');
	// ft_rr(pile, pileb);
	// pile = ft_rra(pile, 'a');
	// pileb = ft_rra(pileb, 'b');
	// pile = ft_rrr(pile, pileb);
	// ft_printpile(pile);
	// ft_printpile(pileb);
	
	/*tab = ft_pileclonetab(pile);
    if (ft_printtab(pile,tab))
		return (0);*/
	if(ft_indexpile(pile))  ////////////////////////////////PROBLEME AVEC LES - et + ft_checkchar
	{
		write(2,"Error\n",6);
		return (0);
	}
	ft_printpile(pile, 'a');
	ft_printpile(pileb, 'b');
	if (ft_pileissort(pile))
	{
		// ft_pilefree(pile);
		// ft_pilefree(pileb);
		free(pile);
		free(pileb);
		return (0);
	}
	ft_algosort(pile, pileb);
	ft_printpile(pile, 'a');
	ft_printpile(pileb, 'b');
	free(pile);
	free(pileb);
    return (0);
}