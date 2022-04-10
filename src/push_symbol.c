/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** push_symbol - 2022
**
** *****************************************************************************
*/

#include        "babl.h"

t_symbol_node	*std_push_symbol(t_symbol_table		**table,
				 char			*name,
				 int			type,
				 void			*data)
{
  t_symbol_node	*nsymbol;
  t_symbol_node	*save;

  if (*table == NULL)
    *table = std_init_table();
  nsymbol = malloc(sizeof(t_symbol_node));
  if (nsymbol == NULL)
    return (NULL);
  nsymbol->name = name;
  nsymbol->type = type;
  nsymbol->data = data;
  nsymbol->next = NULL;
  if ((*table)->table == NULL)
    (*table)->table = nsymbol;
  else
    {
      save = (*table)->table;
      while (save->next != NULL)
	save = save->next;
      save->next = nsymbol;
    }
  return (nsymbol);
}
