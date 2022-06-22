# Libft

## 참조
<https://www.cplusplus.com/reference/>   
<https://www.ibm.com/docs/ko>

## 목차
* Part 1 - Libc functions
* Part 2 - Additional functions

## 함수 설명 구조
* 함수 설명
* 매개 인자
* 구동 방식
* 예제 코드

## Part 1 - Libc functions
### ft_isalpha
* 문자가 알파벳인지 확인
* int c
* 문자라면 1, 아니라면 0
```c
/* isalpha example */
#include <stdio.h>
#include "ft_isalpha.c"
int main ()
{
  int i=0;
  char str[]="C++";
  while (str[i])
  {
    if (ft_isalpha(str[i])) printf ("character %c is alphabetic\n",str[i]);
    else printf ("character %c is not alphabetic\n",str[i]);
    i++;
  }
  return 0;
}
```

### ft_isdigit
* 문자가 숫자인지 확인
* int c
* 숫자라면 1, 아니라면 0

```c
/* isdigit example */
#include <stdio.h>
#include "ft_isdigit.c"
int main ()
{
  char str[]="1776ad";
  int year;
  if (ft_isdigit(str[0]))
  {
    year = atoi (str);
    printf ("The year that followed %d was %d.\n",year,year+1);
  }
  return 0;
}
```

### ft_isalnum
* 문자가 알파벳 또는 숫자인지 확인
* int c
* 알파벳이거나 숫자라면 1, 아니라면 0

```c
/* isalnum example */
#include <stdio.h>
#include "ft_isalnum.c"
int main ()
{
  int i;
  char str[]="c3po...";
  i=0;
  while (ft_isalnum(str[i])) i++;
  printf ("The first %d characters are alphanumeric.\n",i);
  return 0;
}
```

### ft_isascii
* ASCII값으로 표시 가능한 문자인지 확인
* int c
* ASCII값으로 표시 가능하다면 1, 아니라면 0

```c
#include <stdio.h>
#include <ctype.h>
int main(void)
{
   int ch;
 
   for (ch = 0x7c; ch <= 0x82; ch++) {
      printf("%#04x    ", ch);
      if (isascii(ch))
         printf("The character is %c\n", ch);
      else
         printf("Cannot be represented by an ASCII character\n");
   }
   return 0;
}
```

### ft_isprint
* 문자가 출력 가능한지 확인
* int c
* 출력이 가능하다면 1, 아니라면 0

```c
/* isprint example */
#include <stdio.h>
#include "ft_isprint.c"
int main ()
{
  int i=0;
  char str[]="first line \n second line \n";
  while (ft_isprint(str[i]))
  {
    putchar (str[i]);
    i++;
  }
  return 0;
}
```

### ft_strlen
* 문자열의 길이
* const char *s
* NULL 문자를 만나기 전까지 길이를 셈

```c
/* strlen example */
#include <stdio.h>
#include "ft_strlen.c"

int main ()
{
  char szInput[256];
  printf ("Enter a sentence: ");
  gets (szInput);
  printf ("The sentence entered is %u characters long.\n",(unsigned)ft_strlen(szInput));
  return 0;
}
```

### ft_memset
* 특정 값으로 바이트 블록을 채움
* void *dest, int c, size_t count
* c값으로 count만큼 dest를 채움

```c
/* memset example */
#include <stdio.h>
#include "ft_memset.c"

int main ()
{
  char str[] = "almost every programmer should know memset!";
  ft_memset (str,'-',6);
  puts (str);
  return 0;
}
```

### ft_bzero
* 0으로 바이트 블록을 채움
* void *dest, size_t count
* 0으로 count만큼 dest를 채워 반환

### ft_memcpy
* 바이트 블럭 복사
* void *dest, const void *src, size_t count
* src의 count 바이트를 dest에 복사

```c
/* memcpy example */
#include <stdio.h>
#include "ft_strlen.c"
#include "ft_memcpy.c"

struct {
  char name[40];
  int age;
} person, person_copy;

int main ()
{
  char myname[] = "Pierre de Fermat";

  /* using memcpy to copy string: */
  ft_memcpy ( person.name, myname, ft_strlen(myname)+1 );
  person.age = 46;

  /* using memcpy to copy structure: */
  ft_memcpy ( &person_copy, &person, sizeof(person) );

  printf ("person_copy: %s, %d \n", person_copy.name, person_copy.age );

  return 0;
}
```

### ft_memmove
* 바이트 블럭 복사
* void *dest, const void *src, size_t count
* src의 count 바이트를 dest에 복사

```c
/* memmove example */
#include <stdio.h>
#include "ft_memmove.c"

int main ()
{
  char str[] = "memmove can be very useful......";
  ft_memmove (str+20,str+15,11);
  puts (str);
  return 0;
}
```

### ft_strlcpy
* 안정성 있는 strcpy
* char *dest, const char *src, size_t count
* 최대 count - 1만큼 복사(마지막 바이트에 NULL값을 넣어주기 위함)

### ft_strlcat
* 안정성 있는 strcat
* char *dest, const char *src, size_t count
* 최대 count - strlen(dest) - 1만큼 복사(마지막 바이트에 NULL값을 넣어주기 위함)

### ft_toupper
* 소문자를 대문자로 변환
* int c
* 문자가 소문자라면 대문자로 변환, 아니라면 변경하지 않고 return

```c
/* toupper example */
#include <stdio.h>
#include "ft_toupper.c"
int main ()
{
  int i=0;
  char str[]="Test String.\n";
  char c;
  while (str[i])
  {
    c=str[i];
    putchar (ft_toupper(c));
    i++;
  }
  return 0;
}
```

### ft_tolower
* 대문자르 소문자로 변환
* int c
* 문자가 대문자라면 소문자로 변환, 아니라면 변경하지 않고 return
```c
/* tolower example */
#include <stdio.h>
#include <ctype.h>
int main ()
{
  int i=0;
  char str[]="Test String.\n";
  char c;
  while (str[i])
  {
    c=str[i];
    putchar (tolower(c));
    i++;
  }
  return 0;
}
```

### ft_strchr
* 앞에서부터 문자열 안의 특정 문자 주소 찾기
* const char *s, int c
* 문자열 안의 특정 문자가 위치한 주소, 아니라면 NULL return

```c
/* strchr example */
#include <stdio.h>
#include "ft_strchr.c"

int main ()
{
  char str[] = "This is a sample string";
  char * pch;
  printf ("Looking for the 's' character in \"%s\"...\n",str);
  pch=ft_strchr(str,'s');
  while (pch!=NULL)
  {
    printf ("found at %ld\n",pch-str+1);
    pch=ft_strchr(pch+1,'s');
  }
  return 0;
}
```

### ft_strrchr
* 뒤에서부터 문자열 안의 특정 문자 주소 찾기
* const char *s, int c
* 문자열 안의 특정 문자가 위치한 주소, 아니라면 NULL return

### ft_strncmp
* 특정 구간까지 두 주소 비교
* unsigned char *s1, unsigned char *s2, size_t count
* count만큼 바이트 블록 단위로 두 주소의 값 비교

```c
/* strncmp example */
#include <stdio.h>
#include "ft_strncmp.c"

int main ()
{
  char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
  int n;
  puts ("Looking for R2 astromech droids...");
  for (n=0 ; n<3 ; n++)
    if (ft_strncmp (str[n],"R2xx",2) == 0)
    {
      printf ("found %s\n",str[n]);
    }
  return 0;
}
```

### ft_memchr
* 앞에서부터 특정 바이트 블록 값 찾기
* const void *s, int c, size_t count
* 최대 count만큼 s와 c 비교하여 같다면 해당 주소, 없다면 NULL

```c
/* memchr example */
#include <stdio.h>
#include "ft_memchr.c"
#include "ft_strlen.c"

int main ()
{
  char * pch;
  char str[] = "Example string";
  pch = (char*) ft_memchr (str, 'p', ft_strlen(str));
  if (pch!=NULL)
    printf ("'p' found at position %ld.\n", pch-str+1);
  else
    printf ("'p' not found.\n");
  return 0;
}
```

### ft_memcmp
* 두 주소를 바이트 블록 단위로 비교
* const void *s1, const void *s2, size_t count
* 같지 않다면 해당 바이트 블록 연산값(s1 - s2), 같다면 0 return

```c
/* memcmp example */
#include <stdio.h>
#include "ft_memcmp.c"

int main ()
{
  char buffer1[] = "DWgaOtP12df0";
  char buffer2[] = "DWGAOTP12DF0";

  int n;

  n=ft_memcmp ( buffer1, buffer2, sizeof(buffer1) );

  if (n>0) printf ("'%s' is greater than '%s'.\n",buffer1,buffer2);
  else if (n<0) printf ("'%s' is less than '%s'.\n",buffer1,buffer2);
  else printf ("'%s' is the same as '%s'.\n",buffer1,buffer2);

  return 0;
}
```

### ft_strnstr
* 서브 문자열 찾기
* const char *haystack, const char *needle, size_t count
* 찾을 경우 해당 haystack index, 없을 경우 NULL return

### ft_atoi
* 문자열을 정수형으로 변환
* const char *str
* 정수형 범위가 넘을 경우, 양의 정수면 -1, 음의 정수면 0 return

```c
/* atoi example */
#include <stdio.h>      /* printf, fgets */
#include "ft_atoi.c"     /* atoi */

int main ()
{
  int i;
  char buffer[256];
  printf ("Enter a number: ");
  fgets (buffer, 256, stdin);
  i = ft_atoi (buffer);
  printf ("The value entered is %d. Its double is %d.\n",i,i*2);
  return 0;
}
```

### ft_calloc
* 공간을 할당받고 할당받은 모든 공간의 값을 0으로 초기화
* size_t count, size_t size
* 할당받으면 해당 주소, 받지 못하면 NULL return

```c
/* calloc example */
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* calloc, exit, free */

int main ()
{
  int i,n;
  int * pData;
  printf ("Amount of numbers to be entered: ");
  scanf ("%d",&i);
  pData = (int*) calloc (i,sizeof(int));
  if (pData==NULL) exit (1);
  for (n=0;n<i;n++)
  {
    printf ("Enter number #%d: ",n+1);
    scanf ("%d",&pData[n]);
  }
  printf ("You have entered: ");
  for (n=0;n<i;n++) printf ("%d ",pData[n]);
  free (pData);
  return 0;
}
```

### ft_strdup
* 문자열 사본 생성
* const char *s1
* 사본 생성시 해당 주소, 실패시 NULL return

## Part 2 - Additional functions
### ft_substr
* 문자열의 특정 부분 문자열 생성
* char const *s, unsigned int start, size_t len
* s의 start 지점부터 최대 len만큼 동적할당하여 복사, 실패시 NULL return

### ft_strjoin
* 2개의 문자열을 이어붙인 문자열 생성
* char const *s1, char const *s2
* s1과 s2를 이어붙여 문자열을 동적할당하여 복사, 실패시 NULL return

### ft_strtrim
* 앞뒤에 특정문자를 제외한 문자열을 생성
* char const *s1, char const *set
* s1 앞뒤에 set에 포험된 문자 제외하여 동적할당하여 복사, 실패시 NULL return

### ft_split
* 문자열을 구분자를 기준으로 나누어 2차원 배열 생성
* char const *s, char c
* s를 c 단위로 나누어 문자열 동적할당하여 복사하여 2차원 배열, 실패시 NULL return

### ft_itoa
* 숫자을 문자로 표현한 문자열 생성
* int n
* n을 문자로 표현한 문자열, 실패시 NULL return

### ft_strmapi
* 문자열의 각 문자에 대해 기능하는 함수 사용
* char const *s, char (*f)(unsigned int, char)
* 각 문자와 해당 index에 대한 함수를 사용하여 s에 적용

### ft_striteri
* 문자열의 각 index pointer에 대해 기능하는 함수 사용
* char *s, void (*f)(unsigned int, char*)
* 문자열의 각 index pointer에 대해 함수 적용

### ft_putchar_fd
* file descriptor로 문자 출력
* char c, int fd
* fd로 c 출력, fd가 음수거나 0일 때는 사용하지 않음

### ft_putstr_fd
* file descriptor로 문자열 출력
* char *s, int fd
* fd로 s 출력, fd가 음수거나 0일 때는 사용하지 않음

### ft_putendl_fd
* file descriptor로 문자열 출력 후 next line
* char *s, int fd
* fd로 s 출력 후 next line, fd가 음수거나 0일 때는 사용하지 않음

### ft_putnbr_fd
* file descriptor로 정수 출력
* int n, int fd
* fd로 정수를 표현하여 출력, fd가 음수거나 0일 때는 사용하지 않음

## BONUS
### ft_lstnew
* 새로운 내용에 대한 node를 할당하여 반환
* void *content
* node를 동적할당하여 content를 담고 next = NULL, 실패시 NULL 반환

### ft_lstadd_front
* node를 list 가장 앞에 위치시킴
* t_list **lst, t_list *new
* lst의 가장 앞에 new를 위치, lst 또는 new가 NULL일 시 수행하지 않음

### ft_lstsize
* list의 길이
* t_list *lst
* head node부터 tail node까지의 길이 반환

### ft_lstlast
* tail node 탐색
* t_list *lst
* lst를 탐색하여 tail node, 빈 list일 시 NULL 반환

### ft_lstadd_back
* node를 list 가장 뒤에 위치시킴
* t_list **lst, t_list *new
* lst의 가장 뒤에 new를 위치, lst 또는 new가 NULL일 시 수행하지 않음

### ft_lstdelone
* node 동적할당 해제
* t_list *lst, void (*del)(void*)
* lst 안의 멤버(content) del 함수 수행 후 lst 동적할당 해제, lst 또는 del가 NULL일 시 수행하지 않음

### ft_lstclear
* list 동적할당 해제
* t_list **lst, void (*del)(void*)
* list 안의 node를 순회하며 동적할당 해제, lst 또는 del이 NULL일 시 수행하지 않음

### ft_lstiter
* node의 content 멤버마다 함수 적용
* t_list *lst, void (*f)(void *)
* lst를 순회하며 node의 content 멤버마다 함수 f 적용, lst 또는 f가 NULL일 시 수행하지 않음

### ft_lstmap
* 기존 list에 함수를 적용시켜 새로운 list를 만들어 반환
* t_list *lst, void *(*f)(void *), void (*del)(void *)
* lst의 각 node에 함수 f를 적용시켜 새 list 만들어 반환, node 생성 오류시 del을 이용하여 새 list 동적할당 해제   
lst, f 또는 del이 NULL일 시 수행하지 않음