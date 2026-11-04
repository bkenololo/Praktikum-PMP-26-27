/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
*   Modul               : Data Manipulation and External Files
*   Hari dan Tanggal    : Rabu, 4 November 2026
*   Nama (NIM)          : Benedictus Kenneth Setiadi (13224003)
*   Nama File           : soal1.c
*   Deskripsi           : 
*/

#include <stdio.h>
#include <string.h>


struct Paket {
    int index;
    char kata[];
};

void reverse(char kata[]){
    int left = 0;
    int right = strlen(kata);

    while (left < right){
        right--;

        char temp = kata[left];
        kata[left] = kata[right];
        kata[right] = temp;

        left++;
    }
}

void print(struct Paket array[], int N){
    for (int i = 0; i < N; i++)
    {
        // if(strcmp(array[i].kata, "kodeError")==1){
        //     printf("");
        // } else {
        //     printf("%s ", array[i].kata);
        // }
        printf("%d %s \n", array[i].index, array[i].kata);
    }
}

int main(){
    int N;
    struct Paket array[N];
    char sandi[20];
    scanf("%d %s", &N, sandi);
    for (int i = 0; i < N; i++)
    {
        int index_i;
        char sandi_i[20];
        char kata_i[100];

        scanf("%d %s %s", &index_i, sandi_i, kata_i);
        reverse(kata_i);
        // printf("%s", kata_i);
        array[index_i-1].index=index_i;
        if(strcmp(sandi, sandi_i) == 0){
            strcpy(array[index_i-1].kata, kata_i);
        } else {
            strcpy(array[index_i-1].kata, "kodeError");
        }
        // printf("%d %s \n", array[index_i-1].index, array[index_i-1].kata);
    }
    // printf("%d %s \n", array[0].index, array[0].kata);
    // printf("%d %s \n", array[1].index, array[1].kata);
    print(array, N);
    return 0;
}
