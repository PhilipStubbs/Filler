#include "filler.h"
#include <stdio.h>
	
m_line	*malloctime(m_line *node)
{
	node = (m_line*)malloc(sizeof(m_line));
	// node->grid = (g_line*)malloc(sizeof(g_line));
	// node->token = (g_line*)malloc(sizeof(g_line));
	// node->token->mdhold = (char**)malloc(sizeof(char*));
	node->heatmapcreat = 0;
	// node->grid->sizex = 0;
	// node->grid->sizey = 0;
	node->playable = 1;

	return (node);
}

g_line	*mallocgline()
{
	g_line *ret;

	ret = (g_line*)malloc(sizeof(g_line));
	ret->mdhold = (char**)malloc(sizeof(char*) * 5);;
	ret->sizex = 0;
	ret->sizey = 0;
	return (ret);
}


// void	printnode(char **str)
// {
// 	int i;

// 	i = 0;
// 	while(i < )
// 		ft_putendl_fd(str[i++], 2);
// }

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
	
void	printtokenhold(m_line *node)
{
	int i;
	int	l;

	i = 0;
	l = 0;
	ft_putchar_fd('[', 2);
	while(l < node->token->sizey)
	{
		i = 0;
		while(i < node->token->sizex)
		{
			ft_putchar_fd(node->token->mdhold[l][i], 2);
			i++;
		}
		ft_putchar_fd('\n', 2);
		l++;
	}
	ft_putchar_fd(']', 2);
}

int	main()
{
	m_line *node;
	int fd;

	// fd = open("output01.txt", O_RDONLY);
	fd = 0;
	node = NULL;
	node = malloctime(node);
	node->grid = mallocgline();
	node->token = mallocgline();
	findplayer(node, fd);
	findgrid(node, fd);
	findtoken(node, fd);
	// getinfo(node,fd);

	// printnode(node->token->mdhold);

	while(node->playable)
	{
		
		swallow(node);
		
		// ft_putendl_fd("swallow", 2);
		// printtokenhold(node);
		// ft_putendl_fd("BEFORE tokenplacement", 2);

		tokenplacement(node);

		// ft_putendl_fd("tokenplacement", 2);

		if (node->playable == 0)
		{
			ft_putendl_fd("EXIT", 2);
			return (0);
		}
		getinfo(node,fd);
		// updategrid(node, fd);
		// ft_putendl_fd("updategrid grid", 2);
		// findtoken(node, fd);
		// ft_putendl_fd("findtoken", 2);
		

	
	}
	return(0);
}
