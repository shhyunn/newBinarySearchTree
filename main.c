#include "main.h"
#include <time.h>
#define NUM_RUNS 10

int main(void) {
	classPtr* classArray = initClass();
	initAnimal(classArray);

	insertClass(classArray);
	insertAnimal(classArray);

	deleteClass(classArray, 6);
	deleteAnimal(classArray, "bear");

	searchClass(classArray, 2);
	searchAnimal(classArray, "hamster");
	int i;
	double executionTimes1[NUM_RUNS];
	double executionTimes2[NUM_RUNS];
	char* featureName = { "antelope","chicken","dogfish","giraffe","penguin","ostrich","raccoon","seal","toad","wolf" };
	
	for (i = 0; i < NUM_RUNS; i++) {
		clock_t start, end;
		double cpu_time_used;

		start = clock();
		featureSearch1(classArray, featureName[i]);
		end = clock();

		cpu_time_used((double)(end - start)) / CLOCKS_PER_SEC;
		excutionTimes1[i] = cpu_time_used;
	}

	for (i = 0; i < NUM_RUNS; i++) {
		clock_t start, end;
		double cpu_time_used;

		start = clock();
		featureSearch2(classArray, featureName[i]);
		end = clock();

		cpu_time_used((double)(end - start)) / CLOCKS_PER_SEC;
		excutionTimes2[i] = cpu_time_used;
	}
	  
	int j;
	printf("featureSearch1");
	for (j = 0; j < NUM_RUNS; j++) {
		printf("%f ", executionTimes1[j]);
	}

	printf("featureSearch2");
	for (j = 0; j < NUM_RUNS; j++) {
		printf("%f ", executionTimes2[j]);
	}


	readClass(classArray);
	readAnimal(classArray);
	
	/*
	* for (int i = 0; i < 7; i++) {
		featurePtr feature = classArray[i]->classAnimal->featureFirst;
		printf("feature name: %s\n", feature->featureName);
	}
	*/
	
	freeAnimal(classArray);
	freeClass(classArray);
	return 0;
}