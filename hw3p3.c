//Paul Tudan
//CISC361 HW3
//3-24-18

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/semaphore.h>
#define NUM 10
int maxTellers = NUM;
int workingTellers = 0;
int freeTellers = 0;
int customersWaiting = 0;
int time = 0;
int tellerIDs[NUM];
pthread_t tellers[NUM];
sem_t semaphores[NUM];

void* tellerThread(void* arg){
	//performs simple bubble sort based on rank of process
	int * tellerID = (int*) arg;

    return NULL;
}


int main(int argc, char *argv[]){
	printf("Hello, and welcome to The Bank of Operating Systems \n");
	for(int i=0; i<NUM; i++) sem_init(semaphores + i, 0, 0);
	for(int i=0; i<NUM; i++) tellerIDs[i] = i;
	for (int i=0; i<NUM; i++) pthread_create(tellers + i, NULL, tellerThread, tellerIDs + i);


}