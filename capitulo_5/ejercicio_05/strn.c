#include <stdio.h> 

#define EQ 1
#define NEQ -1
#define MAX_SIZE    30

char* strncpy(char* s, const char* t, int n);
char* strncat(char* s, const char* t, int n);
int strncmp(const char* s, const char* t, int n);

char* strncpy(char* s, const char* t, int n)
{
  char* ss = s;
  while (n-- && (*s++ = *t++));
  *s = '\0';
  return ss;
}

// Redefining this function definition to allow 
// memory safety: 
//
// strncat: Concatenate string t to string s, terminate s with '\0', ensuring 
//          the final concatenated string is at most n characters in size. If s points 
//          to an amount of characters greater than n, return an error code. 
char* strncat(char* s, const char* t, int n)
{
  char* ss = s;
  int ns = n;
  while ((*s++ != '\0') && n--);  // strlen(s + t) < n => strlen(s) < n
  if (*s != '\0') return NULL;
  (void)strncpy(--s, t, ns);
  return ss;
}

int strncmp(const char* s, const char* t, int n)
{
  while (n--) if (*s++ != *t++) return NEQ;
  return EQ;
}

int main (void)
{
  const char* str1 = "Hola, ";
  const char* str2 = "mundo!";
  char str3[MAX_SIZE];
  char str4[MAX_SIZE];
  printf("str1 = %s\nstr2 = %s\nstrncpy str3 <- str2 = %s\n", str1, str2, strncpy(str3, str2, MAX_SIZE));
  printf("strncpy str4 <- str1 = %s\n", strncpy(str4, str1, MAX_SIZE));
  char* str42 = strncat(str4, str2, MAX_SIZE);
  if (str42 == NULL)
  {
    printf("Error: strncat returned %p", str42);
    return 1;
  }
  printf("str1 + str2 = %s\n", str42);
  printf("str1 == str1 = %s\n", strncmp(str1, str1, MAX_SIZE) > 0 ? "True" : "False");
  printf("str1 == str2 = %s\n", strncmp(str1, str2, MAX_SIZE) > 0 ? "True" : "False");
  return 0; 
}

// gcc -fno-builtin strn.c
// ./a.out
