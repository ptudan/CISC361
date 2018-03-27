//Paul Tudan
//CISC361 HW3
//3-26-18

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <windows.h>
#define N 5 //num philosophers
#define THINKING 0
#define HUNGRY 1
#define EATING 2
int states[N];
pthread_cond_t conds[N];
pthread_mutex_t mutex;

void think(int p);
void pickup_forks(int p);
void return_forks(int p);



//228 has code
//252 has problem

void* philoThread(void* arg){
	//philosopher thread
	int p = *((int*) arg);
	think(p);
	int count = 0;
	while(count<100){
		int r = rand()%5;
		if(r <4) think(p);
		else pickup_forks(p);
		count++;
	}

}

void think(int p){
	states[p] = THINKING;
	sleep(1+rand()%3);
}

void pickup_forks(int p){
	int left, right;
	if(p == 0)left = N -1;
	else left = p-1;

	if(p == N-1) right = 0;
	else right = N+1;

	states[p] = HUNGRY;
	pthread_mutex_lock(&mutex);
	while(!(states[left]==THINKING)&&(states[right])==THINKING){
		pthread_cond_wait(&conds[p], &mutex);
	}
	return_forks(p);
	pthread_mutex_unlock(&mutex);
	states[p] = THINKING;


}


void return_forks(int p){
	int left, right;
	if(p == 0)left = N -1;
	else left = p-1;

	if(p == N-1) right = 0;
	else right = N+1;

	sleep(1+rand()%3);
	printf("Philosopher %d has eaten \n", p);

	pthread_cond_signal(&conds[left]);
	pthread_cond_signal(&conds[right]);

}


int main(int argc, char *argv[]){
	printf("start\n");
	srand(time(NULL));
	pthread_mutex_init(&mutex, NULL);
	for(int i = 0; i<N; i++) pthread_cond_init(conds+i, NULL);
	int pids[N];
	pthread_t phis[N];
	for(int i = 0; i<N; i++)pids[i] = i;

	for(int i = 0; i<N; i++)pthread_create(phis + i, NULL, philoThread, pids + i);
    for(int i = 0; i<N; i++) pthread_join(phis[i], NULL);

}