
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
    char kata[100]; // FIXED: Allocated a fixed size so strcpy has enough memory buffer
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
    if (N == 0){
        printf("000\n");
        return;
    }

    int total = 0;

    for (int i = 0; i < N; i++)
    {
        if (i > 0) printf(" ");
        printf("%s", array[i].kata);
        total += strlen(array[i].kata);
    }

    printf("\nLENGTH %d\n", total);
}

int main(){
    int N;
    char sandi[20];

    // Scan N first so the compiler knows how much memory to allocate for the array
    if (scanf("%d %19s", &N, sandi) != 2) return 1;

    struct Paket array[N > 0 ? N : 1]; // FIXED: Declared AFTER N is initialized
    int jumlahValid = 0;

    for (int i = 0; i < N; i++)
    {
        int index_i;
        char sandi_i[20];
        char kata_i[100];

        if (scanf("%d %19s %99s", &index_i, sandi_i, kata_i) != 3) break;
        reverse(kata_i);

        if(strcmp(sandi, sandi_i) == 0){
            array[jumlahValid].index = index_i;
            strcpy(array[jumlahValid].kata, kata_i);
            jumlahValid++;
        }
    }

    for (int i = 0; i < jumlahValid - 1; i++){
        for (int j = i + 1; j < jumlahValid; j++){
            if (array[i].index > array[j].index){
                struct Paket temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    print(array, jumlahValid);
    return 0;
}
