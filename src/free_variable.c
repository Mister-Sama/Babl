/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** free_variable - 2022
**
** *****************************************************************************
*/

#include	"babl.h"

void		std_free_variable(t_variable	*var)
{
  if (var != NULL)
    {
      if (var->type == ADR)
	free(((t_adress *)(var->data))->adress);
      (var->data != NULL) ? free(var->data) : 0;
      free(var);
    }
}

