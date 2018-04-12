#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

int vehicle;
#define MAX_VEHICLE 25

int enter=0;

struct direction
{
  int vid,origin,destination;
};

struct direction object[MAX_VEHICLE];
void *intersection(void *args)
{

   	struct direction *obj=args;
   	int i;
 	for(i=1;i<=vehicle;i++)
	{
	printf("\n\n********** Vehicle %d and %d Enters into the intersection **********",i,i+1);
	if(obj[i].origin==obj[i+1].destination && obj[i].destination==obj[i+1].origin)
    	{
      	printf("\nOK To pass the vehicles(%d and %d) through intersection: ",i,i+1);
    	}
    	else if(obj[i].origin==obj[i+1].origin)
    	{
      	printf("\nOK To pass the vehicles through intersection: ");
    	}
    	else if(obj[i].destination!=obj[i+1].destination)
    	{
      	switch(obj[i].origin)
      	{
        case 0:
          printf("\nvehicle %d take right turn ie goes to east to north",i);
          break;
          case 1:
          printf("\nvehicle %d take right turn ie goes to west to south",i);
          break;
        case 2:
          printf("\nvehicle %d take right turn ie goes to north to west",i);
          break;
        case 3:
          printf("\nvehicle %d take right turn ie goes to south to east",i);
          break;
      }
      switch(obj[i+1].origin)
      {
        case 0:
          printf("\nvehicle %d take right turn ie goes to east to north",i+1);
          break;
          case 1:
          printf("\nvehicle %d take right turn ie goes to west to south",i+1);
          break;
        case 2:
          printf("\nvehicle %d take right turn ie goes to north to west",i+1);
          break;
        case 3:
          printf("\nvehicle %d take right turn ie goes to south to east",i+1);
          break;
      }
    }i++;
}
}
enum dir{East=0,West=1,North=2,South=3};
void *genrateVehicle(void *vehicleInfo)
{
  struct direction *obj=vehicleInfo;
  int a,b;
  while(1)
  {
    a=rand()%4;
    b=rand()%4;
    if(a!=b)
    break;
  }
  obj->origin=a;
  obj->destination=b;
  
    printf("\nvehicle %d goes from %d ----> %d\n\n",obj->vid,obj->origin,obj->destination);
    //intersection((void*)(obj->vid));
}
int main()
{
  printf("\n\n***** TRAFIC INTERSECTION PROBLEM *****\n\n");
  printf("East : 0\nWest : 1\nNorth : 2\nSouth : 3\n");
  printf("\nEnter Number of vehicle in a traffic : ");
  scanf("%d",&vehicle);
  pthread_t vehicle_id[vehicle];
  struct direction object[vehicle];
  pthread_t inter;
	int temp=0;  
pthread_mutex_t l; 
if(temp==0)
	{
//pthread_mutex_lock(&l);
int i;
 for(i=1;i<=vehicle;i++)
  {
    object[i].vid=i;
    pthread_create(&vehicle_id[i],NULL,genrateVehicle,(void*)&object[i]);
  }
	
  for(i=1;i<=vehicle;i++)
  {
    pthread_join(vehicle_id[i],NULL);
  }
//pthread_mutex_unlock(&l);
temp+=1;
}
if(temp+=1)
{
//pthread_mutex_lock(&l);
pthread_create(&inter,NULL,intersection,&object);
  pthread_join(inter,NULL);
//pthread_mutex_unlock(&l);
}
 
  return 0;
}
