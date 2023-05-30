#include "main.h"

void readClass(classPtr* classArray) {
	int idx;
	for (idx = 0; idx < MAX_CLASS; idx++) {
		if (classArray[idx] != NULL) {
			printf("classnum: %d, class animal: %s\n", classArray[idx]->classNum, classArray[idx]->className);
		}
	}
}

void readAnimal(classPtr* classArray) {
	int idx;
	classPtr tempClass;
	animalPtr tempAnimal;
	for (idx = 0; idx < MAX_CLASS; idx++) {
		if (classArray[idx] != NULL) {
			tempClass = classArray[idx];

			printf("class number : %d, animal name: %s", tempClass->classNum, tempClass->className);
			tempAnimal = tempClass->inAnimal;
			while (tempAnimal != NULL) {
				printf("%s ", tempAnimal->animalName);
				tempAnimal = tempAnimal->nextAnimal;
			}
			printf("\n");
		}
	}
}

/*
void readFeature(classPtr* classArray) {
	
}
*/