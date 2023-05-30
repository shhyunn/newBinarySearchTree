#include "main.h"

void insertClass(classPtr* classArray) {
    FILE* insertClassFile = fopen("classInsert.csv", "r");
    if (insertClassFile == NULL) {
        printf("The file can't be opened.");
        exit(0);
    }
    char line[MAX_CHAR];
    fgets(line, sizeof(line), insertClassFile);
    int idx;
    int cnt;
    int classNum;
    char* className = NULL;
    while (fgets(line, sizeof(line), insertClassFile) != NULL) {
        cnt = 0;
        for (char* token = strtok(line, ","); token != NULL; token = strtok(NULL, ",")) {
            if (cnt == 0) {
                classNum = atoi(token);
            }
            else if (cnt == 2) {
                className = strdup(token);
            }
            cnt += 1;
        }

        for (idx = 0; idx < MAX_CLASS; idx++) {
            if (classArray[idx] == NULL && idx == classNum-1) {
                classArray[idx] = (classPtr)malloc(sizeof(Class));
                classArray[idx]->classNum = classNum;
                classArray[idx]->className = className;
                classArray[idx]->inAnimal = NULL;
            }
        }
    }
    fclose(insertClassFile);
}

void insertAnimal(classPtr* classArray) {
    FILE* insertAnimalFile = fopen("insert.csv", "r");
    if (insertAnimalFile == NULL) {
        printf("The file can't be opened.");
        exit(0);
    }
    char feature[MAX_LINE];
    char* featureList[MAX_FEATURE];
    char line[MAX_LINE];
    fgets(feature, sizeof(line), insertAnimalFile);
    int idx = 0;
    int iidx = 0;
    for (char* token = strtok(feature, ","); token != NULL; token = strtok(NULL, ",")) {
        if (!(idx == 0 || idx == 13 || idx == 17)) {
            featureList[iidx] = token;
            iidx += 1;
        }
        idx += 1;
    }

    for (iidx; iidx < MAX_FEATURE; iidx++) {
        featureList[iidx] = NULL; //null포인터로 초기화
    }

    int cnt; int featureIdx;
    while (fgets(line, sizeof(line), insertAnimalFile) != NULL) {
        animalPtr temp = (animalPtr)malloc(sizeof(Animal));
        cnt = 0;
        featureIdx = 0;

        featurePtr rootNode = (featurePtr)malloc(sizeof(Feature));
        featurePtr currNode = rootNode;
        featurePtr prevNode = NULL;
        featurePtr yesNode = NULL;
        featurePtr noNode = NULL;

        for (char* token = strtok(line, ","); token != NULL; token = strtok(NULL, ",")) {
            if (cnt == 0)
                temp->animalName = strdup(token);
            else if (cnt == 17) {
                temp->classIdx = atoi(token);
            }
            else if (cnt != 13) {
                currNode->leftChild = NULL;
                currNode->rightChild = NULL;

                if (atoi(token) == 1) {
                    currNode->ownFlag = 1;
                    if (yesNode == NULL) {
                        yesNode = currNode;
                    }
                    else if (yesNode != NULL) {
                        yesNode->leftChild = currNode;
                        yesNode = currNode;
                    }
                    //currNode->leftChild = rootNode;

                }
                else if (atoi(token) == 0) {
                    currNode->ownFlag = 0;
                    if (noNode == NULL) {
                        noNode = currNode;
                    }
                    else if (noNode != NULL) {
                        noNode->rightChild = currNode;
                        noNode = currNode;
                    }
                }

                currNode->featureName = strdup(featureList[featureIdx]);
                featureIdx += 1;

                if (prevNode != NULL) {
                    prevNode->rightChild = currNode;
                }

                prevNode = currNode;
                currNode = (featurePtr)malloc(sizeof(Feature));
            }
            cnt += 1;

        }

        temp->featureFirst = rootNode;
        temp->nextAnimal = NULL;
        if ((classArray[temp->classIdx - 1]->inAnimal) == NULL) {
            classArray[temp->classIdx - 1]->inAnimal = temp;
        }


        else if ((classArray[temp->classIdx - 1]->inAnimal) != NULL) {
            animalPtr currentPtr = classArray[temp->classIdx - 1]->inAnimal;
            animalPtr prevPtr = NULL;
            for (currentPtr, prevPtr; currentPtr != NULL;) {
                prevPtr = currentPtr;
                currentPtr = currentPtr->nextAnimal;
            }
            prevPtr->nextAnimal = temp;
        }
    }
    fclose(insertAnimalFile);
}