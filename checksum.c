#include<stdio.h>

int main()
{
    int n,m,i,j;
    printf("Enter the number of words:");
    scanf("%d",&n);
    printf("Enter the length of each word:");
    scanf("%d",&m);
    int words[n+1][m],carry=0,result[m];
    for(i=0;i<n;i++)
    {
        printf("Enter the %d word:\n",i+1);
        for(j=0;j<m;j++){
            scanf("%d",&words[i][j]);
            result[j]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        carry = 0;
        for(j=m-1;j>=0;j--)
        {
            if((result[j] == 1 && words[i][j] == 1))
            {
                result[j] = carry;
                carry = 1;
            }
            else if(((result[j] == 1 && words[i][j] == 0)||(result[j] == 0 && words[i][j] == 1)) && carry == 0)
            {
                result[j] = 1;
                carry = 0;
            }
            else if(((result[j] == 1 && words[i][j] == 0)||(result[j] == 0 && words[i][j] == 1)) && carry == 1)
            {
                result[j] = 0;
                carry = 1;
            }
            else if((result[j] == 0 && words[i][j] == 0))
            {
                result[j] = carry;
                carry = 0;
            }
        }
        j=m-1;
        while((carry != 0))
        {
            if(result[j]==1)
            {
                result[j]=0;
            }
            else
            {
                result[j]=1;
                carry = 0;
            }
            j--;
        }
    }
    for(i=0;i<m;i++)
    {
        if(result[i]==0)
            result[i]=1;
        else
            result[i]=0;
    }
    printf("Sending data.....\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d",words[i][j]);
        }
        printf("\n");
    }
    
       printf("Checksum = ");
    for(j=0;j<m;j++)
    {
        words[n][j]=result[j];
        printf("%d",result[j]);
        result[j]=0;
    }
 
    printf("\n");
    for(i=0;i<n+1;i++)
    {
        carry = 0;
        for(j=m-1;j>=0;j--)
        {
            if((result[j] == 1 && words[i][j] == 1))
            {
                result[j] = carry;
                carry = 1;
            }
            else if(((result[j] == 1 && words[i][j] == 0)||(result[j] == 0 && words[i][j] == 1)) && carry == 0)
            {
                result[j] = 1;
                carry = 0;
            }
            else if(((result[j] == 1 && words[i][j] == 0)||(result[j] == 0 && words[i][j] == 1)) && carry == 1)
            {
                result[j] = 0;
                carry = 1;
            }
            else if((result[j] == 0 && words[i][j] == 0))
            {
                result[j] = carry;
                carry = 0;
            }
        }
        j=m-1;
        while((carry != 0))
        {
            if(result[j]==1)
            {
                result[j]=0;
            }
            else
            {
                result[j]=1;
                carry = 0;
            }
            j--;
        }
    }
 
    for(i=0;i<m;i++)
    {
        if(result[i]==0)
            result[i]=1;
        else
            result[i]=0;
    }
    
    printf("Recieved data: \n");
    for(i=0;i<n+1;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d",words[i][j]);
        }
        printf("\n");
    }
    for(j=0;j<m;j++)
        printf("%d",result[j]);
       
    printf("\n");
    return 0;
}


