#include <stdio.h> 

int strend(char*, char*);

int main(void)
{
  char* my_string_1 = "Hello, World!";
  char* my_string_2 = "World!";

  if (strend(my_string_1, my_string_2) == 1)
  {
    printf("The string \"%s\" occurs at the end of the string \"%s\"\n", my_string_1, my_string_2);
  }
  else
  {
    printf("The string \"%s\" does NOT occur at the end of the string \"%s\"\n", my_string_1, my_string_2);
  }
}

int strend(char* str1, char* str2)
{
  size_t len1 = 0;
  size_t len2 = 0;

  /* Find the lenght of both strings 
   * WARNING: This makes this function dangerous due to no bound checking! 
   */
  while(str1[len1++] != '\0');
  while(str2[len2++] != '\0');

  /* Reverse-compare str1 and str2 */
  while(--len1 && --len2)
  {
    if (str1[len1] != str2[len2])
    {
      return 0;
    }
  }
  return 1;
}
