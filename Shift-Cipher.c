#include<stdio.h>
#include<stdlib.h>
char *encrypt(char plaintext[],int key)
{
  for(int i=0;plaintext[i]!='\0';i++)
  {
    if ( plaintext[i]>=48 && plaintext[i]<=57)
    {
      plaintext[i]=(plaintext[i]-48+key)%10+48;
    }
    else if (plaintext[i]>=65 && plaintext[i]<=90)
    {
      plaintext[i]=(plaintext[i]-65+key)%26+65;
    }
    else if (plaintext[i]>=97 && plaintext[i]<=122)
    {
      plaintext[i]=(plaintext[i]-97+key)%26+97;
    }
    else
    {
      continue;
    }
  }
  return plaintext;
}
char *decrypt(char ciphertext[],int key)
{
  for(int i=0;ciphertext[i]!='\0';i++)
  {
    if (ciphertext[i]>=48 && ciphertext[i]<=57)
    {
      ciphertext[i]=(ciphertext[i]-38-key)%10+48;
    }
    else if (ciphertext[i]>=65 && ciphertext[i]<=90)
    {
      ciphertext[i]=(ciphertext[i]-39-key)%26+65;
    }
    else if (ciphertext[i]>=97 && ciphertext[i]<=122)
    {
      ciphertext[i]=(ciphertext[i]-71-key)%26+97;
    }
    else
    {
      continue;
    }
  }
  return ciphertext;
}
void main()
{
  while (1)
  {
    int k;
    char *j;
    printf("Welcome to Shift Cipher Tool\nWhat do you want to do?\n1. Encrypt\n2. Decrypt\n3. Exit\nEnter your choice : ");
    scanf("%d",&k);
    switch (k)
    {
      case 1:
        printf("Enter your plaintext : ");
        scanf(" %m[^\n]",&j);
        printf("Enter your key (between 0 and 25) : ");
        scanf("%d",&k);
        printf("Your Ciphertext is : %s\n",encrypt(j,k));
        break;
      case 2:
        printf("Enter your ciphertext : ");
        scanf(" %m[^\n]",&j);
        printf("Enter your key (between 0 and 25) : ");
        scanf("%d",&k);
        printf("Your Plaintext is : %s\n",decrypt(j,k));
        break;
      case 3:
        printf("Bye!\n");
        exit(0);
        break;
      default:
        printf("Enter a valid option!\n");
    }
  }
}
