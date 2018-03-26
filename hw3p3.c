//Paul Tudan
//CISC361 HW3
//3-24-18

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <windows.h>
#include <semaphore.h>

sem_t semaphore;
int t = 0;


void tellerCheckIn(){
	printf("Teller Checked in \n");
	sem_post(&semaphore);
}

void tellerCheckOut(){
	sem_wait(&semaphore);
}

void FinishBanking(){
	sem_post(&semaphore);
	int r = rand()%15;
	if(r==14){
		printf("That customer was so bad im taking my smoke break \n");
		tellerCheckOut();
	}
}

void DoBanking(){
	sem_wait(&semaphore);
	//sleep(1);
	printf("Banking done \n");
	FinishBanking();
}

int main(int argc, char *argv[]){
	printf("Hello, and welcome to The Bank of Operating Systems \n");
	sem_init(&semaphore, 0, 0);
	for(int i = 0; i<5; i++) tellerCheckIn();
	srand(time(NULL));
	while(t<100){
		int r = rand()%10;

		if(r == 4) tellerCheckIn();
		else if(r == 2) tellerCheckOut();
		else if(r >7 ) DoBanking();
		t++;
	}




}