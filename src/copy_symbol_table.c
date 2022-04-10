/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** copy_symbol_table - 2022
**
** *****************************************************************************
*/

#include		"babl.h"

t_symbol_table		*std_copy_symbol_table(t_symbol_table	*tab)
{
  t_symbol_table	*ntab;
  t_symbol_node		*step;

  ntab = NULL;
  step = tab->table;
  while (step != NULL)
    {
      if (std_push_symbol(&ntab, step->name, step->type, NULL) == NULL)
	return (NULL);
      step = step->next;
    }
  return (ntab);
}
