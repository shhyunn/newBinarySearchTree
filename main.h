#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define MAX_CLASS 10
#define MAX_LINE 200
#define MAX_CHAR 500
#define MAX_FEATURE 20
#define MAX_LENGTH 20
#define MAX_NUM 20




#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct classNode Class;
typedef Class* classPtr;
typedef struct animalNode Animal;
typedef Animal* animalPtr;
typedef struct featureNode Feature;
typedef Feature* featurePtr;

struct classNode {
    char* className;
    int classNum;
    animalPtr inAnimal;
};

struct animalNode {
	char* animalName;
	int classIdx;
	featurePtr featureFirst;
	animalPtr nextAnimal;
};

struct featureNode {
	char* featureName;
	featurePtr leftChild;
	featurePtr rightChild;
	int ownFlag;
};

//write
classPtr* initClass(void);
void freeClass(classPtr* classArray);
int initAnimal(classPtr* classArray);

int freeNodes(featurePtr freeNode);
int freeAnimal(classPtr* classArray);

//read
void readClass(classPtr* classArray);
void readAnimal(classPtr* classArray);
/*void readFeature(classPtr* classArray);
* void readYesFeature(classPtr* classArray);
* void readNoFeature(classPtr* classArray);
*/


//insert
void insertClass(classPtr* classArray);
void insertAnimal(classPtr* classArray);

//delete
void deleteClass(classPtr* classArray, int classNum);
void deleteAnimal(classPtr* classArray, char* animalName);

//search
void searchClass(classPtr* classArray, int classNum);
void searchAnimal(classPtr* classArray, char* animalName);
void featureSearch1(classPtr* classArray, char* animalName);
void featureSearch2(classPtr* classArray, char* animalName);