#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

void clearBuffer(char* screenBuf, int width, int height) {
    int i, j;
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            if (i == 0 || i == width - 1 || j == 0 || j == height - 1) {
                screenBuf[i + (j * width)] = '#';
            } else {
                screenBuf[i + (j * width)] = ' ';
            }
        }
        screenBuf[(j + 1) * width - 2] = '#';
        screenBuf[(j + 1) * width - 1] = '\n'; 
    }
    screenBuf[width * height - 2] = '#';
    screenBuf[width * height - 1] = '\0';
}
int writeStringToBuffer(const char* string, char* screenBuf, int width, int height, int x, int y) {
    int len = strlen(string);
    int i;
    if (x < 0 || x + len >= width || y < 0 || y >= height) {
        return 0;
    }
    for (i = 0; i < len; i++) {
        screenBuf[x + i + (y * width)] = string[i];
    }
    return 1;
}

void setTitleToScreenBuffer(char* screenBuf, int width, int height) {
    clearBuffer(screenBuf, width, height);
    writeStringToBuffer("Tungsten", screenBuf, width, height, 10, 3);
    writeStringToBuffer("1.Play Game", screenBuf, width, height, 3, 6);
    writeStringToBuffer("2.How To Play?", screenBuf, width, height, 3, 9);
    writeStringToBuffer("3.Exit", screenBuf, width, height, 3, 12);
}

void setsc1ToScreenBuffer(char* screenBuf, int width, int height) {
    clearBuffer(screenBuf, width, height);
    writeStringToBuffer("SORRY", screenBuf, width, height, 12, 3);
    writeStringToBuffer("This function has not", screenBuf, width, height, 2, 7);
    writeStringToBuffer("yet been implemented.", screenBuf, width, height, 2, 8);
    writeStringToBuffer("Press 4 to back", screenBuf, width, height, 5, 9);
}
void setsc2ToScreenBuffer(char* screenBuf, int width, int height) {
    clearBuffer(screenBuf, width, height);
    writeStringToBuffer("How To Play Game?", screenBuf, width, height, 6, 3);
    writeStringToBuffer("Press your space bar", screenBuf, width, height, 2, 7);
    writeStringToBuffer("to be able to dig up ore", screenBuf, width, height, 2, 8);
    writeStringToBuffer("Press 4 to back", screenBuf, width, height, 5, 9);
}
void setsc3ToScreenBuffer(char* screenBuf, int width, int height) {
    clearBuffer(screenBuf, width, height);
    writeStringToBuffer("Are you really going to", screenBuf, width, height, 3, 3);
    writeStringToBuffer("end the game?", screenBuf, width, height, 3, 4);
    writeStringToBuffer("1. Yes", screenBuf, width, height, 3, 8);
    writeStringToBuffer("2. No", screenBuf, width, height, 3, 9);
}

#define WIDTH 31
#define HEIGHT 15

void setTitleToScreenBuffer(char* screen, int width, int height);
void setsc1ToScreenBuffer(char* screen, int width, int height);
void setsc2ToScreenBuffer(char* screen, int width, int height);
void setsc3ToScreenBuffer(char* screen, int width, int height);

int main() {
    char screen[WIDTH * HEIGHT + 1];
    int input;
    int currentState = 0;  

    setTitleToScreenBuffer(screen, WIDTH, HEIGHT);

    while (1) {
        printf("%s\npress key-->\n", screen);
        scanf("%d", &input);

        if (currentState == 0) {
            if (input == 1) {
                setsc1ToScreenBuffer(screen, WIDTH, HEIGHT);
                currentState = 1;
            }
        } else if (currentState == 1) 
            if (input == 4) {
                setTitleToScreenBuffer(screen, WIDTH, HEIGHT);
                currentState = 0;
            }
        } else if (currentState == 2) {
            if (input == 4) {
                setTitleToScreenBuffer(screen, WIDTH, HEIGHT);
                currentState = 0;
            }
        } else if (currentState == 3) {
            if (input == 1) {
                break;
            } else if (input == 2) {
                setTitleToScreenBuffer(screen, WIDTH, HEIGHT);
                currentState = 0;
            }
        }

        if (currentState == 0) {
            if (input == 2) {
                setsc2ToScreenBuffer(screen, WIDTH, HEIGHT);
                currentState = 2;
            }
        }

        if (input == 3) {

            setsc3ToScreenBuffer(screen, WIDTH, HEIGHT);
            currentState = 3;
        }
        printf("Program terminated.\n");

        return 0;
    }

