#include "libstrings.h"

long int str_cmp(t_string one, t_string two) {
  size_t ione;
  size_t itwo;

  if (one == NULL || one->data == NULL)
    return (0);
  if (two == NULL || two->data == NULL)
    return (0);
  ione = one->start;
  itwo = two->start;
  ;
  while (ione < one->end && itwo < two->end) {
    if ((unsigned char)one->data[ione] != (unsigned char)two->data[itwo])
      return ((long)(ione - one->start));
    ione++;
    itwo++;
  }
  if ((unsigned char)one->data[ione] != (unsigned char)two->data[itwo])
    return ((long)(ione - one->start));
  return (-1);
}

long int p_str_cmp(t_string one, const char *two) {
  size_t ione;
  size_t itwo;

  if (one == NULL || one->data == NULL)
    return (0);
  ione = one->start;
  itwo = 0;
  while (ione < one->end && two[itwo] != 0) {
    if ((unsigned char)one->data[ione] != (unsigned char)two[itwo])
      return ((long)(ione - one->start));
    ione++;
    itwo++;
  }
  if ((unsigned char)one->data[ione] != (unsigned char)two[itwo])
    return ((long)(ione - one->start));
  return (-1);
}

long int str_ncmp(t_string one, t_string two, size_t max) {
  size_t ione;
  size_t itwo;

  if (one == NULL || one->data == NULL)
    return (0);
  if (two == NULL || two->data == NULL)
    return (0);
  ione = one->start;
  itwo = two->start;
  while (ione < one->end && itwo < two->end && ione - one->start < max) {
    if ((unsigned char)one->data[ione] != (unsigned char)two->data[itwo])
      return ((long)(ione - one->start));
    ione++;
    itwo++;
  }
  ione--;
  itwo--;
  if ((unsigned char)one->data[ione] != (unsigned char)two->data[itwo])
    return ((long)(ione - one->start));
  return (-1);
}

long int p_str_ncmp(t_string one, const char *two, size_t max) {
  size_t ione;
  size_t itwo;

  if (one == NULL || one->data == NULL)
    return (0);
  ione = one->start;
  itwo = 0;
  while (ione < one->end && two[itwo] != 0 && itwo < max) {
    if ((unsigned char)one->data[ione] != (unsigned char)two[itwo])
      return ((long)(ione - one->start));
    ione++;
    itwo++;
  }
  ione--;
  itwo--;
  if ((unsigned char)one->data[ione] != (unsigned char)two[itwo])
    return ((long)(ione - one->start));
  return (-1);
}
long int endswith(t_string string, t_string s_suffix, char *p_suffix) {
  size_t start;
  long pos;
  size_t len;

  start = string->start;
  if (s_suffix && s_suffix->data) {
    string->start = string->end - s_suffix->start;
    pos = str_cmp(string, s_suffix);
  } else if (p_suffix) {
    len = 0;
    while (p_suffix[len] != 0)
      len++;
    string->start = string->end - len;
    pos = p_str_cmp(string, p_suffix);
  } else
    pos = 0;
  string->start = start;
  return (pos);
}
