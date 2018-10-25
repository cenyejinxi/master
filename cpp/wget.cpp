#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>
#define HOST "coding.debuntu.org" 
#define PORT 80
#define USERAGENT "HTMLGET 1.0"
#define SIBUF 4096

pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;
char fil[20];
int count = 0;
float  count1 = 0;
char *host;
char *page;
char *ip;

struct sock
{
    int sock;
    int num;
    int sum;

};
/*????*/
int itos(int n,char *s)
{
    int i;

    if(n<10)
    {
        *s=n+'0';
        i=1;
    }
    else
    {
        i=itos(n/10,s);
        *(s+i++)=n%10+'0';
    }
    *(s+i)='\0';
    return i;
}
int stonum(char *string)
{
    int n=0,i;

    if(*string=='-')
        i=-1;
    else
        i=1;
    while(!(*string>='0'&&*string<='9'))
        string++;
    while(*string>='0'&&*string<='9')
    {
        n*=10;
        n+=*string-'0';
        string++;
    }
    return n*i;
}
/*????page*/
char *char_page(char *s1,char s3[1024])
{
    int i = 0;
    while(strncmp(s1, "http://",7) != 0)
    {
        s1++;
    }
    s1 = s1 + 7;
    while(strncmp(s1,"/",1) != 0)
    {
        s1++;
    }
    while(*s1 != '\0')
    {

        s3[i++] = *s1;
        s1++;
    }
    return s3;
}

/*????host*/
char *char_host(char *s1,char s2[1024])
{
    int i = 0;
    memset(s2,0,1024);
    while(strncmp(s1,"http://",7) != 0)
    {
        s1++;
    }
    s1 = s1 + 7;
      while(*s1 != '/')
    {
        s2[i++] = *s1;
        s1++;
    }
    return s2;
}

/*??ip??*/
char*  get_ip()
{
    struct hostent *hent;
    int iplen = 15;
    unsigned char *hip;
    char *ip = (char *) malloc (iplen + 1);

    memset(ip, 0, iplen + 1);
    if((hent = gethostbyname (host)) == NULL)
    {
        herror("can't ip\n");
        exit(1);

    }
    hip = (unsigned char *)hent->h_addr_list[0];

    sprintf(ip,"%u.%u.%u.%u",hip[0],hip[1],hip[2],hip[3]); 

    return ip;
}

/*??????*/
struct sockaddr_in* my_struct(struct sockaddr_in *fb,char *ip)

{
    int tmp;
    fb = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));

    bzero(fb, sizeof(*fb));
    fb->sin_family = AF_INET;
    tmp = inet_pton(AF_INET,ip,(void *)&(fb->sin_addr.s_addr));

    fb->sin_port = htons(PORT);
    return fb;
}

/*?????*/
int create_socket(void)
{
    int sockfb;
    if((sockfb = socket(AF_INET,SOCK_STREAM,0)) < 0)
        perror("socket error\n");
    return sockfb;     
}

/*????*/
int create_connect(int sockfb,struct sockaddr_in *fb)
{

    if((connect(sockfb, (struct sockaddr *)fb, sizeof(struct sockaddr))) < 0)
    {
        perror("can't connect");
        exit(1);

    }
    return sockfb;
}

/*??????*/
char *creat_req_head()
{
    char *req;
    char *getpage = page;
    char *tp = "HEAD /%s HTTP/1.0\r\nHost: %s\r\nUser-Agent: %s\r\n\r\n";
    if(getpage[0] == '/')
    {
        getpage = getpage + 1;

    }
    req = (char *) malloc (strlen(host) + strlen(getpage) + strlen(USERAGENT) + strlen(tp) - 7) ;


    sprintf(req,tp,getpage,host,USERAGENT); //????HEAD?????req?


    return req;
}

/*??????*/
char *creat_requset(char *ange)
{
    char *req;
    char *getpage = page;
    char *tp = "GET /%s HTTP/1.0\r\nHost: %s\r\nUser-Agent: %s\r\nRange: %s\r\n\r\n";
    if(getpage[0] == '/')
    {
        getpage = getpage + 1;

    }
    req = (char *) malloc (strlen(host) + strlen(getpage) + strlen(USERAGENT) + strlen(ange) + strlen(tp) - 7) ;

    sprintf(req,tp,getpage,host,USERAGENT,ange); //????????????req?

    return req;
}
/*????*/  
int my_send(char *get,int sockfb)
{
    int set = 0;
    int tmp;

    while(set < strlen (get))
    {
        tmp = send(sockfb,get + set,strlen(get) - set,0);
        if(tmp == -1)
        {
            printf("can't sent \n"); 
            exit(1);
        }
        set += tmp; 
    }
    
    return sockfb;
}

/*????HEAD*/
char* my_recv_head(int sockfb,char* buf1)
{
    char buf[SIBUF];
    char *content;
    int tmp;
    int i = 0;
    int j = 0;
    memset(buf,0,strlen(buf));
    if( (tmp = recv (sockfb, buf,1024,0)) > 0)
    {
        content = buf;
        while (strncmp(content,"Content-Length: ",16) != 0)
        {
            j++;    
            content++;
            if(j > 1024)
            {
                printf("no duo  xiancheng!!!!!!!!!!!!!!!\n"); 
            //    break;
                    return NULL;
            }
        }
        content = content + 16;
        while(strncmp(content,"\n",1) != 0)
        {
            buf1[i++] = *content;
            printf("%c",*content); 
            content++;

        }
        printf("\n\n"); 
        memset(buf,0,strlen(buf)); 
    }
    if(tmp < 0)
    {
        perror("error receiving data\n"); 
    }
    //fclose(bf);
    return buf1;
}
/*?????,???,??????*/
void* process(float count1,int sum1)
{
    int k,k1;
    float j = 0;
    int count2;
    int i;
    j = count1/sum1;
    k  = j*100;
    printf("    [                         ]            %d%%\r",k);
    count2 = count1;
    printf("    [                         ]    %6d/%6d\r",count2,sum1);//\r?????????? 
    for(i = 0; i < k; i++)
    {
        printf("    ["); 
        for(k1 = -1; k1 <  k/10; k1++ )
        {
            printf("=>=>"); 
        }
        printf("\r"); 
    }

    fflush(stdout);
    sleep(3);
    return;
}
/*????*/
int  my_recv(int sockfb,int n,int sum1)
{
    char buf[SIBUF];
    int start = 0;
    char *content;
    int tmp;
    int count2;

    FILE *bf;
    int num = 0;
    int i;
    float j = 0;
    int k;
    int k1;
    bf = fopen(fil,"r+");
    fseek(bf,n,SEEK_SET);
    memset(buf,0,SIBUF);
    while( (tmp = recv (sockfb, buf,1024,0)) > 0)
    {
//        printf("buf>>>%s\n",buf); 
        if(start == 0)
        {
            content = buf;
            i = 0;
            while (strncmp(content,"\r\n\r\n",4) != 0)
            {
                i++;
                content++;
            }
            if(content != NULL)
            {
                start = 1;
                content = content + 4;
            }
            else
            {
                printf("content errror\n"); 
                return ;
            }
        }
        else
        {
            content = buf;
        }
        if(start == 1)
        {
            fwrite(content,(tmp -i - 4) ,1,bf);
            start = 2;
            count1 = count1 +(tmp -i -4);
        }
        else
        {
            fwrite(content,tmp,1,bf);
            count1 = count1 + tmp;
        }
    //    printf("count1==%f\n",count1); 
        process(count1,sum1);
    }
    printf("11111111111111111111111111\n"); 

    if(tmp < 0)
    {
        perror("error receiving data\n"); 
    }
    else
    {
        return;
    }

//    fclose(bf);
}

/*????*/
void *pthread(void*args)
{
    struct sockaddr_in *fb1;
    int n1,n2;
    char *q ="bytes=%d-%d";
    char *p ="bytes=%d-/";
    char *ange;
    char *get;
    int sockfb1;
    int number;
    int sum1;
    char s1[1024],s2[1024];
    struct sock *args1;
    args1 = (struct sock*)args;

    number = args1->num;
    sum1 = args1->sum;
    /*?????*/
    sockfb1 = create_socket();

    /*??????*/
    fb1 = my_struct(fb1,ip);

    /*????*/
    sockfb1 = create_connect(sockfb1,fb1);
free(fb1);

    /*??*/
    pthread_mutex_lock(&my_mutex);
    n1 = count*number;    
    count++;
    n2 = count*number;
    n2 = n2 - 1;            //??????????????
    pthread_mutex_unlock(&my_mutex);

     itos(n1,s1);
    itos(n2,s2);
    if((sum1 - n1) < number*2 )
    {
        memset(s2,0,sizeof(s2));
        n2 = sum1 - 1;
        itos(n2,s2);
        ange = (char *)malloc(strlen(s1) + strlen(s2) + strlen(q) - 3);
        sprintf(ange,q,n1,n2);         //q?“bytes = s1-s2”;
    }
    else
    {

        ange = (char *)malloc(strlen(s1) + strlen(s2) + strlen(q) - 3);
        sprintf(ange,q,n1,n2);
    }

    get = creat_requset(ange);
    printf("get>>>>>>>>>>>>>>>>%s\n",get); 
    sockfb1 = my_send(get,sockfb1);

    sockfb1 = my_recv(sockfb1,n1,sum1);

free(get);
//    close(sockfb1);
    return ;
}
/*????????*/
int find_sum_number(int number)
{    struct sockaddr_in *fb;
    char *get1, *p;
    int sockfb;
    char s1 [1024] = "\0", s2[1024], s3[1024];
    char buf2[1024];
    printf("please input  host page :\n"); 
    scanf("%s",s1);

    /*????????????*/
    host = char_host(s1,s2);
    page = char_page(s1,s3);

    printf("host== %s\npage == %s\n",host,page); 
    /*?????*/
    sockfb = create_socket();

    /*??IP??*/
    ip = get_ip();
    printf("IP >>>>>    %s\n",ip); 

    /*??????*/
    fb = my_struct(fb,ip);

    /*????*/
    sockfb = create_connect(sockfb,fb);
    printf("sockfb ==%d\n",sockfb); 
free(fb);

    /*?????????*/
    printf("please input filename:\n");
    scanf("%s",fil);
    fopen(fil,"w+");


    /*??????*/
    get1 = creat_req_head();
    printf("Query HEAD is \n<<START>>\n%s<<END>>\n",get1);

    /*????????????*/
    sockfb = my_send(get1,sockfb);
    printf("get1111111111111>>>>>>>%s\n",get1); 
free(get1);

    /*?????????????*/
    p = my_recv_head(sockfb,buf2);
    if(p == NULL)
        return ;
    strcpy(buf2,p);
    number = stonum(buf2);

    printf("?????===%d\n",number);

close(sockfb);
    return number;
}

int main(int argc,char *argv[]) 
{
    int num;    
    pthread_t pt[100];
    int err;
    struct sock args;
    int len;
    int i;
    num = find_sum_number(num);
    printf("???????????:\n"); 
    scanf("%d",&len);

    /*?????????*/
    args.num = num/len;
    args.sum = num;            //?????

    /*????*/
    pthread_mutex_init(&my_mutex,NULL);
    for(i = 0; i < len;i++)
    {
        err = pthread_create(&pt[i],NULL,(void *)pthread,&args);
        if(err != 0)
        {
            printf("can't create pthread %d\n",strerror); 
        }
    }
    void *ret;
    for(i = 0;i<len;i++)
    {
        pthread_join(pt[i],&ret);
    }
    free(ip);
    
    printf("\n????\n"); 

    return 0;

}
