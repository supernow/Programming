#include <stdio.h>
#include <stdlib.h>
#define N 6
struct A
{
    int a;
    int b;
};
int  range(struct A *p,int *position,int *mmax)
{
        int i;
        int imax=0;
 for(i=0;i<N;i++)
        {
            if(i==0&&p[i].b==-1)continue;
            if(i==N-1&&p[i].b==1)continue;
            if(p[i].a>p[i+p[i].b].a)
            {
                if(imax<p[i].a)
                {
                     imax=p[i].a;
                     *position=i;
                }


            }
        }
        *mmax=p[*position].a;
        if(imax>0)return 1;
        else return 0;
}
void exchange(struct A *p,struct A*q)
{
    struct A a;
    a=*p;
    *p=*q;
    *q=a;
}
void print(struct A *p)
{
    int i;
    for(i=0;i<N;i++)
    {
        printf(" %d",p[i].a);
    }
}
void adjust(struct A *p,int max)
{
    int i;
    for(i=0;i<N;i++)
    {



            if(p[i].a>max)p[i].b=-p[i].b;

    }
}
int main()
{
  struct A a[N];
  int i=0,position,mmax;
  for(i=0;i<N;i++)
  {
      a[i].a=i+1;
      a[i].b=-1;
  }
  print(a);
  int mmm=0;
  while(1)
  {
      int mmax=0;
      printf("\n");
      if(!range(a,&position,&mmax))break;
      exchange(&a[position],&a[position+a[position].b]);
      print(a);
      mmm++;
      adjust(a,mmax);


  }
  printf("%d",mmm+1);
}
