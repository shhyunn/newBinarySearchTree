#include "main.h"
void searchClass(classPtr* classArray, int classNum) {
    int idx;
    classPtr tempClass = NULL;
    classPtr resultClass = NULL;

 
    for (idx = 0; idx < MAX_CLASS; idx++) {
        if (classArray[idx] != NULL) {
            tempClass = classArray[idx];
            if (tempClass->classNum == classNum) {
                resultClass = tempClass;
                break;
            }
        }  
    }
    if (resultClass == NULL) {
        printf("class number %d에 해당되는 정보가 없습니다.\n", classNum);
    }
    else if (resultClass != NULL) {
        printf("class number: %d, class animal: %s\n", resultClass->classNum, resultClass->className);
    }
}

void searchAnimal(classPtr* classArray, char* animalName) {
    int idx;
    animalPtr resultAnimal = NULL;
    animalPtr animal = NULL;
    char* realName = NULL;
    for (idx = 0; idx < MAX_CLASS; idx++) {
        if (classArray[idx] != NULL && classArray[idx] -> inAnimal != NULL) {
            animal = classArray[idx]->inAnimal;
            while (animal != NULL) {
                realName = animal->animalName;
                if (strcmp(realName, animalName) == 0) {
                    resultAnimal = animal;
                    break;
                }
                animal = animal->nextAnimal;
            }
        }
    }
    
    if (resultAnimal == NULL) {
        printf("%s의 데이터가 없습니다.\n", animalName);
    }
    else if (resultAnimal != NULL) {
        printf("animal name: %s, class number: %d\n", resultAnimal->animalName, resultAnimal->classIdx);
    }
}

void featureSearch1(classPtr* classArray, char* animalName) {
    int idx;
    animalPtr resultAnimal = NULL;
    animalPtr animal = NULL;
    featurePtr tempFeature = NULL;
    featurePtr initFeature = NULL;
    char* realName = NULL;
    for (idx = 0; idx < MAX_CLASS; idx++) {
        if (classArray[idx] != NULL && classArray[idx]->inAnimal != NULL) {
            animal = classArray[idx]->inAnimal;
            while (animal != NULL) {
                realName = animal->animalName;
                if (strcmp(realName, animalName) == 0) {
                    resultAnimal = animal;
                    break;
                }
                animal = animal->nextAnimal;
            }
        }
    }

    if (resultAnimal != NULL) {
        int find = 0;
        initFeature = resultAnimal->featureFirst;
        tempFeature = initFeature;
        printf("feature of animal(own):");
        while (tempFeature != NULL) {
            if (tempFeature->ownFlag == 1) {
                printf("%s ", tempFeature->featureName);
                tempFeature = tempFeature->leftChild;
                find = 1;
            }
            if (!find) {
                tempFeature = tempFeature->rightChild;
            }
            
        }

        printf("\n");
        printf("feature of animal(own x):");
        tempFeature = initFeature;
        find = 0;
        while (tempFeature != NULL) {
            if (tempFeature->ownFlag == 0) {
                printf("%s ", tempFeature->featureName);
                tempFeature = tempFeature->leftChild;
                find = 1;
            }
            if (!find) {
                tempFeature = tempFeature->rightChild;
            } 
        }
        printf("\n");
    }
}

void featureSearch2(classPtr* classArray, char* animalName) {
    int idx;
    animalPtr resultAnimal = NULL;
    animalPtr animal = NULL;
    featurePtr tempFeature = NULL;
    featurePtr initFeature = NULL;
    char* realName = NULL;
    for (idx = 0; idx < MAX_CLASS; idx++) {
        if (classArray[idx] != NULL && classArray[idx]->inAnimal != NULL) {
            animal = classArray[idx]->inAnimal;
            while (animal != NULL) {
                realName = animal->animalName;
                if (strcmp(realName, animalName) == 0) {
                    resultAnimal = animal;
                    break;
                }
                animal = animal->nextAnimal;
            }
        }
    }

    if (resultAnimal != NULL) {
        initFeature = resultAnimal->featureFirst;
        tempFeature = initFeature;
        printf("feature of animal(own):");
        while (tempFeature != NULL) {
            if (tempFeature->ownFlag == 1) {
                printf("%s ", tempFeature->featureName);
            }
            tempFeature = tempFeature->rightChild;
        }

        printf("\n");
        printf("feature of animal(own x):");
        tempFeature = initFeature;
        while (tempFeature != NULL) {
            if (tempFeature->ownFlag == 0) {
                printf("%s ", tempFeature->featureName);
            }
            tempFeature = tempFeature->rightChild;
        }
        printf("\n");
    }
}