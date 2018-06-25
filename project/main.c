#include "filler.h"
#include <stdio.h>
	
m_line	*malloctime(m_line *node)
{
	node = (m_line*)malloc(sizeof(m_line));
	node->grid = (g_line*)malloc(sizeof(g_line));
	node->token = (g_line*)malloc(sizeof(g_line));
	node->token->hold = (char*)malloc(sizeof(char));
	node->heatmapcreat = 0;
	node->grid->sizex = 0;
	node->grid->sizey = 0;


	return (node);
}

void	printnode(char **str)
{
	int i;

	i = 0;
	while(str[i])
		ft_putendl_fd(str[i++], 2);
}

void	printnodenbr(m_line *node)
{
	int i;
	int	l;

	i = 0;
	l = 0;
	while(l < node->grid->sizey)
	{
		i = 0;
		while(i < node->grid->sizex)
		{
			ft_putnbr_fd(node->heatmap[l][i], 2);
			i++;
		}
		ft_putchar_fd('\n', 2);
		l++;
	}
}
	

int	main()
{
	m_line *node;
	int fd;

	fd = open("output02.txt", O_RDONLY);
	// fd = 0;
	node = NULL;
	node = malloctime(node);
	findplayer(node, fd);
	findgrid(node, fd);
	findtoken(node, fd);
	printnode(node->token->mdhold);

	swallow(node);
	printnodenbr(node);
	// ft_putendl_fd("29 30", 1);

	// updategrid(node, fd);
	// printnode(node->grid->mdhold);
	// findtoken(node, fd);
	ft_putchar_fd('[', 2) ;

	// findtoken(node, fd);

	ft_putchar_fd(']', 2);

	return(0);
}
