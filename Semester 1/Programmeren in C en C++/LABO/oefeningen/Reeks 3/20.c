#include <stdio.h>


int main(){
	int t[6] = {0,10,20,30,40,50};
	int* pt[3];
	int i;
	for(i=0; i<3; i++){
		//pt = [ 0 | 20 | 40 ]
		pt[i] = &t[2*i];
	}

	pt[1]++; //pt = [ 0 | 30 | 40 ]
	pt[2] = pt[1]; //pt = [ 0 | 30 | 30 ]
	*pt[1] += 1; // t[ = [0 | 10 | 20 | 31 | 40 | 50] ; pt = [ 0 | 31 | 31 ]
	*pt[2] *= 2; // t[ = [0 | 10 | 20 | 62 | 40 | 50] ; pt = [ 0 | 62 | 62 ]
	int ** ppt = &pt[0]; // ppt = 0
	(*ppt)++; // pt = [ 10 | 62 | 62 ]
	**ppt += 1; // t = [ 0 | 11 | 20 | 62 | 40 | 50 ] ; pt = [ 11 | 62 | 62 ]
	for(i=0; i<6; i++){
		printf("%d ",t[i]);
	}
	printf("\n");
	for(i=0; i<3; i++){
		printf("%d ",*pt[i]);
	}
	printf("\n");
	return 0;
}