/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** add_parameter - 2022
**
** *****************************************************************************
*/

#include                "babl.h"

void			*std_add_parameter(t_symbol_table	*ntab,
					   char			*cmd,
					   size_t		*i,
					   t_symbol_table	**tab)
{
  t_symbol_node		*step;
  t_variable		*save;
  
  if (std_read_text(cmd, i, "(") == false)
    return (NULL);
  step = ntab->table;
  while (step != NULL)
    {
      if (step == NULL)
	return (NULL);
      save = std_compute(cmd, i, tab);
      if (save == NULL)
	return (NULL);
      if (save->type != step->type)
	return (NULL);
      step->data = save->data;
      free(save);
      step = step->next;
      std_read_text(cmd, i, ",");
      std_read_text(cmd, i, ")");
    }
  return (ntab);
}
					   
