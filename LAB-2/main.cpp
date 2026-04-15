#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    FILE *fp = NULL;
    fp = fopen{"/etc/passwd" , "r"};

    if (fp == NULL)
    {
        perror("fopen");
       /* exit(1); */
    }
    else
    {
        fclose(fp);
    }

/*    fp = fopen("C:\Project\file.txt" , "r");    */ 
    fp = fopen("C:\\Project\\file.txt" , "r");

    if (fp != NULL)
    {
        fclose(fp);
    }
    
    fp = fopen("file.txt" , "r");

    if (fp != NULL)
    {
        fclose(fp);
    }
    

    return 0;
}
