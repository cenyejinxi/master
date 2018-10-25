#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,g,h,i;
    for(a=1;a<10;a++)
    {
        for(b=1;b<10;b++)
        {while(a==b)b++;
            for(c=1;c<10;c++)
            {
                while(a==c or b==c)c++;
                for(d=1;d<10;d++)
                {
                    while(a==d or b==d or c==d)d++;
                    for (e=1;e<10;e++)
                    {
                        while(a==e or b==e or c==e or d==e)e++;
                        for(f=1;f<10;f++)
                        {
                            while(a==f or b==f or c==f or d==f or e==f)f++;
                            for(g=1;g<10;g++)
                            {
                                while(a==g or b==g or c==g or d==g or e==g or f==g)g++;
                                for(h=1;h<10;h++)
                                {
                                    while(a==h or b==h or c==h or d==h or e==h or f==h or g==h)h++;
                                    for(i=1;i<10;i++)
                                    {
                                        while(a==i or b==i or c==i or d==i or e==i or f==i or g==i or h==i)i++;
                                        //printf("%d%d%d%d%d%d%d%d%d\n",a,b,c,d,e,f,g,h,i);
                                        if(2*(100*a+10*b+c)==(100*d+10*e+f) and 3*(100*a+10*b+c)==(100*g+10*h+i))
                                        {
                                            printf("%d %d %d\n",(100*a+10*b+c),(100*d+10*e+f),(100*g+10*h+i));
                                        };
                                    };
                                };
                            };
                        };
                    };
                };
            };
        };
    };
    return 0;
}
