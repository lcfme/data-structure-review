#include <stdlib.h>
#include <stdio.h>

void strcopy(char *dest, char *src)
{
  int i = 0;
  while (*(src + i))
  {
    *(dest + i) = *(src + i);
    ++i;
  }
  *(dest + i) = '\0';
}

long strlength(char *src)
{
  long i = 0;
  while (*(src + i))
  {
    i++;
  }
  return i;
}

long strcompare(char *str1, char *str2)
{
  long str1len = strlength(str1);
  long str2len = strlength(str2);
  for (long i = 0; i < str1len && i < str2len; ++i)
  {
    if (*(str1 + i) != *(str2 + i))
    {
      return *(str1 + i) - *(str2 + i);
    }
  }
  return str1len - str2len;
}

void strconcat(char *dest, char *src, int n)
{
  int i = 0;
  while (*(src + i) && i < n)
  {
    *(dest + i) = *(src + i);
    ++i;
  }
  *(dest + i) = '\0';
}

void strsubstr(char *sub, char *src, int at, int len)
{
  int i = 0;
  while (*(src + at + i) && i < len)
  {
    *(sub + i) = *(src + at + i);
    ++i;
  }
  *(sub + i) = '\0';
}

int strindexof(char *src, char *sub)
{
  int count = 0, index = -1, start = count, m = 0;
  while (*(src + count) && m < strlength(sub))
  {
    if (*(src + start) == *(sub + m))
    {
      index = count;
      ++m;
      ++start;
    }
    else
    {
      m = 0;
      index = -1;
      start = ++count;
    }
  }
  return index;
}

int strIndexOf2(char *src, char *sub)
{
  int i = 0;
  while (*(src + i))
  {
    int m = 0;
    int flag = 0;
    while (*(src + i + m) && *(src + i + m) == *(sub + m))
    {
      if (++m == strlength(sub))
      {
        flag = 1;
        break;
      };
    }
    if (flag)
    {
      return i;
    }
    ++i;
  }
  return -1;
}


int main()
{
  char *wele = "Hello World!";
  char *dest = "Wor";
  int indexOf = strIndexOf2(wele, dest);
  printf("%d\n", indexOf);
}
