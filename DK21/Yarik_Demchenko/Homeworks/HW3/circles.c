#include <stdio.h>
#include <stdlib.h>
#include "circles.h"
#include "circle.h"
#include <string.h>

int extendArrayOfCircles(ArrayOfCircles *anArray);

ArrayOfCircles *createArrayOfCircles(int aReserved) {
    ArrayOfCircles *result = (ArrayOfCircles *)malloc(sizeof(ArrayOfCircles));
	if (NULL != result) {
		result->preservedCount = (aReserved > 0) ? aReserved : 2;
		result->count = 0;
		result->storage = (Circle **)malloc(sizeof(Circle *) * (long long unsigned int)result->preservedCount);

		if (NULL == result->storage) { // if failed to alloc memory for internal storage
			free(result);
			return NULL;
		} else {
			//bzero(result->storage, sizeof(Point *) * result->preservedCount);
			memset(result->storage, 0, sizeof(Circle *) * (long long unsigned int)result->preservedCount);
		}
	}
	return result;
}

void destroyArrayOfCircles(ArrayOfCircles *anArray) {
    if (NULL == anArray) {
		return ;
	}

	free(anArray->storage);
	free(anArray);
}

int addCircle(ArrayOfCircles *anArray, Circle *aCircle) {
    if (NULL == anArray) {
		return -1;
	}

	if (anArray->count == anArray->preservedCount) {
		if (0 != extendArrayOfCircles(anArray)) {
			return -1;
		}
	}

	anArray->storage[anArray->count] = aCircle;
	anArray->count++;
    return anArray->count-1;
}

int addCircleByCoords(ArrayOfCircles *anArray, int cx, int cy, int cr) {
    if (NULL == anArray) {
		return -1;
	}

	if (anArray->count == anArray->preservedCount) {
		if (0 != extendArrayOfCircles(anArray)) {
			return -1;
		}
	}

    Circle *aCircle = createCircle(cx, cy, cr);
    if (NULL == aCircle) {
		return -1;
	}

	anArray->storage[anArray->count] = aCircle;
	anArray->count++;
    return anArray->count-1;
}

int addCircleAtIndex(ArrayOfCircles *anArray, Circle *aCircle, int index) {
    if (NULL == anArray) {
		return -1;
	}
    if(index < 0) {
        return -1;
    }

    if (index < anArray->count) {
        Circle *toDelete = anArray->storage[index];
        anArray->storage[index] = aCircle;
        destroyCircle(toDelete);
        return 0;
    }
    addCircle(anArray, aCircle);
    return 0;
}

Circle *getCircleAt(ArrayOfCircles *anArray, int aIndex) {
    if (NULL == anArray || aIndex >= anArray->count) {
		return NULL;
	}

	return anArray->storage[aIndex];
}

void printArrayOfCircles(ArrayOfCircles *anArray) {
    if (NULL == anArray) {
		return;
	}
    printf("[");
	for (int i = 0; i < anArray->count; i++) {
		printCircle(anArray->storage[i]);
        printf("; ");
	}
    printf("]\n");
}

int countArrayOfCircles(ArrayOfCircles *anArray) {
    return (NULL != anArray) ? anArray->count : -1;
}

int extendArrayOfCircles(ArrayOfCircles *anArray) {
	if (NULL == anArray) {
		return 1; //Bad input parameters
	}

	anArray->preservedCount *= 2;
	Circle **local = (Circle **)malloc(sizeof(Circle *) * (long long unsigned int)anArray->preservedCount);

	if (NULL == local) {
		return 2; //Couldn't create local
	}

	memcpy(local, anArray->storage, (long long unsigned int)anArray->count * sizeof(Circle *));
	free(anArray->storage);
	anArray->storage = local;
	return 0;
}
