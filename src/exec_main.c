/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** exec_main - 2022
**
** *****************************************************************************
*/

#include	"babl.h"

int			std_exec_main(char		*cmd,
				      t_symbol_table	*table,
				      size_t		*i,
				      int		*result)
{
  t_variable		*value;
  t_symbol_table	*tab[2];

  tab[0] = table;
  tab[1] = NULL;
  std_read_text(cmd, i, "()");
  value = malloc(sizeof(t_variable));
  if (value == NULL)
    return (-1);
  value = std_compute(cmd, i, tab);
  if (value == NULL)
    return (-1);
  if (value->type == ADR)
    {
      std_free_variable(value);
      return (-1);
    }
  *result = ((t_value *)(value->data))->value;
  return (1);
}
