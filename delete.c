#include "main.h"
void deleteClass(classPtr* classArray, int classNum) {
    int idx;
    for (idx = 0; idx < MAX_CLASS; idx++) {
        if (idx == (classNum - 1) && classArray[idx] != NULL) {
            if (classArray[idx]->inAnimal != NULL) {
                animalPtr tempAnimal = classArray[idx]->inAnimal;
                animalPtr deleteAnimal;
                featurePtr tempFeature;
                while (tempAnimal != NULL) {
                    tempFeature = tempAnimal->featureFirst;
                    freeNodes(tempFeature);
                    deleteAnimal = tempAnimal;
                    tempAnimal = tempAnimal->nextAnimal;
                    free(deleteAnimal->animalName);
                    free(deleteAnimal);
                }

                free(classArray[idx]->className);
                free(classArray[idx]);
                printf("class data를 정상적으로 삭제하였습니다.");
            }   
        }
    }
}

void deleteAnimal(classPtr* classArray, char* animalName) {
   
    animalPtr resultAnimal = NULL;
    animalPtr tempAnimal = NULL;
    animalPtr prevAnimal = NULL;
    animalPtr deleteAnimal = NULL;
    animalPtr prevRes = NULL;
    featurePtr tempFeature = NULL;
    char* realName = NULL;
    int idx;
    int result = -1;

    for (idx = 0; idx < MAX_CLASS; idx++) {
        result = -1;
        if (classArray[idx] != NULL) {
            tempAnimal = classArray[idx]->inAnimal;
            while (tempAnimal != NULL) {
                realName = tempAnimal->animalName;
                if (strcmp(realName, animalName) == 0) {
                    resultAnimal = tempAnimal;
                    prevRes = prevAnimal;
                    result = idx;
                    break;
                }
                prevAnimal = tempAnimal;
                tempAnimal = tempAnimal->nextAnimal;
            }
        }
        tempAnimal = NULL;
        prevAnimal = NULL;
        realName = NULL;

    }

    if (resultAnimal != NULL) {
        if (prevRes == NULL) {
           deleteAnimal = classArray[result]->inAnimal;
           classArray[result]->inAnimal = resultAnimal;
           if (deleteAnimal != NULL)
               free(deleteAnimal);
        }

        else if (prevRes != NULL) {
            prevRes->nextAnimal = resultAnimal->nextAnimal;
            tempFeature = resultAnimal->featureFirst;

            if (tempFeature != NULL)
                freeNodes(tempFeature);

            if (resultAnimal->animalName != NULL) 
                free(resultAnimal->animalName);

            if (resultAnimal != NULL)
                free(resultAnimal);
        }
        printf("animal data를 정상적으로 삭제하였습니다.\n");
    }
    else {
        printf("삭제할 animal data가 없습니다.\n");
    }
}
 
    
