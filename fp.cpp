#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;
// MAX gudang
#define MAX 200
// struct
struct barang
{
	// array data
	string data[MAX];
	// array id
	int id[MAX];
	int awal, akhir;
} antrean;
// inisiasi antrian
void init()
{
	antrean.awal = 0;
	antrean.akhir = 0;
}
// check apakah parkiran kosong
bool checkKosong()
{
	if (antrean.akhir == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// check apakah parkiran penuh
bool gudangPenuh()
{
	if (antrean.akhir == MAX)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// inqueque
void inputData(int jmlKendaraan)
{
	cout << "Masukkan data kendaraan!" << endl;
	cout << "1. Merek Motor" << endl;
	cout << "2. Plat Nomor" << endl;
	cout << "3. Lama Parkir" << endl;
	cout << "------------------------" << endl;
	cout << endl;
	string temp;
	for (int i = 0; i < jmlKendaraan; i++)
	{
		if (antrean.akhir < jmlKendaraan + antrean.akhir)
		{
			cout << " ";
			if (i == 0)
			{
				cin.ignore();
			}
			getline(cin, temp);

			antrean.data[antrean.akhir] = temp;
			antrean.id[antrean.akhir] = antrean.akhir;
			antrean.akhir++;
		}
	}
	cout << "~Data sudah masuk~" << endl;
}
void periksaBarang()
{
	for (int i = antrean.awal; i < antrean.akhir; i++)
	{
		cout << "barang dengan id ke-" << antrean.id[i] << " = " << antrean.data[i] << endl;
	}
}
// dequeque
void barangKeluar()
{
	for (int i = 0; i < antrean.akhir; i++)
	{
		antrean.id[i] = antrean.id[i + 1];
		antrean.data[i] = antrean.data[i + 1];
	}
}

// bubble sort ascending
void sortNama()
{
	string temp1;
	int temp2;
	for (int i = antrean.awal; i < antrean.akhir; i++)
	{
		for (int j = i + 1; j < antrean.akhir; j++)
		{
			if (antrean.data[j] < antrean.data[i])
			{
				// untuk data
				temp1 = antrean.data[i];
				antrean.data[i] = antrean.data[j];
				antrean.data[j] = temp1;
			}
		}
	}
}
// bubble sort ascending
void sortID()
{
	string temp1;
	int temp2;
	for (int i = antrean.awal; i < antrean.akhir; i++)
	{
		for (int j = i + 1; j < antrean.akhir; j++)
		{
			if (antrean.id[j] < antrean.id[i])
			{
				// untuk id Barang
				temp2 = antrean.id[i];
				antrean.id[i] = antrean.id[j];
				antrean.id[j] = temp2;
			}
		}
	}
}
// bubble sort descending
void sortIDDescending()
{
	string temp1;
	int temp2;
	for (int i = antrean.awal; i < antrean.akhir; i++)
	{
		for (int j = i + 1; j < antrean.akhir; j++)
		{
			if (antrean.id[j] > antrean.id[i])
			{
				// untuk id Barang
				temp2 = antrean.id[i];
				antrean.id[i] = antrean.id[j];
				antrean.id[j] = temp2;
			}
		}
	}
}
// bubble sort descending
void sortNamaDescending()
{
	string temp1;
	int temp2;
	for (int i = antrean.awal; i < antrean.akhir; i++)
	{
		for (int j = i + 1; j < antrean.akhir; j++)
		{
			if (antrean.id[j] > antrean.id[i])
			{
				// untuk data
				temp1 = antrean.data[i];
				antrean.data[i] = antrean.data[j];
				antrean.data[j] = temp1;
			}
		}
	}
}
// sequential search
void cariBarang(string cari)
{
	int searchNama[MAX];
	int j;
	j = 0;
	for (int i = antrean.awal; i < antrean.akhir; i++)
	{
		if (antrean.data[i] == cari)
		{
			searchNama[j] = i;
			j++;
		}
	}
	if (j > 0)
	{
		cout << "data yang dicari adalah : " << cari << endl;
		cout << "data tersebut terdapat index array ke : ";
		for (int i = 0; i < j; i++)
		{
			cout << searchNama[i] << endl;
		}
	}
	else
	{
		cout << "data tidak di temukan " << endl;
	}
}
// clear all
void hapusSemuaData()
{
	antrean.akhir = 0;
}

int main()
{
	// tipe data & variabel
	int jmlKendaraan;
	int menu;
	string caridata;
	// memanggil fungsi init
	init();
	// perulangan do while
	do
	{
		system("cls");
		cout << ".:. Program Parkir .:." << endl;
		cout << "Silahkan pilih : " << endl;
		cout << "\t 1. Input Data " << endl;
		cout << "\t 2. Lihat data" << endl;
		cout << "\t 3. Keluarkan dari gudang" << endl;
		cout << "\t 4. Urutkan Data berdasarkan ID (Ascending)" << endl;
		cout << "\t 5. Urutkan Data berdasarkan Nama Barang (Ascending)" << endl;
		cout << "\t 6. Urutkan Data berdasarkan ID (Descending)" << endl;
		cout << "\t 7. Urutkan Data berdasarkan Nama (Descending" << endl;
		cout << "\t 8. Cari Data" << endl;
		cout << "\t 9. Bersihkan Gudang dari barang" << endl;
		cout << "\t 10. keluar \n"
			 << endl;

		cout << "Masukan pilihan :";
		cin >> menu;
		system("cls");

		switch (menu)
		{
		// Input Data
		case 1:
			if (gudangPenuh() == true)
			{
				cout << "Gudang Sudah Penuh" << endl;
			}
			else
			{
				jmlKendaraan = 3;
				inputData(jmlKendaraan);
			}
			getch();
			break;
		// Lihat data
		case 2:
			if (checkKosong() == true)
			{
				cout << "Silahkan input barang terlebih dahulu" << endl;
			}
			else
			{
				periksaBarang();
			}
			getch();
			break;
		// Keluarkan dari gudang
		case 3:
			if (checkKosong() == true)
			{
				cout << "Silahkan input barang terlebih dahulu" << endl;
			}
			else
			{
				barangKeluar();
			}
			periksaBarang();
			getch();
			break;
		// Urutkan Data berdasarkan ID secara ascending
		case 4:
			if (checkKosong() == true)
			{
				cout << "Silahkan input barang terlebih dahulu" << endl;
			}
			else
			{
				sortID();
			}
			break;
		// urutkan Data berdasarkan Nama Barang ascending
		case 5:
			if (checkKosong() == true)
			{
				cout << "Silahkan input barang terlebih dahulu" << endl;
			}
			else
			{
				sortNama();
			}
			break;
		// sortBy ID Descending
		case 6:
			cout << "Sorting By id Descending" << endl;
			sortIDDescending();
			break;
		// Sort By Name Descending
		case 7:
			cout << "Sorting By name Descending" << endl;
			sortNamaDescending();
			break;
		// Cari Data
		case 8:
			cout << " Masukan nama barang yang ingin dicari :";
			cin.ignore();
			getline(cin, caridata);
			cariBarang(caridata);
			getch;
			break;
		// Bersihkan Gudang dari barang
		case 9:
			cout << "Menghapus data..." << endl;
			hapusSemuaData();
			cout << "Data sudah berhasil dihapus" << endl;
			getch();
			break;

		case 10:
			cout << "Keluar dari program" << endl;
			getch();
			break;
		default:
			cout << "Masukan angka sesuai di menu!" << endl;
			getch();
			break;
		}
	} while (menu != 10);
}
