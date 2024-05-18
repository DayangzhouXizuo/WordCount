#include <stdio.h>  
#include <stdlib.h>  
#include <ctype.h>  
#include <string.h>  
  
int count_characters(FILE *file);  
int count_words(FILE *file);  
  
int main(int argc, char *argv[]) {  
    if (argc != 3) {  
        printf("Usage: %s [-c|-w] [input_file_name]\n", argv[0]);  
        return 1;  
    }  
  
    FILE *file = fopen(argv[2], "r");  
    if (file == NULL) {  
        perror("打开文件错误！");  
        return 1;  
    }  
  
    int count = 0;  
    if (strcmp(argv[1], "-c") == 0) {  
        count = count_characters(file);  
        printf("字符数：%d\n", count);  
    } else if (strcmp(argv[1], "-w") == 0) {  
        count = count_words(file);  
        printf("单词数：%d\n", count);  
    } else {  
        printf("无效参数: %s\n", argv[1]);  
    }  
  
    fclose(file);  
    return 0;  
}  
  
int count_characters(FILE *file) {  
    int count = 0;  
    char ch;  
    while ((ch = fgetc(file)) != EOF) {  
        if (!isspace(ch)) {  
            count++;  
        }  
    }  
    rewind(file);  
    return count;  
}  
  
int count_words(FILE *file) {  
    int count = 0;  
    int in_word = 0;  
    char ch;  
    while ((ch = fgetc(file)) != EOF) {  
        if (isspace(ch)) {  
            in_word = 0;  
        } else if (!in_word) {  
            count++;  
            in_word = 1;  
        }  
    }    
    rewind(file);  
    return count;  
} 

