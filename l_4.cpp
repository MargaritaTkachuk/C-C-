#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int id;
    double x1, y1;
    double x2, y2;
} Rectangle;


double area(Rectangle r) {
    return fabs((r.x2 - r.x1) * (r.y1 - r.y2));
}


void createFile(const char *filename) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        printf("Помилка створення файлу!\n");
        return;
    }

    int n;
    printf("Скільки прямокутників ввести? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        Rectangle r;
        r.id = i + 1;
        printf("\nПрямокутник #%d\n", r.id);
        printf("Введіть x1, y1 (верхній лівий кут): ");
        scanf("%lf %lf", &r.x1, &r.y1);
        printf("Введіть x2, y2 (нижній правий кут): ");
        scanf("%lf %lf", &r.x2, &r.y2);

        fwrite(&r, sizeof(Rectangle), 1, f);
    }

    fclose(f);
}


void printFile(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        printf("Не вдалося відкрити файл!\n");
        return;
    }

    Rectangle r;
    printf("\n--- Вміст файлу ---\n");
    while (fread(&r, sizeof(Rectangle), 1, f) == 1) {
        printf("ID: %d | (%.2lf, %.2lf) - (%.2lf, %.2lf) | Площа = %.2lf\n",
               r.id, r.x1, r.y1, r.x2, r.y2, area(r));
    }
    fclose(f);
}


void findMaxArea(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        printf("Помилка відкриття файлу!\n");
        return;
    }

    Rectangle r, maxRect;
    double maxArea = -1;

    while (fread(&r, sizeof(Rectangle), 1, f) == 1) {
        double a = area(r);
        if (a > maxArea) {
            maxArea = a;
            maxRect = r;
        }
    }

    fclose(f);

    if (maxArea < 0) {
        printf("Файл порожній!\n");
        return;
    }

    printf("\nПрямокутник з найбільшою площею:\n");
    printf("ID: %d | Площа = %.2lf\n", maxRect.id, maxArea);
}


void deleteById(const char *filename, int id) {
    FILE *f = fopen(filename, "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (!f || !temp) {
        printf("Помилка відкриття файлів!\n");
        if (f) fclose(f);
        if (temp) fclose(temp);
        return;
    }

    Rectangle r;
    int found = 0;

    while (fread(&r, sizeof(Rectangle), 1, f) == 1) {
        if (r.id != id)
            fwrite(&r, sizeof(Rectangle), 1, temp);
        else
            found = 1;
    }

    fclose(f);
    fclose(temp);

    remove(filename);
    rename("temp.dat", filename);

    if (found)
        printf("Прямокутник з ID %d видалено.\n", id);
    else
        printf("Прямокутник з ID %d не знайдено.\n", id);
}


void replaceByIndex(const char *filename, int index) {
    FILE *f = fopen(filename, "rb+");
    if (!f) {
        printf("Не вдалося відкрити файл!\n");
        return;
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    int count = size / sizeof(Rectangle);

    if (index < 1 || index > count) {
        printf("Невірний номер! У файлі %d записів.\n", count);
        fclose(f);
        return;
    }

    Rectangle r;
    printf("Введіть нові координати для прямокутника #%d:\n", index);
    printf("x1, y1: "); scanf("%lf %lf", &r.x1, &r.y1);
    printf("x2, y2: "); scanf("%lf %lf", &r.x2, &r.y2);
    r.id = index;

    fseek(f, (index - 1) * sizeof(Rectangle), SEEK_SET);
    fwrite(&r, sizeof(Rectangle), 1, f);

    fclose(f);
    printf("Прямокутник #%d оновлено!\n", index);
}

int main() {
    const char *filename = "rectangles.dat";
    int choice;

    do {
        printf("\n--- МЕНЮ ---\n");
        printf("1. Створити файл\n");
        printf("2. Вивести файл\n");
        printf("3. Знайти прямокутник з найбільшою площею\n");
        printf("4. Видалити прямокутник за ID\n");
        printf("5. Замінити запис за порядковим номером\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        if (choice == 1) createFile(filename);
        else if (choice == 2) printFile(filename);
        else if (choice == 3) findMaxArea(filename);
        else if (choice == 4) {
            int id;
            printf("Введіть ID для видалення: ");
            scanf("%d", &id);
            deleteById(filename, id);
        }
        else if (choice == 5) {
            int index;
            printf("Введіть номер запису для заміни: ");
            scanf("%d", &index);
            replaceByIndex(filename, index);
        }
    } while (choice != 0);

    return 0;
}
