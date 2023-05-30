#include "main.h"

int initAnimal(classPtr* classArray) {
    FILE* animalFile = fopen("zoo.csv", "r");
    if (animalFile == NULL) {
        printf("The file can't be opened.");
        exit(0);
    }

    char feature[MAX_CHAR];
    char* featureList[MAX_FEATURE];
    char line[MAX_CHAR];

    fgets(feature, sizeof(line), animalFile);
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
    while (fgets(line, sizeof(line), animalFile) != NULL) {
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
            else if (cnt == 17)
                temp->classIdx = atoi(token);

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
                }

                else if (atoi(token) == 0) {
                    currNode->ownFlag = 0;
                    if (noNode == NULL) {
                        noNode = currNode;
                    }
                    else if (noNode != NULL) {
                        noNode->leftChild = currNode;
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
        //class number -1이 class 정보가 있음
        
        if ((classArray[temp->classIdx-1]->inAnimal) == NULL) {
            classArray[temp->classIdx-1]->inAnimal = temp;
        }

       else if ((classArray[temp->classIdx-1]->inAnimal) != NULL) {
            animalPtr currentPtr = classArray[temp->classIdx-1]->inAnimal;
            animalPtr prevPtr = NULL;
            for (currentPtr, prevPtr; currentPtr != NULL;) {
                prevPtr = currentPtr;
                currentPtr = currentPtr->nextAnimal;
            }
            prevPtr->nextAnimal = temp;
        }
    }
    
    fclose(animalFile);
    return 0;
}

int freeNodes(featurePtr freeNode) {
    if (freeNode == NULL) {
        return 0;
    }
    /*
    * if (freeNode->leftChild != NULL)
        freeNodes(freeNode->leftChild);
    */
    
    if (freeNode->rightChild != NULL)
        freeNodes(freeNode->rightChild);

    free(freeNode->featureName);
    free(freeNode);
    return 0;
}

int freeAnimal(classPtr* classArray) {

    for (int i = 0; i < MAX_CLASS; i++) {
        if (classArray[i] != NULL) {
            animalPtr tempAnimal = classArray[i]->inAnimal;
            animalPtr deleteAnimal=NULL;
            featurePtr tempFeature=NULL;
            while (tempAnimal != NULL) {
                tempFeature = tempAnimal->featureFirst;
                if (tempFeature != NULL) {
                    freeNodes(tempFeature);
                }
                deleteAnimal = tempAnimal;
                tempAnimal = tempAnimal->nextAnimal;
                free(deleteAnimal->animalName);
                free(deleteAnimal);
            }
        }      
    }
    return 0;
}