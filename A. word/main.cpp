#include<stdio.h>
#include<ctype.h> //For isupper, islower, toupper, tolower
#include<string.h> //for strlen

int main() {
  char s[101];
  char s_correct[101];
  int len = 0;
  int upper = 0;

  scanf("%100s",s);
  
  len = strlen(s);

  //count number of upper
  for(int i = 0; i < len; i++) {
    char c = s[i];
    if(isupper((unsigned char)c)) {
      upper++; 
    }
  }

  
  if (upper > len - upper) {

    for(int i = 0; i < len; i++) {
      //More upper character than lower
        s_correct[i] = toupper((unsigned char)s[i]);
      }
  } else {

    for(int i = 0; i < len; i++) {
      //More lower character than upper
        s_correct[i] = tolower((unsigned char)s[i]);
    }

  }

  s_correct[len] = '\0';

  printf("%s\n",s_correct);
  return 0;
}
  
