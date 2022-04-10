/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@csr-pi02.ecole-89.com>
**
** realloc - 2022
**
** *****************************************************************************
*/

#include        "babl.h"

void            *std_realloc(void       *ptr,
                             size_t     size)
{
  char          *nptr;
  size_t        i;

  i = 0;
  nptr = malloc(size);
  while (i != size)
    {
      nptr[i] = '\0';
      i = i + 1;
    }
  i = 0;
  while (i != size && i != malloc_usable_size(ptr))
    {
      nptr[i] = ((char *)ptr)[i];
      i = i + 1;
    }
  nptr[size - 1] = '\0';
  if (ptr != NULL)
    free(ptr);
  return (nptr);
}

