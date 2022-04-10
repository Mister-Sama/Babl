/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** babl - 2022
**
** *****************************************************************************
*/

#include        "babl.h"

t_function	*std_get_func_parameters(char	*line,
					 size_t	*i,
					 int	res)
{
  t_function	*func;
  int		type;

  func = malloc(sizeof(t_function));
  if (func == NULL)
    return (NULL);
  func->local_table = NULL;
  if (std_read_chars(line, i, "(") == false)
    return (NULL);
  while (std_read_chars(line, i, ")") != true)
    {
      if (std_read_chars(line, i, "$"))
	type = ADR;
      else if (std_read_chars(line, i, "#"))
	type = VAL;
      else
	return (NULL);
      std_push_symbol((t_symbol_table **) &func->local_table, std_find_name(line, i), type, NULL);
      std_read_chars(line, i, ",");
    }
  func->code = &line[*i];
  func->result = res;
  return (func);
}
