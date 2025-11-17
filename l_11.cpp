#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int passengerId;
    int items;
    double weight;
} Baggage;


int readPassengers(const char *filename, char names[][50], int maxCount) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Не вдалося відкрити файл пасажирів!\n");
        return 0;
    }

    int count = 0;
    while (fgets(names[count], 50, f) != NULL && count < maxCount) {

        names[count][strcspn(names[count], "\n")] = '\0';
        count++;
    }

    fclose(f);
    return count;
}


int readBaggage(const char *filename, Baggage *bags, int maxCount) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Не вдалося відкрити файл багажу!\n");
        return 0;
    }

    int count = 0;
    while (fscanf(f, "%d %d %lf", &bags[count].passengerId, &bags[count].items, &bags[count].weight) == 3) {
        count++;
        if (count >= maxCount) break;
    }

    fclose(f);
    return count;
}


void findPassengerWithMaxBaggage(const char *passengersFile, const char *baggageFile) {
    char passengers[100][50];
    Baggage bags[100];
    int passCount = readPassengers(passengersFile, passengers, 100);
    int bagCount = readBaggage(baggageFile, bags, 100);

    if (passCount == 0 || bagCount == 0) {
        printf("Недостатньо даних!\n");
        return;
    }


    int maxItems = 0;
    for (int i = 0; i < bagCount; i++) {
        if (bags[i].items > maxItems)
            maxItems = bags[i].items;
    }


    double minWeight = 1e9;
    int bestId = -1;

    for (int i = 0; i < bagCount; i++) {
        if (bags[i].items == maxItems && bags[i].weight < minWeight) {
            minWeight = bags[i].weight;
            bestId = bags[i].passengerId;
        }
    }


    if (bestId > 0 && bestId <= passCount) {
        printf("\nПасажир з найбільшим багажем:\n");
        printf("Прізвище: %s\n", passengers[bestId - 1]);
        printf("Кількість речей: %d\n", maxItems);
        printf("Вага багажу: %.2lf кг\n", minWeight);
    } else {
        printf("Не знайдено відповідного пасажира!\n");
    }
}

int main() {
    const char *passengersFile = "passengers.txt";
    const char *baggageFile = "baggage.txt";

    findPassengerWithMaxBaggage(passengersFile, baggageFile);
    return 0;
}
