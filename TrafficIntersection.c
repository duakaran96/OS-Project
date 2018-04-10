#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <time.h>

pthread_mutex_t lock;

static int beg1,end1;
static int beg2,end2;

void *firstVehicle(int a[])
{  
   pthread_mutex_lock(&lock);
   switch(a[0])
   {
   	case 1:
   		printf("First Vehicle is starting from West\n");
   		break;
   	case 2:
   		printf("First Vehicle is starting from North\n");
   		break;
   	case 3:
   		printf("First Vehicle is starting from East\n");
   		break;
   	case 4:
   		printf("First Vehicle is starting from South\n");
   		break;
   }
   
  //printf("First Vehicle is starting from :%d\n",a[0]);
  switch(a[1])
  {
  	case 1:
   		printf("It has to go to West\n");
   		break;
   	case 2:
   		printf("It has to go to North\n");
   		break;
   	case 3:
   		printf("It has to go to East\n");
   		break;
   	case 4:
   		printf("It has to go to South\n");
   		break;
  }
  //printf("It has to go to :%d\n",a[1]);
  
   if(beg1==beg2 ||end1==end2)
    {
     printf("Vehicle2 enters critical section\n\n");
     sleep(1);
    }
    else if(beg1==end2 ||beg2==end1)
    {
      printf("Vehicle 2 enters critical section\n\n");
      sleep(1);
    }
    else if(beg1==beg2  ||end1!=end2)
   {
     printf("Vehicle 2 enters critical secition\n\n");
     sleep(1);
   }
    else{
         printf("Vehicle 1 and 2 collide\n ");  
      } 
   pthread_mutex_unlock(&lock);

}

void *secondVehicle(int a[])
{
    pthread_mutex_lock(&lock);
   
   switch(a[0])
   {
   	case 1:
   		printf("Second Vehicle is starting from West\n");
   		break;
   	case 2:
   		printf("Second Vehicle is starting from North\n");
   		break;
   	case 3:
   		printf("Second Vehicle is starting from East\n");
   		break;
   	case 4:
   		printf("Second Vehicle is starting from South\n");
   		break;
   }
   
  //printf("First Vehicle is starting from :%d\n",a[0]);
  switch(a[1])
  {
  	case 1:
   		printf("It has to go to West\n");
   		break;
   	case 2:
   		printf("It has to go to North\n");
   		break;
   	case 3:
   		printf("It has to go to East\n");
   		break;
   	case 4:
   		printf("It has to go to South\n");
   		break;
  }
    //printf("\nSecond Vehicle is starting from :%d\n",a[0]);
	//printf("It has to go to :%d\n",a[1]);

    if(beg1==beg2  ||end1==end2)
    {
       printf("Vehicle1 enters critical section\n\n");
       sleep(1);
    }
    else if(beg1==end2 || beg2==end1)
    {
      printf("Vehicle 1 enters critical section\n\n");
      sleep(1);
    }
    else if(beg1==beg2 ||end1!=end2)
    {
      printf("Vehicle 1 enters critical section\n\n");
      sleep(1);
    }
   else{
    printf("Vehicle 1 and Vehicle2 collide!!!");
   }

  pthread_mutex_unlock(&lock); 
}

int main()
{


  printf("\t\t\t______________________________\t\t\t\n\n");
  printf("\t\t\t Traffic Intersection Problem\t\t\t\n");
  printf("\t\t\t______________________________\t\t\t\n\n");
  
  printf("Here's an example demonstrating the traffic intersection.\nSteps have been taken in order to prevent collision.\n\n");
  //printf("Directions:::\nWest=1\nNorth=2\nEast=3\nSouth=4\n");
  
  int a[2]={0};
  
  //Assigning random directions
  while(a[0]==a[1])
  	{
    srand (time(NULL));
	a[0]=rand()%4+1;
	sleep(1);
	srand (time(NULL));
	a[1]=rand()%4+1;
}
  pthread_mutex_init(&lock,NULL);       
  pthread_t p,q;

  pthread_create(&p,NULL,firstVehicle,a);
  pthread_create(&q,NULL,secondVehicle,a);

  pthread_join(p,NULL);
  pthread_join(q,NULL);

}
