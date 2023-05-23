#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_paper
{
	int w, h;
	char c;
} t_paper;

typedef struct s_rec
{
	float x, y, w, h;
	char r, c;
} t_rec;

t_paper paper;
t_rec *rec;
char **map;
int rec_num;

void putstr(char *str)
{
	for(int i=0; str[i]; i++)
		write(1, &str[i], 1);
}

void get_map()
{
	map = (char **)calloc(paper.h, sizeof(char *));
	for(int i=0; i<paper.h; i++)
	{
		map[i] = (char *)calloc(paper.w, sizeof(char));
		for(int j=0; j<paper.w; j++)
			map[i][j] = paper.c;
	}
}

void print_map()
{
	for(int i=0; i<paper.h; i++)
	{
		for(int j=0; j<paper.w; j++)
			write(1, &map[i][j], 1);
		write(1, "\n", 1);
	}
}

int init(char *file)
{
	rec = (t_rec*)calloc(10000, sizeof(t_rec));
	FILE *fp = fopen(file, "r");
	fscanf(fp, "%d %d %c\n", &paper.w, &paper.h, &paper.c);

	int i=0;
	while(fscanf(fp, "%c %f %f %f %f %c\n", &rec[i].r, &rec[i].x, &rec[i].y, &rec[i].w, &rec[i].h, &rec[i].c) != EOF)
	{
		if(rec[i].r == '\0') continue;
		if(rec[i].r != 'r' && rec[i].r != 'R') return (-1);
		if(rec[i].w <= 0 || rec[i].h <= 0) return (-1);
		i++;
	}
	rec_num = i;
	return (0);
}

int is_in_rec(float xt, float yt, float xb, float yb, float x, float y)
{
	if(xt <= x && x <= xb && yt <= y && y <= yb)
		return (1);
	return (0);
}

int is_side_rec(float xt, float yt, float xb, float yb, float x, float y)
{
	if(xt <= x && x <= xb)
		if((yt <= y && y < yt+1) || (yb-1 < y && y <= yb))
			return (1);
	if (yt <= y && y <= yb)
		if((xt <= x && x < xt+1) || (xb-1 < x && x <= xb))
			return (1);
	return (0);
}

void filled_rec(float x, float y, float w, float h, char c)
{
	for(int i=0; i<paper.h; i++)
	{
		for(int j=0; j<paper.w; j++)
		{
			if(is_in_rec(x, y, x+w, y+h, j, i) == 1)
				map[i][j] = c;
			if(j > x+w) break;
		}
		if(i > y+h) break;
	}
}

void empty_rec(float x, float y, float w, float h, char c)
{
	for(int i=0; i<paper.h; i++)
	{
		for(int j=0; j<paper.w; j++)
		{
			if(is_side_rec(x, y, x+w, y+h, j, i) == 1)
				map[i][j] = c;
			if(j > x+w) break;
		}
		if(i > y+h) break;
	}
}

void draw_rec()
{
	for(int i=0; i < rec_num; i++)
	{
		if(rec[i].r == 'r')
			empty_rec(rec[i].x, rec[i].y, rec[i].w, rec[i].h, rec[i].c);
		if(rec[i].r == 'R')
			filled_rec(rec[i].x, rec[i].y, rec[i].w, rec[i].h, rec[i].c);
	}
}

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		putstr("Error: argument\n");
		return (1);
	}
	if(init(argv[1]) == -1)
	{
		putstr("Error: operation file corrupted\n");
		return (1);
	}
	get_map();
	draw_rec();
	print_map();
	return (0);
}