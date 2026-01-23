#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR_SIZE 50

int min_distance(char *arr[], int n);

// initialization functions:
void *allocate(int n) {
    char *str = (char *)malloc(n);
    if (str == NULL) {
        exit(1);
    }
    return str;
}
char *get_string() {
    char *str, *str_i;
    str_i = str = (char *)allocate(MAX_ARR_SIZE);
    while (1) {
        int f = scanf("%c", str_i);
        if (f == 0) {
            exit(1);
        }
        if (f == EOF || *(str_i) == '\n') {
            *str_i = '\0';
            return str;
        }
        str_i++;
    }
}

char **get_all_string(int n) {

    char **arr = (char **)allocate(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        arr[i] = get_string();
    }
    return arr;
}
void free_all_strings(char **arr, int n) {
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main() {
    int n;
    int r = scanf("%d ", &n);
    if (r == 0) {
        exit(1);
    }
    char **arr = get_all_string(n);
    printf("%s\n", arr[min_distance(arr, n)]);
    free_all_strings(arr, n);

    return 0;
}

// auxiliary functions for get_all_sub_strings:
int count_num_of_one(int n) {
    int count = 0;
    while (n > 0) {
        count += n % 2;
        n = n / 2;
    }
    return count;
}

char *get_sub_string(char *str, int num_of_ones, int mask) {
    char *sub_str, *sub_str_i;
    sub_str_i = sub_str = (char *)allocate(num_of_ones + 1);
    while (*str) {
        if (mask % 2) {
            *sub_str_i = *str;
            sub_str_i++;
        }
        mask = mask / 2;
        str++;
    }
    *sub_str_i = 0;
    return sub_str;
}

int pow_of_2(int n) {
    int p = 1;
    while (n-- > 0) {
        p *= 2;
    }
    return p;
}

char **get_all_sub_strings(char *str, int n) {
    int amount_of_sub_strings = pow_of_2(n);
    char **arr = (char **)allocate(amount_of_sub_strings * sizeof(char *));
    for (int i = 0; i < amount_of_sub_strings; i++) {
        arr[i] = get_sub_string(str, count_num_of_one(i), i);
    }
    return arr;
}

// arr: The array we want to add to
// length: the length of the array
void free_2d_strings(char **arr, int length) {
    for (int i = 0; i < length; i++) {
        free(arr[i]);
    }
    free(arr);
}

int max(int first, int second) {
    if (first >= second) {
        return first;
    }
    return second;
}

int lenstr(char *str) {
    int index = 0;
    while (str[index] != '\0') {
        index++;
    }
    return index;
}

bool cmpstr(char *str1, char *str2) {
    int len1 = lenstr(str1);
    int len2 = lenstr(str2);
    if (len1 != len2) {
        return false;
    }
    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}

int get_length(char *word1, char *word2, char *link) {
    int word1len = lenstr(word1);
    int word2len = lenstr(word2);
    int linklength = lenstr(link);
    return word1len + word2len - (2 * linklength);
}

// str: The string
// n: The length of the string
// pos: The current position within the string
int get_next_space(char *str, int n, int pos) {
    while (pos < n) {
        if (*(str + pos) == ' ') {
            return pos;
        }
        pos++;
    }
    return -1;
}

// str: The string
// n: The length of the string
int get_words_count(char *str, int n) {
    int pos = 0;
    int count = 0;
    while (pos != -1) {
        pos++;
        count++;
        pos = get_next_space(str, n, pos);
    }
    return count;
}

// str: The original string
char *clonestr(char *str) {
    int length = lenstr(str) + 1;
    char *ret = (char *)malloc((length) * sizeof(char));
    for (int i = 0; i < length - 1; i++) {
        ret[i] = str[i];
    }
    ret[length - 1] = '\0';
    return ret;
}

// arr: The array we want to add to
// length: The position in the array we want to add the string to
// str: the string we want to add
void add_str_to_arr(char **arr, int position, char *str) {
    int stringLength = lenstr(str) + 1;
    arr[position] = (char *)malloc(stringLength * sizeof(char));
    for (int i = 0; i < stringLength - 1; i++) {
        arr[position][i] = str[i];
    }
    arr[position][stringLength - 1] = '\0';
}

char **get_words(char *line, int len) {
    char **str = (char **)allocate(get_words_count(line, len) * sizeof(char *));
    int pos = 0;
    for (int i = 0; i < get_words_count(line, len); i++) {
        int nextSpace = get_next_space(line, len, pos);
        if (nextSpace == -1)
            nextSpace = len;
        int wordLength = nextSpace - pos;
        str[i] = (char *)allocate((wordLength + 1) * sizeof(char));
        for (int j = 0; j < wordLength; j++) {
            str[i][j] = line[j + pos];
        }
        str[i][wordLength] = '\0';
        pos = nextSpace + 1;
    }
    return str;
}

char **get_both(char **arr1, int len1, char **arr2, int len2, int *len) {
    char **intersection = (char **)allocate(len1 * len2 * sizeof(char *));
    int index = 0; // The index of the current word within the intersection arr
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (cmpstr(arr1[i], arr2[j])) {
                add_str_to_arr(intersection, index++, arr1[i]);
            }
        }
    }
    *len = index;
    return intersection;
}

char *get_link(char *word1, int len1, char *word2, int len2) {
    char **subs1 = get_all_sub_strings(word1, len1);
    char **subs2 = get_all_sub_strings(word2, len2);
    int len = 0;
    char **both = get_both(subs1, pow_of_2(len1), subs2, pow_of_2(len2), &len);
    int best = -1;
    for (int i = 0; i < len; i++) {
        if (best == -1 || lenstr(both[i]) > lenstr(both[best])) {
            best = i;
        }
    }
    char *bestWord = clonestr(best == -1 ? "" : both[best]);
    free_2d_strings(subs1, pow_of_2(len1));
    free_2d_strings(subs2, pow_of_2(len2));
    free_2d_strings(both, len);
    return bestWord;
}

int *get_distances(char *arr[], int n) {
    int *dist = (int *)allocate(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        int count = get_words_count(arr[i], lenstr(arr[i]));
        char **words = get_words(arr[i], lenstr(arr[i]));
        dist[i] = 0;
        for (int j = 0; j < count; j++) {
            int next = (j + 1) % count;
            char *link = get_link(words[j], lenstr(words[j]), words[next],
                                  lenstr(words[next]));
            dist[i] = max(dist[i], get_length(words[j], words[next], link));
            free(link);
        }
        free_2d_strings(words, count);
    }
    return dist;
}

int min_distance(char *arr[], int n) {
    int *distances = get_distances(arr, n);
    int min_val = distances[0];
    int min_index = 0;
    for (int i = 0; i < n; i++) {
        if (min_val > distances[i]) {
            min_val = distances[i];
            min_index = i;
        }
    }
    free(distances);
    return min_index;
}
