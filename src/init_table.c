/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** babl - 2022
**
** *****************************************************************************
*/

#include		"babl.h"

t_symbol_table		*std_init_table()
{
  t_symbol_table	*table;

  table = malloc(sizeof(t_symbol_table));
  if (table == NULL)
    return (NULL);
  table->table = NULL;
  return (table);
}
