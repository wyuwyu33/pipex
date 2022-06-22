/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 03:50:58 by wyu               #+#    #+#             */
/*   Updated: 2022/01/03 16:31:39 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// /* isalpha example */
// #include <stdio.h>
// #include "ft_isalpha.c"
// int main ()
// {
//   int i=0;
//   char str[]="C++";
//   while (str[i])
//   {
//     if (ft_isalpha(str[i])) printf ("character %c is alphabetic\n",str[i]);
//     else printf ("character %c is not alphabetic\n",str[i]);
//     i++;
//   }
//   return 0;
// }

// /* isdigit example */
// #include <stdio.h>
// #include "ft_isdigit.c"
// int main ()
// {
//   char str[]="1776ad";
//   int year;
//   if (ft_isdigit(str[0]))
//   {
//     year = atoi (str);
//     printf ("The year that followed %d was %d.\n",year,year+1);
//   }
//   return 0;
// }

// /* isalnum example */
// #include <stdio.h>
// #include "ft_isalnum.c"
// int main ()
// {
//   int i;
//   char str[]="c3po...";
//   i=0;
//   while (ft_isalnum(str[i])) i++;
//   printf ("The first %d characters are alphanumeric.\n",i);
//   return 0;
// }

// #include <stdio.h>
// #include "ft_isascii.c"
// int main(void)
// {
//    int ch;

//    for (ch = 0x7c; ch <= 0x82; ch++) {
//       printf("%#04x    ", ch);
//       if (ft_isascii(ch))
//          printf("The character is %c\n", ch);
//       else
//          printf("Cannot be represented by an ASCII character\n");
//    }
//    return 0;
// }

// /* isprint example */
// #include <stdio.h>
// #include "ft_isprint.c"
// int main ()
// {
//   int i=0;
//   char str[]="first line \n second line \n";
//   while (ft_isprint(str[i]))
//   {
//     putchar (str[i]);
//     i++;
//   }
//   return 0;
// }

// /* strlen example */
// #include <stdio.h>
// #include "ft_strlen.c"

// int main ()
// {
//   char szInput[256];
//   printf ("Enter a sentence: ");
//   gets (szInput);
//   printf ("The sentence entered is %u characters long.\n",(unsigned)ft_strlen(szInput));
//   return 0;
// }

// /* memset example */
// #include <stdio.h>
// #include "ft_memset.c"

// int main ()
// {
//   char str[] = "almost every programmer should know memset!";
//   ft_memset (str,'-',6);
//   puts (str);
//   return 0;
// }

// /* memcpy example */
// #include <stdio.h>
// #include "ft_strlen.c"
// #include "ft_memcpy.c"

// struct {
//   char name[40];
//   int age;
// } person, person_copy;

// int main ()
// {
//   char myname[] = "Pierre de Fermat";

//   /* using memcpy to copy string: */
//   ft_memcpy ( person.name, myname, ft_strlen(myname)+1 );
//   person.age = 46;

//   /* using memcpy to copy structure: */
//   ft_memcpy ( &person_copy, &person, sizeof(person) );

//   printf ("person_copy: %s, %d \n", person_copy.name, person_copy.age );

//   return 0;
// }

// /* memmove example */
// #include <stdio.h>
// #include "ft_memmove.c"

// int main ()
// {
//   char str[] = "memmove can be very useful......";
//   ft_memmove (str+20,str+15,11);
//   puts (str);
//   return 0;
// }

// /* toupper example */
// #include <stdio.h>
// #include "ft_toupper.c"
// int main ()
// {
//   int i=0;
//   char str[]="Test String.\n";
//   char c;
//   while (str[i])
//   {
//     c=str[i];
//     putchar (ft_toupper(c));
//     i++;
//   }
//   return 0;
// }

// /* tolower example */
// #include <stdio.h>
// #include <ctype.h>
// int main ()
// {
//   int i=0;
//   char str[]="Test String.\n";
//   char c;
//   while (str[i])
//   {
//     c=str[i];
//     putchar (tolower(c));
//     i++;
//   }
//   return 0;
// }

// /* strchr example */
// #include <stdio.h>
// #include "ft_strchr.c"

// int main ()
// {
//   char str[] = "This is a sample string";
//   char * pch;
//   printf ("Looking for the 's' character in \"%s\"...\n",str);
//   pch=ft_strchr(str,'s');
//   while (pch!=NULL)
//   {
//     printf ("found at %ld\n",pch-str+1);
//     pch=ft_strchr(pch+1,'s');
//   }
//   return 0;
// }

// /* strrchr example */
// #include <stdio.h>
// #include "ft_strrchr.c"

// int main ()
// {
//   char str[] = "This is a sample string";
//   char * pch;
//   pch=ft_strrchr(str,'s');
//   printf ("Last occurence of 's' found at %ld \n",pch-str+1);
//   return 0;
// }

// /* strncmp example */
// #include <stdio.h>
// #include "ft_strncmp.c"

// int main ()
// {
//   char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
//   int n;
//   puts ("Looking for R2 astromech droids...");
//   for (n=0 ; n<3 ; n++)
//     if (ft_strncmp (str[n],"R2xx",2) == 0)
//     {
//       printf ("found %s\n",str[n]);
//     }
//   return 0;
// }

// /* memchr example */
// #include <stdio.h>
// #include "ft_memchr.c"
// #include "ft_strlen.c"

// int main ()
// {
//   char * pch;
//   char str[] = "Example string";
//   pch = (char*) ft_memchr (str, 'p', ft_strlen(str));
//   if (pch!=NULL)
//     printf ("'p' found at position %ld.\n", pch-str+1);
//   else
//     printf ("'p' not found.\n");
//   return 0;
// }

// /* memcmp example */
// #include <stdio.h>
// #include "ft_memcmp.c"

// int main ()
// {
//   char buffer1[] = "DWgaOtP12df0";
//   char buffer2[] = "DWGAOTP12DF0";

//   int n;

//   n=ft_memcmp ( buffer1, buffer2, sizeof(buffer1) );

//   if (n>0) printf ("'%s' is greater than '%s'.\n",buffer1,buffer2);
//   else if (n<0) printf ("'%s' is less than '%s'.\n",buffer1,buffer2);
//   else printf ("'%s' is the same as '%s'.\n",buffer1,buffer2);

//   return 0;
// }

// /* atoi example */
// #include <stdio.h>      /* printf, fgets */
// #include "ft_atoi.c"     /* atoi */

// int main ()
// {
//   int i;
//   char buffer[256];
//   printf ("Enter a number: ");
//   fgets (buffer, 256, stdin);
//   i = ft_atoi (buffer);
//   printf ("The value entered is %d. Its double is %d.\n",i,i*2);
//   return 0;
// }

// /* calloc example */
// #include <stdio.h>      /* printf, scanf, NULL */
// #include <stdlib.h>     /* calloc, exit, free */

// int main ()
// {
//   int i,n;
//   int * pData;
//   printf ("Amount of numbers to be entered: ");
//   scanf ("%d",&i);
//   pData = (int*) calloc (i,sizeof(int));
//   if (pData==NULL) exit (1);
//   for (n=0;n<i;n++)
//   {
//     printf ("Enter number #%d: ",n+1);
//     scanf ("%d",&pData[n]);
//   }
//   printf ("You have entered: ");
//   for (n=0;n<i;n++) printf ("%d ",pData[n]);
//   free (pData);
//   return 0;
// }
