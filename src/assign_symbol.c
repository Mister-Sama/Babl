/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** assign_symbol - 2022
**
** *****************************************************************************
*/

#include		"babl.h"

static t_variable	*std_crochet(char			*cmd,
				     size_t			*i,
				     t_variable			*var,
				     t_symbol_table		**tab)
{
  t_variable		*occ;
  t_value		*val;
  
  if (std_read_text(cmd, i, "["))
    {
      occ = std_compute(cmd, i, tab);
      if (occ == NULL)
	{
	  std_free_variable(var);
	  return (NULL);
	}
      if (occ->type == ADR)
	{
	  std_free_variable(var);
	  std_free_variable(occ);
	  return (NULL);
	}
      var->type = VAL;
      if ((val = malloc(sizeof(t_value))) == NULL)
	{
	  std_free_variable(var);
	  std_free_variable(occ);
	  return (NULL);
	}
      val->value = ((t_adress *)(var->data))->adress[((t_value *)(occ->data))->value];
      std_free_variable(occ);
      if (std_read_text(cmd, i, "]") == false)
	{
	  std_free_variable(var);
	  return (NULL);
	}
      var->data = val;
    }
  return (var);
}

t_variable		*std_assign_symbol(char			*cmd,
					   size_t		*i,
					   t_symbol_node	*symbol,
					   t_symbol_table	**tab)
{
  t_variable		*var;
  t_symbol_table	*table[2];
  size_t		j;
  
  j = 0;
  table[0] = tab[0];
  if ((var = malloc(sizeof(t_variable))) == NULL)
    return (NULL);
  if (symbol->type == FUNC)
    {
      table[1] = std_add_parameter(std_copy_symbol_table(((t_function *) symbol->data)->local_table), cmd, i, tab);
      if (table[1] == NULL)
	{
	  free(var);
	  return (NULL);
	}
      var = std_compute(((t_function *)(symbol->data))->code, &j, table);
      free(table[1]);
    }
  else
    {
      var->type = symbol->type;
      var->data = symbol->data;
      var = (var->type == ADR) ? std_crochet(cmd, i, var, tab) : var;
    }
  return (var);
}

