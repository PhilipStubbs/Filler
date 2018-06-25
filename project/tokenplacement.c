
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
	ft_putendl_fd(ret, 1);
}

int	tokenplacement(m_line *node)
{
	int	x;
	int	y;
	int	tempx;
	int	tempy;
	int	score;
	int	tempscore;

	y = 0;
	score = 0;
	tempy = 0;
	tempx = 0;
	while (y < node->grid->sizey)
	{
		x = 0;
		while (x < node->grid->sizex)
		{
			if(validpos(node, y, x) == 1)
			{
				tempscore = scorecount(node, x, y);
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
	placementoutput(tempy, tempx);
	return (1);
}