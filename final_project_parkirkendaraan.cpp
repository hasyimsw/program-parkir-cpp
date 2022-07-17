#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;
#define MAX 200

struct Kendaraan
{
	string platNomor[MAX];
	string tipeKendaraan[MAX];
	int lamaParkir[MAX];
	int id[MAX];
	int awal, akhir;
} antrean;

void init()
{
	antrean.awal = 0;
	antrean.akhir = 0;
}

bool cekKosong()
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

bool parkiranPenuh()
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

void inputData(int jmlKendaraan)
{
	string temp1;
	int temp2, type;
	for (int i = 0; i < jmlKendaraan; i++)
	{
		if (antrean.akhir < jmlKendaraan + antrean.akhir)
		{
			cout << "Antrean Nomor [" << antrean.akhir + 1 << "]" << endl;
			if (i == 0)
			{
				cin.ignore();
			}
			cout << "Masukkan tipe kendaraan: ";
			cin >> type;
			if (type == 1)
			{
				antrean.tipeKendaraan[antrean.akhir] = "Mobil";
			}
			else if (type == 2)
			{
				antrean.tipeKendaraan[antrean.akhir] = "Motor";
			}
			cout << "Masukkan plat nomor  : ";
			cin >> temp1;
			cout << "Masukkan lama parkir : ";
			cin >> temp2;

			antrean.platNomor[antrean.akhir] = temp1;
			antrean.id[antrean.akhir] = antrean.akhir;
			antrean.lamaParkir[antrean.akhir] = temp2;
			antrean.id[antrean.akhir] = antrean.akhir;
			antrean.akhir++;

			cout << "Berhasil menambahkan data." << endl;
			cout << endl;
		}
	}
}
void cekKendaraan()
{
	for (int i = antrean.awal; i < antrean.akhir; i++)
	{
		if (antrean.tipeKendaraan[i] == "Mobil")
		{
			cout << "Antrean Kendaraan Nomor [" << antrean.id[i] + 1 << "]" << endl;
			cout << "Tipe Kendaraan\t: " << antrean.tipeKendaraan[i] << endl;
			cout << "Plat Nomor\t: " << antrean.platNomor[i] << endl;
			cout << "Lama Parkir\t: " << antrean.lamaParkir[i] << " jam | Biaya: Rp. " << antrean.lamaParkir[i] * 4000 << endl;
			cout << endl;
		}
		else if (antrean.tipeKendaraan[i] == "Motor")
		{
			cout << "Antrean Kendaraan Nomor [" << antrean.id[i] + 1 << "]" << endl;
			cout << "Tipe Kendaraan\t: " << antrean.tipeKendaraan[i] << endl;
			cout << "Plat Nomor\t: " << antrean.platNomor[i] << endl;
			cout << "Lama Parkir\t: " << antrean.lamaParkir[i] << " jam | Biaya: Rp. " << antrean.lamaParkir[i] * 2000 << endl;
			cout << endl;
		}
	}
}
// dequeque
void kendaraanKeluar()
{
	for (int i = 0; i <= antrean.akhir; i++)
	{
		antrean.id[i] = antrean.id[i + 1];
		antrean.platNomor[i] = antrean.platNomor[i + 1];
		antrean.lamaParkir[i] = antrean.lamaParkir[i + 1];
		antrean.tipeKendaraan[i] = antrean.tipeKendaraan[i + 1];
	}
}

// bubble sort ascending
/*
void sortPlat()
{
	string temp1;
	int temp2;
	for (int i = antrean.awal; i < antrean.akhir; i++)
	{
		for (int j = i + 1; j < antrean.akhir; j++)
		{
			if (antrean.platNomor[j] < antrean.platNomor[i])
			{
				// untuk platNomor
				temp1 = antrean.platNomor[i];
				antrean.platNomor[i] = antrean.platNomor[j];
				antrean.platNomor[j] = temp1;
				
				temp2 = antrean.lamaParkir[i];
				antrean.lamaParkir[i] = antrean.lamaParkir[j];
				antrean.lamaParkir[j] = temp2;
			}
		}
	}
}
*/
// bubble sort ascending
void sortlamaParkir()
{
	string temp1;
	int temp2;
	for (int i = antrean.awal; i < antrean.akhir; i++)
	{
		for (int j = i + 1; j < antrean.akhir; j++)
		{
			if (antrean.lamaParkir[j] < antrean.lamaParkir[i])
			{
				temp1 = antrean.platNomor[i];
				antrean.platNomor[i] = antrean.platNomor[j];
				antrean.platNomor[j] = temp1;
				// untuk id Kendaraan
				temp2 = antrean.lamaParkir[i];
				antrean.lamaParkir[i] = antrean.lamaParkir[j];
				antrean.lamaParkir[j] = temp2;
			}
		}
	}
}

// sequential search
void cariKendaraan(string cari)
{
	int cariPlat[MAX];
	int j = 0;
	for (int i = antrean.awal; i < antrean.akhir; i++)
	{
		if (antrean.platNomor[i] == cari)
		{
			cariPlat[j] = i;
			j++;
		}
	}
	if (j > 0)
	{
		cout << endl;
		cout << "Plat Nomor Kendaraan  " << cari << endl;
		cout << "Data ditemukan!" << endl;
	}
	else
	{
		cout << "Data tidak ditemukan!" << endl;
	}
}
// clear all data
void clearData()
{
	antrean.akhir = 0;
}

int main()
{
	int jmlKendaraan, pil;
	string cari;
	init();

	do
	{
	menu:
		system("cls");
		cout << "------------ .:. Program Parkir Kendaraan .:. -----------" << endl;
		cout << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << "| Menu:\t\t\t\t\t\t\t|" << endl;
		cout << "| 1. Input Data\t\t\t\t\t\t|" << endl;
		cout << "| 2. View Data\t\t\t\t\t\t|" << endl;
		cout << "| 3. Keluarkan Kendaraan Dari Parkiran\t\t\t|" << endl;
		cout << "| 4. Urutkan Data Lama Parkir  \t\t\t\t|" << endl;
		cout << "| 5. Cari Kendaraan (Plat Nomor)\t\t\t|" << endl;
		cout << "| 6. Bersihkan Parkiran Dari Kendaraan\t\t\t|" << endl;
		cout << "| 7. Keluar\t\t\t\t\t\t|" << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << endl;

		cout << "Masukan pilihan: ";
		cin >> pil;
		system("cls");

		switch (pil)
		{
		// Input Data Kendaraan
		case 1:
			if (parkiranPenuh() == true)
			{
				cout << "Parkiran Sudah Penuh!" << endl;
			}
			else
			{
				cout << ".:. Input Data Kendaraan .:." << endl;
				cout << endl;
				cout << "Tipe Kendaraan: " << endl;
				cout << "1. Mobil | Biaya: Rp. 4000 / jam" << endl;
				cout << "2. Motor | Biaya: Rp. 2000 / jam" << endl;
				cout << endl;
				cout << "Masukkan Jumlah Kendaraan: ";
				cin >> jmlKendaraan;
				cout << endl;
				inputData(jmlKendaraan);
			}
			getch();
			break;
		// view data kendaraan
		case 2:
			if (cekKosong() == true)
			{
				cout << "Silahkan input kendaraan terlebih dahulu!" << endl;
			}
			else
			{
				cout << "\t.:. Daftar Kendaraan .:." << endl;
				cout << endl;
				cekKendaraan();
			}
			getch();
			break;
		// Keluarkan kendaraan dari parkiran
		case 3:
			if (cekKosong() == true)
			{
				cout << "Silahkan input kendaraan terlebih dahulu!" << endl;
			}
			else
			{
				kendaraanKeluar();
			}
			cekKendaraan();
			getch();
			break;
		// Urutkan Data lama parkir secara ascending
		case 4:
			if (cekKosong() == true)
			{
				cout << "Silahkan input Kendaraan terlebih dahulu!" << endl;
			}
			else
			{
				sortlamaParkir();
			}
			cekKendaraan();
			getch();
			break;
		// Urutkan Data Kendaraan Berdasarkan Plat Nomor Ascending
		/*
		case 5:
			if (cekKosong() == true)
			{
				cout << "Silahkan input Kendaraan terlebih dahulu!" << endl;
			}
			else
			{
				sortPlat();
			}
			cekKendaraan();
			getch();
			break;
		*/	
		// Cari Data Kendaraan
		case 5:
			cout << "Masukan plat kendaraan yang ingin dicari: ";
			cin.ignore();
			getline(cin, cari);
			cariKendaraan(cari);
			getch();
			break;
		// Bersihkan Parkiran Dari Kendaraan
		case 6:
			cout << "Menghapus data..." << endl;
			clearData();
			cout << "Data sudah berhasil dihapus!" << endl;
			getch();
			break;
		case 7:
			cout << "Keluar Dari Program..." << endl;
			break;
		default:
			cout << "Masukkan pilihan sesuai di menu!" << endl;
			getch();
			goto menu;
		}
	} while (pil != 7);
}