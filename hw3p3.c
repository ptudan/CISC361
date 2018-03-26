//Paul Tudan
//CISC361 HW3
//3-24-18

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>
#include <sys/semaphore.h>

sem_t semaphore;
int t = 0;


void tellerCheckIn(){
	sem_post(&semaphore);
}

void tellerCheckOut(){
	sem_wait(&semaphore);
}

void DoBanking(){
	sem_wait(&semaphore);
	sleep(3000);
	FinishBanking();
}

void FinishBanking(){
	sem_post(&semaphore);
}

int main(int argc, char *argv[]){
	printf("Hello, and welcome to The Bank of Operating Systems \n");
	sem_init(&semaphore, 0, 0);
	for(int i = 0; i<5; i++) tellerCheckIn();
	srand(time(NULL));
	while(t<100){
		int r = rand()%10;
		if(r == 2) tellerCheckOut();
		else if(r == 4) tellerCheckIn();
		else if(r >7 ) DoBanking();
	}




}