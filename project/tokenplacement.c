
#include "filler.h"

int	scorecount(m_line *node, int y, int x)
{
	int	i;
	int	l;
	int score;

	score = 0;
	l = 0;
	while (l < node->token->sizey)
	{
		i = 0;
		while (i < node->token->sizex)
		{
			if (node->token->mdhold[l][i] == '*')
				score += node->heatmap[y+l][x+i];
			i++;
		}
		l++;
	}
	return (score);
}

void placementoutput(int y, int x)
{
	char *ret;
	
	ret = ft_strjoin(ft_itoa(y), " ");
	ft_strcat(ret, ft_itoa(x));
	
	// ft_putendl_fd(ret, 2);
	ft_putendl_fd(ret, 1);
	free(ret);

}

int	*findfirststar(m_line *node)
{
	int	x;
	int	y;
	int	*ret;

	y = 0;

	ret = (int*)ft_memalloc(sizeof(int) *2);
	ret[1] = node->token->sizey;
	ret[0] = node->token->sizex;
	while (y < node->token->sizey)
	{
		x = 0;
		while (x < node->token->sizex)
		{
			if (node->token->mdhold[y][x] == '*')
			{	
				if (ret[0] > x)
					ret[0] = x;
				if (ret[1] > y)
					ret[1] = y;
				break;
			}
			x++;
		}
		y++;
	}
	if (y == node->token->sizey)
		ret[1] = 0;
	
	return (ret);
}

int	tokenplacement(m_line *node)
{
	int	x;
	int	y;
	int	tempx;
	int	tempy;
	int	score;
	int	tempscore;
	int	*xyneg;

	
	xyneg = findfirststar(node);
	y = 0 - xyneg[1];
	score = 0;
	tempy = 0;
	tempx = 0;
	tempscore = 0;
	while (y < node->grid->sizey)
	{
		x = 0 - xyneg[0];
		while (x < node->grid->sizex)
		{
			if(validpos(node, y, x, xyneg) == 1)
			{
				tempscore = scorecount(node, y, x);
				if (tempscore > score)
				{
					score = tempscore;
					tempx = x;
					tempy = y;
				}
			}
			x++;
		}
		y++;
	}
	if (tempscore > 0)
	{
		node->playable = 1;
		placementoutput(tempy, tempx);
	}
	else if (tempscore == 0)
	{
		node->playable = 0;
		placementoutput(0, 0);

	}
	return (1);
}

// int	tokenplacement(m_line *node)
// {
// 	int	x;
// 	int	y;
// 	int	tempx;
// 	int	tempy;
// 	int	score;
// 	int	tempscore;

// 	y = 0;
// 	score = 0;
// 	tempy = 0;
// 	tempx = 0;
// 	tempscore = 0;
// 	while (y < node->grid->sizey)
// 	{
// 		x = 0;
// 		while (x < node->grid->sizex)
// 		{
// 			if(validpos(node, y, x) == 1)
// 			{
// 				// ft_putendl_fd("Validpos found", 2);
// 				tempscore = scorecount(node, y, x);
// 				if (tempscore > score)
// 				{
// 					score = tempscore;
// 					tempx = x;
// 					tempy = y;
// 				}
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	if (tempscore > 0)
// 	{
// 		node->playable = 1;
// 		placementoutput(tempy, tempx);
// 	}
// 	else if (tempscore == 0)
// 	{
// 		node->playable = 0;
// 		placementoutput(0, 0);

// 	}
// 	return (1);
// }