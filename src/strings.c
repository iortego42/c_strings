#include "libstrings.h"

void	dtor(t_string *string)
{
	if (!string || !(*string) )
		return ;
	if ((*string)->data)
		free((*string)->data);
	(*string)->data = NULL;
	free(*string);
	*string = NULL;
}

void	ctor(t_string *string, const char *data)
{
	if (!string)
		return ;
	*string = malloc(sizeof(struct s_str));
	if (*string)
	{
		(*string)->start = 0;
		(*string)->end = 0;
		(*string)->data_len = 0;
		if (data)
		{
			while (data[(*string)->end])
				(*string)->end++;
			(*string)->data = malloc(sizeof(char) * ((*string)->end + 1));
			while ((*string)->data && data[(*string)->data_len])
			{
				(*string)->data[(*string)->data_len] = data[(*string)->data_len];
				(*string)->data_len++;
			}
			(*string)->data[(*string)->data_len] = 0;
		}
	}
}
