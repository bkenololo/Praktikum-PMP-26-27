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
    char kata[100];
    int length;
    int error;
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
    int sumlen = 0;
    int totalvalid=0;
    for (int i = 0; i < N; i++)
    {
        if(array[i].error!=1){
            totalvalid += 1;
            printf("%s", array[i].kata);
            if (i < totalvalid-1)
            {
                printf(" ");
            }
            sumlen+=array[i].length;
        };
    }
    printf("\nLENGTH %d\n", sumlen);
}

int main(){
    int N;
    char sandi[20];
    scanf("%d %s", &N, sandi);
    struct Paket array[N];
    for (int i = 0; i < N; i++)
    {
        int index_i;
        char sandi_i[20];
        char kata_i[100];

        scanf("%d %s %s", &index_i, sandi_i, kata_i);
        reverse(kata_i);
        // printf("%s", kata_i);
        array[index_i-1].index=index_i;
        array[index_i-1].length=strlen(kata_i);
        if(strcmp(sandi, sandi_i) == 0){
            strcpy(array[index_i-1].kata, kata_i);
            array[index_i-1].error=0;
        } else {
            array[index_i-1].error=1;
        }
        // printf("%d %s \n", array[index_i-1].index, array[index_i-1].kata);
    }
    // printf("%d %s \n", array[0].index, array[0].kata);
    // printf("%d %s \n", array[1].index, array[1].kata);
    print(array, N);
    return 0;
}
