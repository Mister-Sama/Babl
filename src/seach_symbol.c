/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** search_symbol - 2022
**
** *****************************************************************************
*/

#include        "babl.h"

t_variable	*std_search_symbol(char			*cmd,
				   size_t		*i,
				   char			*symbol,
				   t_symbol_table	**tab)
{
  t_variable	*var;
  t_symbol_node	*step;

  step = (tab[0])->table;
  var = NULL;
  while (step != NULL && var == NULL)
    {
      if (std_strcmp(symbol, step->name))
	var = std_assign_symbol(cmd, i, step, tab);
      step = step->next;
    }
  if (tab[1] != NULL && var == NULL)
    {
      step = (tab[1])->table;
      while (step != NULL && var == NULL)
	{
	  if (std_strcmp(symbol, step->name))
	    var = std_assign_symbol(cmd, i, step, tab);
	  step = step->next;
	}
    }
  if (var == NULL)
    return (NULL);
  return (var);
}
