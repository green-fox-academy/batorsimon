#include <stdio.h>
#include <stdlib.h>

//Create a function named is anagram following your current language's style guide.
//It should take two strings and return a boolean value depending on whether its an anagram or not.

int anagram(char[], char[]);

int main()
{
    char input[20] = {0};
    char input2[20] = {0};
    int check= 0;

    printf("Type in a word: ");
    scanf("%s", &input);

    printf("\nType an anagram of the given word: ");
    scanf("%s", &input2);

    check = anagram(input, input2);

    if (check == 1)
        printf("\"%s\" and \"%s\" are anagrams.\n", input, input2);
    else
        printf("\"%s\" and \"%s\" are not anagrams.\n", input, input2);
    return 0;
}

int anagram(char input[], char input2[])
{
    int arr1[26] = {0};
    int arr2[26] = {0};
    int i = 0;

   while (input[i] != '\0')
   {
      arr1[input[i]-'a']++;
      i++;
   }

   i = 0;

   while (input2[i] != '\0')
   {
      arr2[input2[i]-'a']++;
      i++;
   }

   for (i = 0; i < 26; i++)
   {
      if (arr1[i] != arr2[i])
         return 0;
   }

   return 1;



}
