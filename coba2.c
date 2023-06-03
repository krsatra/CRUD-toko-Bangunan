#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>



struct toko{
    int kode[50];
    int harga[50], jumlah[50];
    char nama_barang[50], jenis[50];
};

typedef struct{
    char riwayat[100];
}history;

struct toko toko[50];
history riwayat[200];

void gotoxy();
void login();
void menu();
void tampilDatabase();
void tambahDatabase();
void hapusDatabase();
void editDatabase();
void cariDatabase();
void tampilcariDatabase();
void riwayatDatabase();
void keluar();

int banyakdata, banyaktambahdata, i, j, k;
int riwayad, found, total;
int arr;
int n=5;

int main(){
    login();
}

// Memberi nilai gotoxy
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

// Buat Data Base

void buatDatabase(){
    system("cls");
    gotoxy(30,3);
    printf("+ ================================================= +");
    gotoxy(54,5);printf("DATABASE");
    gotoxy(41,6);
    printf("~~~ Membuat Database Toko Bangunan ~~~");
    gotoxy(30,8);
    printf("+ ================================================= +");
    gotoxy(30,11);
    printf("+ ================================================= +");
    gotoxy(39,9);
    printf("Data maksimum yang bisa diinput : %d", n-banyakdata);
    gotoxy(39,10);
    printf("Banyak data yang ingin diinput  : ");
    scanf("%d", &banyakdata);

    if(banyakdata <= n-banyakdata+2 && banyakdata >= 1){
        for(i = 0; i < banyakdata; i++){
            printf(" ");
            gotoxy(32,13+(i*6));
            printf("\nData Toko Bangunan Ke-%d\n", i+1);

            gotoxy(32,14+(i*6));
            printf("Kode Barang\t : ");
            fflush(stdin);
            scanf("%s", &toko[i].kode);

            gotoxy(32,15+(i*6));
            printf("Nama Barang\t : ");
            fflush(stdin);
            gets(toko[i].nama_barang);

            gotoxy(32,16+(i*6));
            printf("Nama Barang\t : ");
            fflush(stdin);
            gets(toko[i].nama_barang);

            gotoxy(32,17+(i*6));
            printf("Jenis Barang\t : ");
            fflush(stdin);
            gets(toko[i].jenis);

            gotoxy(32,18+(i*6));
            printf("Jumlah Barang\t : ");
            fflush(stdin);
            scanf("%s", &toko[i].jumlah);

            gotoxy(32,19+(i*6));
            printf("Harga Barang\t : ");
            fflush(stdin);
            scanf("%s", &toko[i].harga);
        }
        strcpy(riwayat[riwayad].riwayat, "ADMIN MEMBUAT DATABASE");
        riwayad++;


        gotoxy(40,40);printf("\nKlik Apa Saja Untuk Melanjutkan....");
        getch();
        menu();
    }else{
        gotoxy(72,10);printf(" Maksimal %d Cuyyy", n-banyakdata+2);
        getch();
        buatDatabase();
    }
}

// Tampil Data Base

void tampilDatabase(){
    system("cls");
    gotoxy(10,3);
    printf("+ ========================================================================================================= +");
    gotoxy(60,5);
    printf("DATABASE");
    gotoxy(50,6);
    printf("=== MENAMPILKAN ISI DATABASE ===");
    gotoxy(10,8);
    printf("+ ========================================================================================================= +");

    gotoxy(10,10);
    printf("|Kode Barang");
    gotoxy(33,10);
    printf("|Nama Barang");
    gotoxy(56,10);
    printf("|Jenis Barang");
    gotoxy(79,10);
    printf("|Jumlah Barang");
    gotoxy(102,10);
    printf("|Harga Barang");

    for(i=0; i < banyakdata; i++){
        gotoxy(10,11+i+1);
        printf("|%s", toko[i].kode);
        gotoxy(33, 11+i+1);
        printf("|%s", toko[i].nama_barang);
        gotoxy(56, 11+i+1);
        printf("|%s", toko[i].jenis);
        gotoxy(79, 11+i+1);
        printf("|%s", toko[i].jumlah);
        gotoxy(102, 11+i+1);
        printf("|%s", toko[i].harga);
        printf("\n");
    }
    gotoxy(10,20);
    printf("+ ========================================================================================================== +");
    strcpy(riwayat[riwayad].riwayat, "ADMIN MEMBUAT DATABASE");
    riwayad++;

    gotoxy(11,30);printf("\nKlik Apa Saja Untuk Melanjutkan....");
    getch();
    menu();
}

//tambah data base
void tambahDatabase(){
    int b;

    balik:
    system("cls");
    gotoxy(30, 3);
    printf("+ ================================================= +");
    gotoxy(37, 5);
    printf("                 DATABASE                            ");
    gotoxy(37, 6);
    printf("    ~~~ MENAMBAHKAN ISI DATABASE PET SHOP ~~~        ");
    gotoxy(30, 8);
    printf("+ ================================================= +");
    gotoxy(30, 11);
    printf("+ ================================================= +");
    gotoxy(39, 9);
    printf("DATA MAKSIMUM YANG BISA DIINPUT : %d", n-banyakdata);
    gotoxy(39, 10);
    printf("BANYAK DATA YANG INGIN DIINPUT : ");
    scanf("%d", &banyaktambahdata);
    int c = 0;

    if(banyaktambahdata <=n-banyakdata && banyaktambahdata >= 1){
        for(b = 0; b < banyaktambahdata; b++){
            printf(" ");
            gotoxy(32, 13+(b*6));
            printf("\nData Pet Shop Ke-%d\n", banyakdata+banyaktambahdata-1+b);

            gotoxy(32, 14+(b*6));
            printf("Kode Barang\t = ");
            fflush(stdin);
            scanf("%s", &toko[i].kode);
            for(j = 0; j < i; j++){
                if(found =  strcmp(toko[j].kode, toko[i].kode)==0){
                    gotoxy(33,15+(j*b*6));
                    printf("\n Kode Sudah Ada\n\n");
                    gotoxy(35,17);
                    printf("Tekan Apa Saja Untuk Melanjutkan....");
                    getch();
                    goto balik;
                }
            }
            gotoxy(32, 15+(b*6));
            printf("Nama Barang\t = ");
            fflush(stdin);
            gets(toko[i].nama_barang);

            gotoxy(32, 16+(b*6));
            printf("Jenis Barang\t = ");
            fflush(stdin);
            gets(toko[i].jenis);

            gotoxy(32, 17+(b*6));
            printf("Jumlah Barang\t = ");
            fflush(stdin);
            scanf("%s", &toko[i].jumlah);

            gotoxy(32, 18+(b*6));
            printf("Harga Barang\t = ");
            fflush(stdin);
            scanf("%s", &toko[i].harga);
        }
        banyakdata += banyaktambahdata;

        strcpy(riwayat[riwayad].riwayat ,"ADMIN MENAMBAH DATABASE");
        riwayad++;
        strcpy(toko[i].kode, toko[i].kode);
        i++;

        printf("\nKlik Apa Saja Untuk Melanjutkan....");
        getch();
        menu();
    }else{
        gotoxy(72,10);printf(" Maksimal %d Cuyyy", n-banyakdata);
        getch();
        tambahDatabase();
    }
}

void hapusDatabase()
{
    char kode[10], ans;

    system("cls");
    gotoxy(30,3);printf("+ ================================================= +");
    gotoxy(30,5);printf("                      DATABASE                      ");
    gotoxy(30,6);printf("         === MENGHAPUS ISI DATABASE ===    ");
    gotoxy(30,8);printf("+ ================================================= +");
    gotoxy(30,9);printf("      Masukkan kode barang yang ingin dihapus :       ");
    gotoxy(30,10);printf("+ ================================================= +");
    gotoxy(78,9);scanf("%s", &kode);

    for(i = 0; i < banyakdata; i++)
    {
        if(strcmp(kode, toko[i].kode) == 0)
        {
            gotoxy(32, 12);
            printf(":: Data Pet Shop ::");
            gotoxy(32, 13);
            printf(":: Kode Barang\t = %s",toko[i].kode);
            gotoxy(32, 14);
            printf(":: Nama Barang\t = %s",toko[i].nama_barang);
            gotoxy(32, 15);
            printf(":: Jenis Barang\t = %s",toko[i].jenis);
            gotoxy(32, 16);
            printf(":: Jumlah Barang\t = %s", toko[i].jumlah);
            gotoxy(32, 17);
            printf(":: Harga Barang\t = %s", toko[i].harga);
            gotoxy(32, 19);
            printf("Yakin ingin menghapus data ini?[y/n] ");
            scanf("%s", &ans);

            if(ans == 'y' ||  ans == 'Y')
            {
                for(int j = i; j <= banyakdata; j++)
                {
                    toko[j] = toko[j+1];
                }
                banyakdata--;
                printf("\n\t\t\tData berhasil dihapus");

                strcpy(riwayat[riwayad].riwayat ,"ADMIN MENGHAPUS DATABASE");
                riwayad++;

                printf("\n\t\t\tKlik terserah untuk lanjut~ ");
                getch();
                menu();
            }
            else if(ans == 'n' || ans == 'N')
            {
                printf("Tekan Enter Untuk Lanjut....");
                getch();
                system("cls");
                menu();
            }
        }
    }
    gotoxy(23,11);
    printf("Kode %d tidak dapat ditemukan, silahkan coba lagi", kode);
    gotoxy(23,12);
    printf("\nKlik Apa Saja Untuk Melanjutkan....");
    getch();
    system("cls");
    hapusDatabase();

}

void editDatabase(){
    int pilihan;
    char string[30];
    ulang:
    system("cls");
    gotoxy(30, 3);
    printf("+ ================================================= +");
    gotoxy(49, 5);
    printf("DATABASE");
    gotoxy(38, 6);
    printf("=== Mengubah data barang di pet shop ===");
    gotoxy(30, 8);
    printf("+ ================================================= +");
    gotoxy(30, 15);
    printf("+ ================================================= +");
    gotoxy(37, 9);
    printf("-- BAGIAN APA YANG INGIN ANDA EDIT? --");
    gotoxy(35, 10);
    printf("1. Nama Barang\t\t3. Jumlah Barang");
    gotoxy(35, 11);
    printf("2. Jenis Barang\t\t4. harga Barang");
    gotoxy(35, 13);
    printf("Pilihan Anda \t: ");
    //fflush(stdin);
    scanf("%d", &pilihan);

    if(pilihan == 1){
        gotoxy(35, 14);
        printf("Masukkan Kode Barang\t: ");
        scanf(" %s", string);

        for (i = 0; i < banyakdata; i++){
            if(strcmp(string, toko[i].kode) == 0){
                gotoxy(35, 17);
                printf("UBAH DATA NAMA BARENG");
                gotoxy(35, 18);
                printf("DATA SAAT INI : %s", toko[i].nama_barang);
                gotoxy(35, 19);
                printf("DATA YANG BARU : ");
                fflush(stdin);
                gets(toko[i].nama_barang);
                gotoxy(35, 20);
                printf(":: DATA TELAH DIUBAH ::");
                gotoxy(35, 22);

                strcpy(riwayat[riwayad].riwayat ,"ADMIN MENGEDIT DATABASE");
                riwayad++;

                printf("Klik terserah untuk lanjut~");
                getch();
                menu();
                // strcpy(riwayat[riwayad].riwayat ,"ADMIN MELAKUKAN PENCARIAN DATABASE");
                // riwayad++;
            }
        }
        gotoxy(34, 17);
        printf("KODE BARANG YANG DICARI TIDAK DITEMUKAN");
        getch();
        editDatabase();
    }else if(pilihan == 2){
        gotoxy(35, 14);
        printf("Masukkan Kode Barang\t: ");
        scanf(" %s", string);

        for (i = 0; i < banyakdata; i++){
            if(strcmp(string, toko[i].kode) == 0){
                gotoxy(35, 17);
                printf("UBAH DATA JENIS BARENG");
                gotoxy(35, 18);
                printf("DATA SAAT INI : %s", toko[i].jenis);
                gotoxy(35, 19);
                printf("DATA YANG BARU : ");
                fflush(stdin);
                gets(toko[i].jenis);
                gotoxy(35, 20);
                printf(":: DATA TELAH DIUBAH ::");
                gotoxy(35, 22);

                strcpy(riwayat[riwayad].riwayat ,"ADMIN MENGEDIT DATABASE");
                riwayad++;

                printf("Klik terserah untuk lanjut~");
                getch();
                menu();
                // strcpy(riwayat[riwayad].riwayat ,"ADMIN MELAKUKAN PENCARIAN DATABASE");
                // riwayad++;
            }
        }
        gotoxy(34, 17);
        printf("KODE BARANG YANG DICARI TIDAK DITEMUKAN");
        getch();
        editDatabase();
    }else if(pilihan == 3){
        gotoxy(35, 14);
        printf("Masukkan Kode Barang\t: ");
        scanf(" %s", string);

        for (i = 0; i < banyakdata; i++){
            if(strcmp(string, toko[i].kode) == 0){
                gotoxy(35, 17);
                printf("UBAH DATA JUMLAH BARENG");
                gotoxy(35, 18);
                printf("DATA SAAT INI : %s", toko[i].jumlah);
                gotoxy(35, 19);
                printf("DATA YANG BARU : ");
                fflush(stdin);
                gets(toko[i].jumlah);
                gotoxy(35, 20);
                printf(":: DATA TELAH DIUBAH ::");
                gotoxy(35, 22);

                strcpy(riwayat[riwayad].riwayat ,"ADMIN MENGEDIT DATABASE");
                riwayad++;

                printf("Klik terserah untuk lanjut~");
                getch();
                menu();
                // strcpy(riwayat[riwayad].riwayat ,"ADMIN MELAKUKAN PENCARIAN DATABASE");
                // riwayad++;
            }
        }
        gotoxy(34, 17);
        printf("KODE BARANG YANG DICARI TIDAK DITEMUKAN");
        getch();
        editDatabase();
    }else if(pilihan == 4){
        gotoxy(35, 14);
        printf("Masukkan Kode Barang\t: ");
        scanf(" %s", string);

        for (i = 0; i < banyakdata; i++){
            if(strcmp(string, toko[i].kode) == 0){
                gotoxy(35, 17);
                printf("UBAH DATA HARGA BARENG");
                gotoxy(35, 18);
                printf("DATA SAAT INI : %s", toko[i].harga);
                gotoxy(35, 19);
                printf("DATA YANG BARU : ");
                fflush(stdin);
                gets(toko[i].harga);
                gotoxy(35, 20);
                printf(":: DATA TELAH DIUBAH ::");
                gotoxy(35, 22);

                strcpy(riwayat[riwayad].riwayat ,"ADMIN MENGEDIT DATABASE");
                riwayad++;

                printf("Klik terserah untuk lanjut~");
                getch();
                menu();
                // strcpy(riwayat[riwayad].riwayat ,"ADMIN MELAKUKAN PENCARIAN DATABASE");
                // riwayad++;
            }
        }
        gotoxy(34, 17);
        printf("KODE BARANG YANG DICARI TIDAK DITEMUKAN");
        getch();
        editDatabase();
    }else{
        printf("Pilihan Tidak Ada!!!");
        getch();
        editDatabase();
    }
}

void cariDatabase(){
    int pilihan;
    char string[30];

    system("cls");
    gotoxy(30, 3);
    printf("+ ================================================= +");
    gotoxy(49, 5);
    printf("DATABASE");
    gotoxy(38, 6);
    printf("=== MENCARI ISI DATABASE PET SHOP ===");
    gotoxy(30, 8);
    printf("+ ================================================= +");
    gotoxy(30, 18);
    printf("+ ================================================= +");
    gotoxy(37, 9);
    printf("-- BAGIAN APA YANG INGIN ANDA CARI? --");
    gotoxy(35, 10);
    printf("1. KODE BARANG\t\t4. JUMLAH BARANG");
    gotoxy(35, 11);
    printf("2. NAMA BARANG\t\t5. HARGA BARANG");
    gotoxy(35, 12);
    printf("3. JENIS BARANG");
    gotoxy(35, 14);
    printf("PILIHAN ANDA\t\t\t: ");
    scanf("%d", &pilihan);

    switch(pilihan)
    {
    case 1:
        {
            gotoxy(35, 15);
            printf("KODE BARANG YANG DICARI\t: ");
            fflush(stdin);
            scanf(" %s", string);

            for (i = 0; i < banyakdata; i++)
            {
                if(strcmp(string, toko[i].kode) == 0)
                {
                    strcpy(riwayat[riwayad].riwayat ,"ADMIN MELAKUKAN PENCARIAN DATABASE");
                    riwayad++;

                    tampilcariDatabase();
                }
            }
            gotoxy(34, 17);
            printf("KODE BARANG YANG DICARI TIDAK DITEMUKAN");
            getch();
            cariDatabase();
        }
    case 2:
        {
            gotoxy(35, 15);
            printf("NAMA BARANG YANG DICARI\t: ");
            fflush(stdin);
            gets(string);

            for (i = 0; i < banyakdata; i++)
            {
                if(strcmp(string, toko[i].nama_barang) == 0)
                {
                    strcpy(riwayat[riwayad].riwayat ,"ADMIN MELAKUKAN PENCARIAN DATABASE");
                    riwayad++;

                    tampilcariDatabase();
                }
            }
            gotoxy(34, 17);
            printf("NAMA BARANG YANG DICARI TIDAK DITEMUKAN");
            getch();
            cariDatabase();
        }
    case 3:
        {
            gotoxy(35, 15);
            printf("JENIS BARANG YANG DICARI\t: ");
            fflush(stdin);
            gets(string);

            for (i = 0; i < banyakdata; i++)
            {
                if(strcmp(string, toko[i].jenis) == 0)
                {
                    strcpy(riwayat[riwayad].riwayat ,"ADMIN MELAKUKAN PENCARIAN DATABASE");
                    riwayad++;

                    tampilcariDatabase();
                }
            }
            gotoxy(34, 17);
            printf("JENIS BARANG YANG DICARI TIDAK DITEMUKAN");
            getch();
            cariDatabase();
        }
    case 4:
        {
            gotoxy(35, 15);
            printf("JUMLAH BARANG YANG DICARI\t: ");
            fflush(stdin);
            scanf(" %d", string);

            for (i = 0; i < banyakdata; i++)
            {
                if(strcmp(string, toko[i].jumlah) == 0)
                {
                    strcpy(riwayat[riwayad].riwayat ,"ADMIN MELAKUKAN PENCARIAN DATABASE");
                    riwayad++;

                    tampilcariDatabase();
                }
            }
            gotoxy(34, 17);
            printf("JUMLAH BARANG YANG DICARI TIDAK DITEMUKAN");
            getch();
            cariDatabase();
        }
    case 5:
        {
            gotoxy(35, 15);
            printf("HARGA BARANG YANG DICARI\t: ");
            fflush(stdin);
            scanf(" %s", string);

            for (i = 0; i < banyakdata; i++)
            {
                if(strcmp(string, toko[i].harga) == 0)
                {
                    strcpy(riwayat[riwayad].riwayat ,"ADMIN MELAKUKAN PENCARIAN DATABASE");
                    riwayad++;

                    tampilcariDatabase();
                }
            }
            gotoxy(34, 17);
            printf("HARGA BARANG YANG DICARI TIDAK DITEMUKAN");
            getch();
            cariDatabase();
        }
    }

    strcpy(riwayat[riwayad].riwayat ,"ADMIN MELAKUKAN PENCARIAN DATABASE");
    riwayad++;
}


void tampilcariDatabase(){
    {
        system("cls");
        gotoxy(30, 3);
        printf("+ ================================================= +");
        gotoxy(49, 5);
        printf("DATABASE");
        gotoxy(37, 6);
        printf("=== MENAMPILKAN ISI DATABASE ===");
        gotoxy(30, 8);
        printf("+ ================================================= +");

        gotoxy(10,10);
        printf("Kode Barang");
        gotoxy(33,10);
        printf("Nama Barang");
        gotoxy(56,10);
        printf("Jenis Barang");
        gotoxy(79,10);
        printf("Jumlah Barang");
        gotoxy(102,10);
        printf("Harga Barang");
        // for(i = 0; i<banyakdata; i++){
        //     gotoxy(10, 11+(i*2));
        //     printf("%s", toko[i].kode);
        //     gotoxy(33, 11+(i*2));
        //     printf("%s", toko[i].nama_barang);
        //     gotoxy(56, 11+(i*2));
        //     printf("%s", toko[i].jenis);
        //     gotoxy(79, 11+(i*2));
        //     printf("%s", toko[i].jumlah);
        //     gotoxy(102, 11+(i*2));
        //     printf("%s", toko[i].harga);
        //     printf("\n");
        // }
        gotoxy(10, 11);
        printf("%s", toko[i].kode);
        gotoxy(33, 11);
        printf("%s", toko[i].nama_barang);
        gotoxy(56, 11);
        printf("%s", toko[i].jenis);
        gotoxy(79, 11);
        printf("%s", toko[i].jumlah);
        gotoxy(102, 11);
        printf("%s", toko[i].harga);
        printf("\n");

        
    }
    printf("\nKlik terserah untuk lanjut~ ");
    getch();
    menu();
}

void riwayatDatabase(){
    system("cls");
    gotoxy(30, 3);
    printf("+ ================================================= +");
    gotoxy(49, 5);
    printf("DATA TOKO BANGUNAN");
    gotoxy(36, 6);
    printf("=== RIWAYAT AKTIVITAS YANG DILAKUKAN ===");
    gotoxy(30, 8);
    printf("+ ================================================= +");
    gotoxy(35, 9);
    printf("NO.");
    gotoxy(45, 9);
    printf("AKTIVITAS");
    gotoxy(30, 10);
    printf("+ ================================================= +");

    for(int z = 0; z < riwayad; z++)
    {
        gotoxy(35, 11+z);
        printf("%d", z+1);
        printf("\n");

        gotoxy(45, 11+z);
        printf("%s", riwayat[z].riwayat);
        printf("\n");
    }
    getch();
    menu();
}


void urutData(){
    struct toko tempat;
    int pilihan;
    char string[30];

    ulang:
    system("cls");
    gotoxy(30, 3);
    printf("+ ================================================= +");
    gotoxy(49, 5);
    printf("DATABASE");
    gotoxy(38, 6);
    printf("=== MENCARI ISI DATABASE PET SHOP ===");
    gotoxy(30, 8);
    printf("+ ================================================= +");
    // gotoxy(30, 18);
    // printf("+ ================================================= +");
    gotoxy(30,13);
    printf("+ ================================================= +");
    gotoxy(37, 9);
    printf("-- BAGIAN APA YANG INGIN ANDA CARI? --");
    gotoxy(35, 10);
    printf("1. KODE BARANG\t\t4. JUMLAH BARANG");
    gotoxy(35, 11);
    printf("2. NAMA BARANG\t\t5. HARGA BARANG");
    gotoxy(35, 12);
    printf("3. JENIS BARANG");
    gotoxy(35, 14);
    printf("PILIHAN ANDA\t\t\t: ");
    scanf("%d", &pilihan);

    if(pilihan == 1){
            gotoxy(10,18);
            printf("+ ======================================================================================================================= +");
            gotoxy(50,19);
            printf("=== MENGURUTKAN DATABASE ===");
            int stringLenght=strlen(toko[i].kode);
            for(j=0;j<banyakdata;j++){
                for(k=0; k<i-1;k++){
                    if(toko[j].kode>toko[k+1].kode){
                        tempat=toko[j];
                        toko[j]=toko[k];
                        toko[k]=tempat;
                    }
                }
            }
            gotoxy(10,21);
            //printf("+ ======================================================================================================================= +");
            gotoxy(60,23);
            printf("DATABASE");
            gotoxy(50,24);
            printf("=== MENAMPILKAN ISI DATABASE ===");
            gotoxy(10,26);
            printf("+ ======================================================================================================================= +");

            gotoxy(10,28);
            printf("|Kode Barang");
            gotoxy(33,28);
            printf("|Nama Barang");
            gotoxy(56,28);
            printf("|Jenis Barang");
            gotoxy(79,28);
            printf("|Jumlah Barang");
            gotoxy(102,28);
            printf("|Harga Barang");

            for(i=0; i < banyakdata; i++){
                gotoxy(10,29+i+1);
                printf("|%s", toko[i].kode);
                gotoxy(33, 29+i+1);
                printf("|%s", toko[i].nama_barang);
                gotoxy(56, 29+i+1);
                printf("|%s", toko[i].jenis);
                gotoxy(79, 29+i+1);
                printf("|%s", toko[i].jumlah);
                gotoxy(102, 29+i+1);
                printf("|%s", toko[i].harga);
                printf("\n");
            }
            gotoxy(10,38);
            printf("+ ======================================================================================================================= +");
            strcpy(riwayat[riwayad].riwayat, "ADMIN MEMBUAT DATABASE");
            riwayad++;

            gotoxy(70,40);
            printf("\nKlik Apa Saja Untuk Melanjutkan....");
            getch();
            menu();
    }else if(pilihan == 2){
            gotoxy(10,18);
            printf("+ ======================================================================================================================= +");
            gotoxy(50,19);
            printf("=== MENGURUTKAN DATABASE ===");
            int stringLenght=strlen(toko[i].nama_barang);
            for(j=0;j<banyakdata;j++){
                for(k=0; k<i-1;k++){
                    if(toko[j].kode>toko[k+1].nama_barang){
                        tempat=toko[j];
                        toko[j]=toko[k];
                        toko[k]=tempat;
                    }
                }
            }
            gotoxy(10,21);
            //printf("+ ======================================================================================================================= +");
            gotoxy(60,23);
            printf("DATABASE");
            gotoxy(50,24);
            printf("=== MENAMPILKAN ISI DATABASE ===");
            gotoxy(10,26);
            printf("+ ======================================================================================================================= +");

            gotoxy(10,28);
            printf("|Kode Barang");
            gotoxy(33,28);
            printf("|Nama Barang");
            gotoxy(56,28);
            printf("|Jenis Barang");
            gotoxy(79,28);
            printf("|Jumlah Barang");
            gotoxy(102,28);
            printf("|Harga Barang");

            for(i=0; i < banyakdata; i++){
                gotoxy(10,29+i+1);
                printf("|%s", toko[i].kode);
                gotoxy(33, 29+i+1);
                printf("|%s", toko[i].nama_barang);
                gotoxy(56, 29+i+1);
                printf("|%s", toko[i].jenis);
                gotoxy(79, 29+i+1);
                printf("|%s", toko[i].jumlah);
                gotoxy(102, 29+i+1);
                printf("|%s", toko[i].harga);
                printf("\n");
            }
            gotoxy(10,38);
            printf("+ ======================================================================================================================= +");
            strcpy(riwayat[riwayad].riwayat, "ADMIN MEMBUAT DATABASE");
            riwayad++;

            gotoxy(70,40);
            printf("\nKlik Apa Saja Untuk Melanjutkan....");
            getch();
            menu();
    }else if(pilihan == 3){
            gotoxy(10,18);
            printf("+ ======================================================================================================================= +");
            gotoxy(50,19);
            printf("=== MENGURUTKAN DATABASE ===");
            int stringLenght=strlen(toko[i].jenis);
            for(j=0;j<banyakdata;j++){
                for(k=0; k<i-1;k++){
                    if(toko[j].kode>toko[k+1].jenis){
                        tempat=toko[j];
                        toko[j]=toko[k];
                        toko[k]=tempat;
                    }
                }
            }
            gotoxy(10,21);
            //printf("+ ======================================================================================================================= +");
            gotoxy(60,23);
            printf("DATABASE");
            gotoxy(50,24);
            printf("=== MENAMPILKAN ISI DATABASE ===");
            gotoxy(10,26);
            printf("+ ======================================================================================================================= +");

            gotoxy(10,28);
            printf("|Kode Barang");
            gotoxy(33,28);
            printf("|Nama Barang");
            gotoxy(56,28);
            printf("|Jenis Barang");
            gotoxy(79,28);
            printf("|Jumlah Barang");
            gotoxy(102,28);
            printf("|Harga Barang");

            for(i=0; i < banyakdata; i++){
                gotoxy(10,29+i+1);
                printf("|%s", toko[i].kode);
                gotoxy(33, 29+i+1);
                printf("|%s", toko[i].nama_barang);
                gotoxy(56, 29+i+1);
                printf("|%s", toko[i].jenis);
                gotoxy(79, 29+i+1);
                printf("|%s", toko[i].jumlah);
                gotoxy(102, 29+i+1);
                printf("|%s", toko[i].harga);
                printf("\n");
            }
            gotoxy(10,38);
            printf("+ ======================================================================================================================= +");
            strcpy(riwayat[riwayad].riwayat, "ADMIN MEMBUAT DATABASE");
            riwayad++;

            gotoxy(70,40);
            printf("\nKlik Apa Saja Untuk Melanjutkan....");
            getch();
            menu();
    }else if(pilihan == 4){
        gotoxy(10,18);
            printf("+ ======================================================================================================================= +");
            gotoxy(50,19);
            printf("=== MENGURUTKAN DATABASE ===");
            int stringLenght=strlen(toko[i].jumlah);
            for(j=0;j<banyakdata;j++){
                for(k=0; k<i-1;k++){
                    if(toko[j].kode>toko[k+1].jumlah){
                        tempat=toko[j];
                        toko[j]=toko[k];
                        toko[k]=tempat;
                    }
                }
            }
            gotoxy(10,21);
            //printf("+ ======================================================================================================================= +");
            gotoxy(60,23);
            printf("DATABASE");
            gotoxy(50,24);
            printf("=== MENAMPILKAN ISI DATABASE ===");
            gotoxy(10,26);
            printf("+ ======================================================================================================================= +");

            gotoxy(10,28);
            printf("|Kode Barang");
            gotoxy(33,28);
            printf("|Nama Barang");
            gotoxy(56,28);
            printf("|Jenis Barang");
            gotoxy(79,28);
            printf("|Jumlah Barang");
            gotoxy(102,28);
            printf("|Harga Barang");

            for(i=0; i < banyakdata; i++){
                gotoxy(10,29+i+1);
                printf("|%s", toko[i].kode);
                gotoxy(33, 29+i+1);
                printf("|%s", toko[i].nama_barang);
                gotoxy(56, 29+i+1);
                printf("|%s", toko[i].jenis);
                gotoxy(79, 29+i+1);
                printf("|%s", toko[i].jumlah);
                gotoxy(102, 29+i+1);
                printf("|%s", toko[i].harga);
                printf("\n");
            }
            gotoxy(10,38);
            printf("+ ======================================================================================================================= +");
            strcpy(riwayat[riwayad].riwayat, "ADMIN MEMBUAT DATABASE");
            riwayad++;

            gotoxy(70,40);
            printf("\nKlik Apa Saja Untuk Melanjutkan....");
            getch();
            menu();
    }else if(pilihan == 5){
        gotoxy(10,18);
            printf("+ ======================================================================================================================= +");
            gotoxy(50,19);
            printf("=== MENGURUTKAN DATABASE ===");
            int stringLenght=strlen(toko[i].harga);
            for(j=0;j<banyakdata;j++){
                for(k=0; k<i-1;k++){
                    if(toko[j].kode>toko[k+1].harga){
                        tempat=toko[j];
                        toko[j]=toko[k];
                        toko[k]=tempat;
                    }
                }
            }
            gotoxy(10,21);
            //printf("+ ======================================================================================================================= +");
            gotoxy(60,23);
            printf("DATABASE");
            gotoxy(50,24);
            printf("=== MENAMPILKAN ISI DATABASE ===");
            gotoxy(10,26);
            printf("+ ======================================================================================================================= +");

            gotoxy(10,28);
            printf("|Kode Barang");
            gotoxy(33,28);
            printf("|Nama Barang");
            gotoxy(56,28);
            printf("|Jenis Barang");
            gotoxy(79,28);
            printf("|Jumlah Barang");
            gotoxy(102,28);
            printf("|Harga Barang");

            for(i=0; i < banyakdata; i++){
                gotoxy(10,29+i+1);
                printf("|%s", toko[i].kode);
                gotoxy(33, 29+i+1);
                printf("|%s", toko[i].nama_barang);
                gotoxy(56, 29+i+1);
                printf("|%s", toko[i].jenis);
                gotoxy(79, 29+i+1);
                printf("|%s", toko[i].jumlah);
                gotoxy(102, 29+i+1);
                printf("|%s", toko[i].harga);
                printf("\n");
            }
            gotoxy(10,38);
            printf("+ ======================================================================================================================= +");
            strcpy(riwayat[riwayad].riwayat, "ADMIN MEMBUAT DATABASE");
            riwayad++;

            gotoxy(70,40);
            printf("\nKlik Apa Saja Untuk Melanjutkan....");
            getch();
            menu();
    }else{
        gotoxy(44,16);
        printf("Piliha Anda Salah....\n");
        getch();
        goto ulang;
    }
    // for(i=0; i<banyakdata;i++){
    //     int stringLenght = strlen(toko[i].kode);
    //     for(j=0; j<banyakdata-i-1; j++){
    //         if(toko[i].kode<toko[j+1].kode){ //besar ke kecil yang kecil ke besar belum bisa
    //             tempat=toko[i];
    //             toko[i]=toko[j+1];
    //             toko[j+1]=tempat;
    //         }
    //     }
    // }
    // system("cls");
    // gotoxy(10,3);
    // printf("+ ======================================================================================================================= +");
    // gotoxy(60,5);
    // printf("DATABASE");
    // gotoxy(50,6);
    // printf("=== MENAMPILKAN ISI DATABASE ===");
    // gotoxy(10,8);
    // printf("+ ======================================================================================================================= +");

    // gotoxy(10,10);
    // printf("|Kode Barang");
    // gotoxy(33,10);
    // printf("|Nama Barang");
    // gotoxy(56,10);
    // printf("|Jenis Barang");
    // gotoxy(79,10);
    // printf("|Jumlah Barang");
    // gotoxy(102,10);
    // printf("|Harga Barang");

    // for(i=0; i < banyakdata; i++){
    //     gotoxy(10,11+i+1);
    //     printf("|%s", toko[i].kode);
    //     gotoxy(33, 11+i+1);
    //     printf("|%s", toko[i].nama_barang);
    //     gotoxy(56, 11+i+1);
    //     printf("|%s", toko[i].jenis);
    //     gotoxy(79, 11+i+1);
    //     printf("|%s", toko[i].jumlah);
    //     gotoxy(102, 11+i+1);
    //     printf("|%s", toko[i].harga);
    //     printf("\n");
    // }
    // gotoxy(10,20);
    // printf("+ ======================================================================================================================= +");
    // strcpy(riwayat[riwayad].riwayat, "ADMIN MEMBUAT DATABASE");
    // riwayad++;

    // gotoxy(11,50);printf("\nKlik Apa Saja Untuk Melanjutkan....");
    // getch();
    // menu();
    //tampilDatabase();
}

void menu(){
    int pilihan;
    balik:
    system("cls");
    system("color 4f");
    gotoxy(30, 3);
    Sleep(1000);
    printf("+ ===================================================== +");
    Sleep(1000);
    gotoxy(30, 5);
    Sleep(1000);
    printf("          SELAMAT DATANG DI DATABASE TOKO BAGUNAN          \n");
    Sleep(1000);
    gotoxy(30, 6);
    Sleep(1000);
    printf("             ~~~ MENU TOKO BANGUNAN UNYUU ~~                 \n");
    Sleep(1000);
    gotoxy(30, 8);
    Sleep(1000);
    printf("+ ===================================================== +");
    gotoxy(30, 10);printf("|                                                      |");
    gotoxy(30, 11);printf("|   Tekan 1. MEMBUAT DATABASE                          |");
    gotoxy(30, 12);printf("|   Tekan 2. MENAMPILKAN ISI DATABASE                  |");
    gotoxy(30, 13);printf("|   Tekan 3. MENAMBAH DATA BARU KE DATABASE            |");
    gotoxy(30, 14);printf("|   Tekan 4. MENGHAPUS DATA PADA DATABASE              |");
    gotoxy(30, 15);printf("|   Tekan 5. MENGEDIT DATA PADA DATABASE               |");
    gotoxy(30, 16);printf("|   Tekan 6. MENCARI DATA PADA DATABASE                |");
    gotoxy(30, 17);printf("|   Tekan 7. RIWAYAT AKTIFITAS DATABASE                |");
    gotoxy(30, 18);printf("|   Tekan 8. MENGURUTKAN DATA PADA DATABASE            |");
    gotoxy(30, 19);printf("|   Tekan 9. KELUAR                                    |");
    gotoxy(30, 20);printf("|                                                      |");
    gotoxy(30, 21);printf("|   Masukkan pilihan Anda :                            |");
    gotoxy(30, 23);printf("+ =====================================================+");
    gotoxy(58,21);scanf("%d", &pilihan);

    if(pilihan==1){
        buatDatabase();
    }else if(pilihan==2){
        tampilDatabase();
    }else if(pilihan==3){
        tambahDatabase();
    }else if(pilihan==4){
        hapusDatabase();
    }else if(pilihan==5){
        editDatabase();
    }else if(pilihan==6){
        cariDatabase();
    }else if(pilihan==7){
        riwayatDatabase();
    }else if(pilihan==8){
        urutData();
    }else if(pilihan==9){
        keluar();
    }else{
        gotoxy(40,25);
        printf("Pilihan Anda Salah...");
        getch();
        goto balik;
    }
}

void keluar(){
    system("cls");
    system("color 7c");
    Sleep(1000);
    gotoxy(40,5);printf("****     *     *     *****\n");
    Sleep(1000);
    gotoxy(40,6);printf("*    *     * *       *    \n");
    Sleep(1000);
    gotoxy(40,7);printf("****        *        *****\n");
    Sleep(1000);
    gotoxy(40,8);printf("*    *      *        *    \n");
    Sleep(1000);
    gotoxy(40,9);printf("****        *        *****\n");
    Sleep(3000);
    gotoxy(40,15);printf("Bahar Lanang Prakosa\t(672020046)\n");
    gotoxy(40,16);printf("Krisna Adi Saputra\t(672020178)\n");
    gotoxy(40,17);printf("Ryan Agung Iskandar\t(672020236)\n");

    Sleep(5000);

    for(int i = 5; i >= 0; i--)
    {
        gotoxy(37,20);
        printf("Program akan keluar dalam %d\n", i);
        Sleep(1000);
    }
    gotoxy(35,23);printf("Terimakasih telah menggunakan database ini ^-^\n");
    Sleep(500);
    exit(0);
}

//login
void login(){
    balik:
    system("cls");
    struct tm *sys_tme;

    time_t Tval;
    Tval = time(NULL);
    sys_tme = localtime(&Tval);

    char username[15];
    char password[15];
    int benar = 0, salah = 1;

    system("color 7a");
    gotoxy(40,10);
    Sleep(1000);
    printf("  SELAMAT DATANG DI TOKO BANGUNAN \n");
    Sleep(1000);
    gotoxy(40,12);
    Sleep(1000);
    printf("======================================");
    Sleep(1000);
    gotoxy(40,16);
    Sleep(1000);
    printf("=====================================");
    // Mengatur Hari Bulan Tahun
    gotoxy(40,18);printf("%d/%d/%d", sys_tme->tm_mday, sys_tme->tm_mday+1, 1900+sys_tme->tm_year);
    // Mengatur Waktu
    gotoxy(68,18);printf("%d:%d", sys_tme->tm_hour, sys_tme->tm_min);
    gotoxy(40,13);printf("Masukkan Username : ");
    scanf("%s", &username);
    gotoxy(40,14);printf("\n");
    gotoxy(40,15);printf("Masukkan Password : ");
    scanf("%s", &password);
    gotoxy(40,19);
    printf("");

    if((strcmp(username, "admin")==0) && (strcmp(password, "admin")==0)){
        gotoxy(50,20);printf("Login Anda Berhasil!!\n");
        gotoxy(45,21);printf("Klik Apa Saja Untuk Melanjutkan....\n");
        gotoxy(72,21);getch();
        benar = 1;
        menu();
    }else{
        gotoxy(40,20);
        printf("Username atau Password Salah");
        getch();
        goto balik;
    }
}
