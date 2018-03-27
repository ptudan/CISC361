//Paul Tudan
//CISC361 HW3
//3-26-18

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <windows.h>
#define N 5 //num philosophers


void* philoThread(void* arg){
	//philosopher thread


}

int main(int argc, char *argv[]){
	int pids[N];
	pthread_t phis[N];
	for(int i = 0; i<N; i++)pids[i] = i;

	for(int i = 0; i<N; i++)pthread_create();
}