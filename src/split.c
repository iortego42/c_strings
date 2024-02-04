#include "libstrings.h"

// static int wordcount(t_string   this, char  *delimitator)
static int	wordcount(t_string this, t_string delimitator)
{
	int			words;
	size_t		init_start;
	size_t		del_len;
	t_string	next;

	words = 0;
	next = str_cpy(this);
	if (!next)
		return (0);
	init_start = this->start;
	del_len = len(delimitator);
	while (next->start < next->end)
	{
		findword(next, delimitator);
		words++;
		next->start = next->end;
		next->end = this->end;
	}
	this->start = init_start;
	dtor(&next);
	return (words);
}

void	clearlist(t_string this, size_t size)
{
	if (!this->list)
		return ((void)"");
	if (size == 0)
		while (this->list_size--)
			dtor(&this->list[this->list_size]);
	else
		while (size--)
			dtor(&this->list[size]);
	free(this->list);
	this->list = NULL;
}

t_string	split(t_string this, t_string delimitator)
{
	size_t		w;
	t_string	str;

	w = 0;
	if (this->list)
		clearlist(this, 0);
	this->list_size = wordcount(this, delimitator);
	this->list = malloc(sizeof(t_string) * this->list_size);
	if (!this->list)
		this->list_size = 0;
	str = str_cpy(this);
	if (!str)
		return (NULL);
	while (w++ < this->list_size)
	{
		findword(str, delimitator);
		this->list[w - 1] = nstr_cpy(str);
		if (this->list[w - 1] == NULL)
			return (dtor(&str), clearlist(this, w - 1), NULL);
		str->start = str->end;
		str->end = this->end;
	}
	dtor(&str);
	return (this);
}

t_string	nsplit(t_string this, t_string delimitator)
{
	t_string	newlist;

	if (this->list)
		clearlist(this, 0);
	newlist = nstr_cpy(this);
	if (!newlist)
		return (NULL);
	if (split(newlist, delimitator))
		return (newlist);
	else
	{
		dtor(&newlist);
		return (NULL);
	}
}
