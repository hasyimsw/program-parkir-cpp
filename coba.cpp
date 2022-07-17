#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>

using namespace std;

int pilih;
int biaya_motor = 2000;
int biaya_mobil = 4000;
void pilihan();

struct Parkir
{
    char plat[20];
    int lama;
    string mobil, motor;
    int info;

    Parkir *prev, *next;
};

Parkir *data, *top = NULL, *help, *del, *q;

void BUAT_Parkir(int X)
{
    data = (Parkir *)malloc(sizeof(Parkir));
    if (data != NULL)
    {
        data->info = X;
    }
    else
    {
        cout << "Membuat Parkir gagal";
        exit(1);
    }
}

void buat_data() // fungsi membuat data data
{
    data = new (Parkir);
    int pil;

    cout << "Masukkan kendaraan" << endl;
    cout << "1. Mobil" << endl;
    cout << "2. Motor" << endl;
    cout << "------------------" << endl;
    cout << "Pilih: ";
    cin >> pil;

    if (pil == 1)
    {
        data->mobil = "mobil";
        cout << "Masukkan plat: ";
        cin >> data->plat;
        cout << "Masukkan lama parkir: ";
        cin >> data->lama;
        cout << "\n==========================";
        cout << "\nData telah ditambahkan";
        getch();
    }
    else if (pil == 2)
    {
        data->motor = "motor";
        cout << "Masukkan plat: ";
        cin >> data->plat;
        cout << "Masukkan lama parkir: ";
        cin >> data->lama;
        cout << "\n==========================";
        cout << "\nData telah ditambahkan";
        getch();
    }
    else
    {
        cout << "Pilihan tidak tersedia" << endl;
    }

    data->prev = NULL;
    data->next = NULL;
}

void input_data()

{
    buat_data();
    if (top == NULL)
    {
        top = data;
        top->next = NULL;
    }
    else
    {
        data->next = top;
        top = data;
    }
    cout << endl;
}

void hapus_data() // fungsi penghapusan data
{
    int hapus;
    if (top == NULL)
    {
        cout << "Parkiran kosong, \nPenghapusan tidak dapat dilakukan" << endl;
    }
    else
    {
        hapus = top->info;
        cout << "Data terakhir sudah dihapus";
        del = top;
        top = top->next;
        delete del;
        getch();
    }
}

void cetak_data()
{
    cout << "Data telah urut sesuai jam parkir" << endl;
    if (top == NULL)
    {
        cout << "Parkiran kosong!";
        getch();
    }
    else
    {
        help = top;
        while (help != NULL)
        {
            if (help->mobil == "mobil")
            {
                cout << "Plat : " << help->plat << endl;
                cout << "Lama prakir: " << help->lama << " jam | Biaya : " << help->lama * biaya_mobil << endl;
                cout << endl;
                help = help->next;
            }
            else
            {
                cout << "Plat : " << help->plat << endl;
                cout << "Lama prakir: " << help->lama << " jam | Biaya : " << help->lama * biaya_motor << endl;
                cout << endl;
                help = help->next;
            }
        }
        getch();
    }
}

int main() // interface monitor
{
    do
    {

        system("cls");
        cout << ".:. PROGRAM PARKIR MOTOR .:." << endl;
        cout << "=============================" << endl;
        cout << "1. INPUT DATA KENDARAAN" << endl;
        cout << "2. HAPUS DATA" << endl;
        cout << "3. LIHAT DATA KENDARAAN" << endl;
        cout << "4. KELUAR" << endl;
        cout << "=============================" << endl;
        cout << "Pilihan : ";
        cin >> pilih;
        cout << "=============================" << endl;
        cout << endl;

        pilihan();
    } while (pilih != 4);
}

void pilihan() // fungsi "pilihan" untuk pemrosesan
{
    if (pilih == 1)
    {
        input_data();
    }
    else if (pilih == 2)
    {
        hapus_data();
    }
    else if (pilih == 3)
    {
        cetak_data();
    }
    else
    {
        cout << "Terima kasih sudah menggunakan program ini" << endl;
    }
}