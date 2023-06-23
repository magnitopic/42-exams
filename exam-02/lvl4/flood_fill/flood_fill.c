#include "flood_fill.h"

void	fill(char **tab, t_point size, t_point point, char value)
{
	if (point.x >= size.x || point.y >= size.y || point.y < 0 || point.x < 0 || tab[point.y][point.x] != value)
		return ;
	
	tab[point.y][point.x] = 'F';

	fill(tab, size, (t_point){point.x + 1, point.y}, value);
	fill(tab, size, (t_point){point.x - 1, point.y}, value);
	fill(tab, size, (t_point){point.x, point.y + 1}, value);
	fill(tab, size, (t_point){point.x, point.y - 1}, value);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}
