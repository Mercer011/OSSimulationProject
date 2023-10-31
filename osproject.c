#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct File {
    char name[50];
    int size;
    struct File* next;
};

struct DiskBlock {
    struct File* file;
};

struct DiskBlock disk[100]; // 100 disk blocks

void initializeDisk() {
    for (int i = 0; i < 100; i++) {
        disk[i].file = NULL;
    }
}

struct File* createFile(char* name, int size) {
    struct File* newFile = (struct File*)malloc(sizeof(struct File));
    strcpy(newFile->name, name);
    newFile->size = size;
    newFile->next = NULL;
    return newFile;
}

int storeFile(struct File* file) {
    for (int i = 0; i < 100; i++) {
        if (disk[i].file == NULL) {
            disk[i].file = file;
            return 1; // Successful storage
        }
    }
    return 0; // Disk is full
}

int deleteFile(char* name) {
    for (int i = 0; i < 100; i++) {
        if (disk[i].file != NULL && strcmp(disk[i].file->name, name) == 0) {
            free(disk[i].file);
            disk[i].file = NULL;
            return 1; // Successful deletion
        }
    }
    return 0; // File not found
}

void displayDisk() {
    printf("Disk Status:\n");
    int wastedBlocks = 0;
    for (int i = 0; i < 100; i++) {
        if (disk[i].file != NULL) {
            printf("Block %d: %s (%d KB)\n", i, disk[i].file->name, disk[i].file->size);
        } else {
            wastedBlocks++;
        }
    }
    printf("Wasted Disk Space: %d blocks\n", wastedBlocks);
}

// Function to calculate fragmentation
float calculateFragmentation() {
    int usedBlocks = 0;
    for (int i = 0; i < 100; i++) {
        if (disk[i].file != NULL) {
            usedBlocks++;
        }
    }
    float fragmentation = (100 - usedBlocks) / 100.0;
    return fragmentation;
}
int main() {
    initializeDisk();

    while (1) {
        printf("\nFile System Simulation Menu:\n");
        printf("1. Create a file\n");
        printf("2. Delete a file\n");
        printf("3. Display disk status\n");
        printf("4. Calculate and display wasted disk space\n");
        printf("5. Calculate and display average fragmentation\n");
        printf("6. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            // (Previous cases omitted for brevity)

            case 5:
//                float fragmentationValue = calculateFragmentation();
                printf("Fragmentation: %.2f%%\n", fragmentationValue * 100);
                break;

            case 6:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

