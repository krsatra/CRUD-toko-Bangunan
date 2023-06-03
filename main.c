#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>


struct toko{
    char kode[50];
    char harga[50], jumlah[50];
    char nama_barang[50], jenis[50];
};

struct history{
    char riwayat[100];
};

struct toko toko[50];
struct history riwayat[100];

void gotoxy();
void login();
void menu();
void tambahDatabase();
void tampilDatabase();
void hapusDatabase();
void edit();
void cari();
void hhistory();
void urut();
void keluar();

int banyakdata, banyaktambahdata, i, j, k;
int riwayad, found, total;
int arr;
int n=5;

char rriwayat[100][100];

int main(){
    login();
	//menu();
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



// Tampil Data Base
void tampilDatabase(){
    system("cls");
    gotoxy(10,3);
    Sleep(1000);
    printf("+ ========================================================================================================= +");
    gotoxy(60,5);
    Sleep(1000);
    printf("DATABASE");
    gotoxy(40,6);
    Sleep(1000);
    printf("=== MENAMPILKAN ISI DATABASE TOKO BANGUNAN TAYO ===");
    gotoxy(10,8);
    Sleep(1000);
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
    strcpy(rriwayat[riwayad], "ADMIN MENAMPILKAN DATABASE\n");
    riwayad++;

    gotoxy(11,30);printf("\nKlik Apa Saja Untuk Melanjutkan....");
    getch();
    menu();
}

//tambah data base
void tambahDatabase(){
    int b;
    char kode[100];

    system("cls");
    balik:
    gotoxy(30, 3);
    Sleep(1000);
    printf("+ ================================================= +");
    gotoxy(37, 5);
    Sleep(1000);
    printf("                 DATABASE                            ");
    gotoxy(37, 6);
    Sleep(1000);
    printf("    === MENAMBAHKAN ISI DATABASE ===        ");
    gotoxy(30, 8);
    Sleep(1000);
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
            printf("\nData Toko Bangunan Ke-%d\n", b + 1);

            gotoxy(32, 14+(b*6));
            printf("Kode Barang\t = ");
            fflush(stdin);
            scanf("%s", &toko[banyakdata].kode);
            for(j = 0; j < banyakdata; j++){
                if(strcmp(toko[j].kode, toko[banyakdata].kode)==0){
                    gotoxy(33,15+(j*b*6));
                    printf("\n Kode Sudah Ada\n\n");
                    gotoxy(35,17);
                    printf("Tekan Apa Saja Untuk Melanjutkan....");
                    getch();
                    system("cls");
                    goto balik;
                }
            }
            gotoxy(32, 15+(b*6));
            printf("Nama Barang\t = ");
            fflush(stdin);
            scanf("%s", &toko[banyakdata].nama_barang);

            gotoxy(32, 16+(b*6));
            printf("Jenis Barang\t = ");
            fflush(stdin);
            scanf("%s", &toko[banyakdata].jenis);

            gotoxy(32, 17+(b*6));
            printf("Jumlah Barang\t = ");
            fflush(stdin);
            scanf("%s", &toko[banyakdata].jumlah);

            gotoxy(32, 18+(b*6));
            printf("Harga Barang\t = ");
            fflush(stdin);
            scanf("%s", &toko[banyakdata].harga);
            banyakdata++;
        }

        strcpy(rriwayat[riwayad], "ADMIN MENAMBAH DATABASE\n");
        riwayad++;
        strcpy(toko[i].kode, toko[i].kode);
        i++;

        printf("\nKlik terserah untuk lanjut~ ");
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
    char kode[10], ans, i, j;

    system("cls");
    gotoxy(30,3);Sleep(1000);printf("+ ================================================= +");
    gotoxy(30,5);Sleep(1000);printf("                      DATABASE                      ");
    gotoxy(30,6);Sleep(1000);printf("         === MENGHAPUS ISI DATABASE ===    ");
    gotoxy(30,8);Sleep(1000);printf("+ ================================================= +");
    gotoxy(30,9);printf("      Masukkan kode barang yang ingin dihapus :       ");
    gotoxy(30,10);printf("+ ================================================= +");
    gotoxy(78,9);scanf("%s", &kode);

    if (banyakdata > 0) {
	    	for(i = 0; i < banyakdata; i++)
	    {
	        if(strcmp(kode, toko[i].kode) == 0)
	        {
	            gotoxy(32, 12);
	            printf(":: Data Toko Bangunan ::");
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
	                for(j = i; j <= banyakdata; j++)
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
	} else {
		gotoxy(31,12);
    printf("Kode belum ditambahkan");
	}
    strcpy(rriwayat[riwayad], "ADMIN MENGHAPUS DATABASE\n");
        riwayad++;
    gotoxy(23,11);
    printf("Kode %s tidak dapat ditemukan, silahkan coba lagi", kode);
    gotoxy(23,12);
    printf("Klik terserah untuk lanjut~ ");
    getch();
    system("cls");
    menu();
}

void cari() {
	cari:
	system("cls");
	
	int i;
	char kode[100];
	char pilih;
	bool ada = false;
	
	gotoxy(30,3);Sleep(1000);printf("+ ================================================= +");
    gotoxy(30,5);Sleep(1000);printf("                      DATABASE                      ");
    gotoxy(30,6);Sleep(1000);printf("         	 === MENCARI ISI DATABASE ===    ");
    gotoxy(30,8);Sleep(1000);printf("+ ================================================= +");
    gotoxy(30,9);printf("      Masukkan kode barang yang ingin dicari :       ");
    gotoxy(30,10);printf("+ ================================================= +");
    gotoxy(78,9);scanf("%s", &kode);

	for (i = 0; i < banyakdata; i++) {
		
		if ((strcmp(toko[i].kode, kode) == 0)) {
			gotoxy(32, 12);
            printf(":: Data Ditemukan ::");
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
			ada = true;
		    printf("Klik terserah untuk lanjut~ ");
		    getch();
			menu();
		}
	}
	
	if (ada == false) {
	gotoxy(30,12);printf("		Data dengan Kode %s tidak ditemukan", kode);
	gotoxy(30,14);printf("+ ================================================= +");
	gotoxy(30,16);printf("		   Ingin mengulang ?(y/n) : ");
	scanf("%s", &pilih);
	if (pilih == 'y' || pilih == 'Y') {
		goto cari;
	} else {
		menu();
	}
	}
	strcpy(rriwayat[riwayad], "ADMIN MENCARI DATABASE\n");
    riwayad++;
	
}

void urut() {
	system("cls");
	struct toko temp;
	int i,j,y,x,k = 0;
	int pilih,no;
	char *dasar [100];
    
    gotoxy(30,3);Sleep(1000);printf("+ ================================================= +");
    gotoxy(30,5);Sleep(1000);printf("                      DATABASE                      ");
    gotoxy(30,6);Sleep(1000);printf("          === Mengurutkan ISI DATABASE ===    ");
    gotoxy(30,8);Sleep(1000);printf("+ ================================================= +");
    
   	gotoxy(30,10);printf("Urutkan data berdasarkan :\n");
   	gotoxy(30,11);printf("1. Kode\n");
	gotoxy(30,12);printf("2. Nama barang\n");
   	gotoxy(30,13);printf("3. Jenis\n");
   	gotoxy(30,14);printf("4. Jumlah\n");
   	gotoxy(30,15);printf("5. Harga\n");
   	gotoxy(30,16);printf("Masukkan Pilihan : ");
   	scanf("%d", &pilih);
   	gotoxy(30,18);printf("Urutkan Data Secara : \n");
   	gotoxy(30,19);printf("1. Ascending\n");
	gotoxy(30,20);printf("2. Descending\n");
   	gotoxy(30,21);printf("Masukkan Pilihan : ");
   	scanf("%d", &no);
   	printf("\n");
   	
   	if (pilih == 1) {
   		
   		if (no == 1) {
   			dasar [100] = "BERDASARKAN KODE ASCENDING";
		} else if (no == 2) {
   			dasar [100] = "BERDASARKAN KODE DESCENDING";
		} 
   		
   		for (i = 0; i < banyakdata - 1; i++) {
			int min = i;	
			for (j = i + 1; j < banyakdata; j++) {
				if (no == 1) {
					if (strcmp(toko[min].kode, toko[j].kode) > 0) {					
					min = j;					
					}
				} else if (no == 2) {
					if (strcmp(toko[min].kode, toko[j].kode) < 0) {					
					min = j;					
					}
				}	
			}
			temp = toko [i];
			toko [i] = toko [min];
			toko [min] = temp;
		}
		   		
	} else if (pilih == 2) {
   		
   		if (no == 1) {
   			dasar [100] = "BERDASARKAN NAMA BARANG ASCENDING";
		} else if (no == 2) {
   			dasar [100] = "BERDASARKAN NAMA BARANG DESCENDING";
		}
   		
   		for (i = 0; i < banyakdata - 1; i++) {
			int min = i;	
			for (j = i + 1; j < banyakdata; j++) {
				if (no == 1) {
					if (strcmp(toko[min].nama_barang, toko[j].nama_barang) > 0) {					
					min = j;					
					}
				} else if (no == 2) {
					if (strcmp(toko[min].nama_barang, toko[j].nama_barang) < 0) {					
					min = j;					
					}
				}	
			}
			temp = toko [i];
			toko [i] = toko [min];
			toko [min] = temp;
		}
		   		
	} else if (pilih == 3) {
   		
   		if (no == 1) {
   			dasar [100] = "BERDASARKAN JENIS ASCENDING";
		} else if (no == 2) {
   			dasar [100] = "BERDASARKAN JENIS DESCENDING";
		}
   		
   		for (i = 0; i < banyakdata - 1; i++) {
			int min = i;	
			for (j = i + 1; j < banyakdata; j++) {
				if (no == 1) {
					if (strcmp(toko[min].jenis, toko[j].jenis) > 0) {					
					min = j;					
					}
				} else if (no == 2) {
					if (strcmp(toko[min].jenis, toko[j].jenis) < 0) {					
					min = j;					
					}
				}	
			}
			temp = toko [i];
			toko [i] = toko [min];
			toko [min] = temp;
		}
		   		
	} else if (pilih == 4) {
   		
   		if (no == 1) {
   			dasar [100] = "BERDASARKAN JUMLAH ASCENDING";
		} else if (no == 2) {
   			dasar [100] = "BERDASARKAN JUMLAH DESCENDING";
		} 
   		
   		for (i = 0; i < banyakdata - 1; i++) {
			int min = i;	
			for (j = i + 1; j < banyakdata; j++) {
				if (no == 1) {
					if (strcmp(toko[min].jumlah, toko[j].jumlah) > 0) {					
					min = j;					
					}
				} else if (no == 2) {
					if (strcmp(toko[min].jumlah, toko[j].jumlah) < 0) {					
					min = j;					
					}
				}	
			}
			temp = toko [i];
			toko [i] = toko [min];
			toko [min] = temp;
		}
	} else if (pilih == 5) {
   		if (no == 1) {
   			dasar [100] = "BERDASARKAN HARGA ASCENDING";
		} else if (no == 2) {
   			dasar [100] = "BERDASARKAN HARGA DESCENDING";
		} 
   		
   		for (i = 0; i < banyakdata - 1; i++) {
			int min = i;	
			for (j = i + 1; j < banyakdata; j++) {
				if (no == 1) {
					if (strcmp(toko[min].harga, toko[j].harga) > 0) {					
					min = j;					
					}
				} else if (no == 2) {
					if (strcmp(toko[min].harga, toko[j].harga) < 0) {					
					min = j;					
					}
				}	
			}
			temp = toko [i];
			toko [i] = toko [min];
			toko [min] = temp;
		}
		   		
	}
	
system("cls");
    gotoxy(10,3);
    printf("+ ========================================================================================================= +");
    gotoxy(60,5);
    printf("DATABASE");
    gotoxy(35,6);
    printf("=== MENAMPILKAN ISI DATABASE %s ===", dasar[100]);
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
    strcpy(rriwayat[riwayad], "ADMIN MENGURUTKAN DATABASE\n");
    riwayad++;

    gotoxy(11,30);printf("\nKlik Apa Saja Untuk Melanjutkan....");
    getch();
    menu();
	
}

void edit() {
	
    char kode[10], pilih;
    int i;
    struct toko ubah;
    bool ada = false;

	ubah:
    system("cls");
    gotoxy(30,3);Sleep(1000);printf("+ ================================================= +");
    gotoxy(30,5);Sleep(1000);printf("                      DATABASE                      ");
    gotoxy(30,6);Sleep(1000);printf("            === MENGUBAH ISI DATABASE ===    ");
    gotoxy(30,8);Sleep(1000);printf("+ ================================================= +");
    gotoxy(30,9);printf("      Masukkan kode barang yang ingin diubah :       ");
    gotoxy(30,10);printf("+ ================================================= +");
    gotoxy(78,9);scanf("%s", &kode);

    for(i = 0; i < banyakdata; i++)
    {
        if(strcmp(kode, toko[i].kode) == 0)
        {
            gotoxy(32, 12);
            printf(":: Masukkan Data ::");
            gotoxy(32, 13);
            printf(":: Kode Barang\t = ");
            scanf("%s", &ubah.kode);
            gotoxy(32, 14);
            printf(":: Nama Barang\t = ");
            scanf("%s", &ubah.nama_barang);
            gotoxy(32, 15);
            printf(":: Jenis Barang\t = ");
            fflush(stdin);
            scanf("%s", &ubah.jenis);
            gotoxy(32, 16);
            printf(":: Jumlah Barang\t = ");
            scanf("%s", &ubah.jumlah);
            gotoxy(32, 17);
            printf(":: Harga Barang\t = ");
            scanf("%s", &ubah.harga);

            toko[i] = ubah;
            ada = true;
        }
    }
    if (ada == false) {
            gotoxy(29,12);
            printf("Kode %s tidak dapat ditemukan, ingin coba lagi ? (y/n) : ", kode);
            scanf("%s", &pilih);
            if (pilih == 'y' || pilih == 'Y') { 
                goto ubah;
			} else {
				system("cls");
                menu();
			}
		}
    
    strcpy(rriwayat[riwayad], "ADMIN MENGEDIT DATABASE\n");
    riwayad++;
    gotoxy(32,19);
    printf("Klik Apa Saja Untuk Melanjutkan ");
    getch();
    system("cls");
    menu();
}

void hhistory () {
	
	system("cls");
    gotoxy(30,3);Sleep(1000);printf("+ ================================================= +");
    gotoxy(30,6);Sleep(1000);printf("\t\t=== RIWAYAT AKTIVITAS DATABASE ===");
    gotoxy(30,8);Sleep(1000);printf("+ ================================================= +");
	struct history riwayat[100];
	int i;
	for (i = 0; i < riwayad; i++) {	
        gotoxy(30, 11+i);
    	printf("\t%d. %s", i + 1, rriwayat[i]);
	}
    printf("\n\t\t\t\tKlik Apa Saja Untuk Melanjutkan ");
	getch();
    menu();
}

void menu(){
    int pilihan;
    balik:
    system("cls");
    system("color 4f");
    gotoxy(30,3);Sleep(1000);printf("+ ===================================================== +");
    gotoxy(30, 5);Sleep(1000);printf("          SELAMAT DATANG DI DATABASE TOKO BAGUNAN          \n");
    gotoxy(30, 6);Sleep(1000);printf("             ~~~ MENU TOKO BANGUNAN TAYO ~~                 \n");
    gotoxy(30, 8);Sleep(1000);printf("+ ===================================================== +");
    gotoxy(30, 10);printf("|                                                      |");
    gotoxy(30, 11);printf("|   Tekan 1. MENAMBAH DATA KE DATABASE                 |");
    gotoxy(30, 12);printf("|   Tekan 2. MENAMPILKAN ISI DATABASE                  |");
    gotoxy(30, 13);printf("|   Tekan 3. MENGHAPUS DATA PADA DATABASE              |");
    gotoxy(30, 14);printf("|   Tekan 4. MENGEDIT DATA PADA DATABASE               |");
    gotoxy(30, 15);printf("|   Tekan 5. MENCARI DATA PADA DATABASE                |");
    gotoxy(30, 16);printf("|   Tekan 6. RIWAYAT AKTIFITAS DATABASE                |");
    gotoxy(30, 17);printf("|   Tekan 7. MENGURUTKAN DATA PADA DATABASE            |");
    gotoxy(30, 18);printf("|   Tekan 8. KELUAR                                    |");
    gotoxy(30, 19);printf("|                                                      |");
    gotoxy(30, 20);printf("|   Masukkan pilihan Anda :                            |");
    gotoxy(30, 22);printf("+ =====================================================+");
    gotoxy(58,20);scanf("%d", &pilihan);

    if(pilihan==1){
        tambahDatabase();
    }else if(pilihan==2){
        tampilDatabase();
    }else if(pilihan==3){
        hapusDatabase();
    }else if(pilihan==4){
        edit();
    }else if(pilihan==5){
		cari();
    }else if(pilihan==6){
		hhistory();
    }else if(pilihan==7){
		urut();
    }else if(pilihan==8){
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

    for(i = 5; i >= 0; i--){
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
