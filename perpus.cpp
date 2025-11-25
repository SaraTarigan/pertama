#include <iostream>
#include <iomanip>
using namespace std;

int main () {
    int chance, banyak_buku, no_opsi, tambahan_buku;
    string UN, user, pw, nim, next, cek_buku;
    
    bool login, ditemukan;
   
	int stok[100] = {17, 8, 0};
	string penulis[100] = {"Leila S. Chudori", "George Orwell", "W. K. Liotohe"};
	string judul[100] = {"Laut Bercerita", "Animal Farm", "10 Dosa Besar Soeharto"};
	
	banyak_buku = 3;
    UN = "tita";	
    nim = "014";
    chance = 3;
	
	cout << setfill('=') << setw(5) << "="
		 << " Login Ke Database Perpustakaan " 
		 << setfill('=') << setw(5) << "=" << endl;
	
    while (chance > 0) {
        cout << "Username\t: ";
        cin >> user;
        cout << "Password\t: ";
        cin >> pw;

        if (pw != nim && user != UN) {
            cout << "Password dan Username Salah!" << endl;
            login = false;
            chance--;
            if (chance > 0) {
                cout << "Kesempatan Tersisa: " << chance << endl;
                cout << endl;
            }
        }
        else if (pw == nim && user != UN) {
            cout << "Username Salah!" << endl;
            login = false;
            chance--;
            if (chance > 0) {
                cout << "Kesempatan Tersisa: " << chance << endl;
                cout << endl;
            }
        }
        else if (pw != nim && user == UN) {
            cout << "Password Salah!" << endl;
            login = false;
            chance--;
            if (chance > 0) {
                cout << "Kesempatan Tersisa: " << chance << endl;
                cout << endl;
            }
        }
        else {
            cout << "Login Berhasil" << endl << endl;
            system ("cls");
            login = true;
            break;
        }
	}
		
	if (login == true) {
		do{
		system ("cls");
		cout << setfill('=') << setw(21) << "="
		 << "DATABASE PERPUSTAKAAN" 
		 << setfill('=') << setw(21) << "=" << endl;
		 
		 cout << "[1] Lihat Data Buku" << endl;
		 cout << "[2] Tambah Data Buku" << endl;
		 cout << "[3] Cek Ketersediaan Buku" << endl;
		 cout << "[0] Logout" << endl;
		 
		 int salah_opsi = 0;
			do {
				cout << ">> ";
				cin >> no_opsi;
				if (no_opsi < 0 || no_opsi > 3) {
					salah_opsi++;
					cout << "Opsi di luar jangkauan.\n\nMasukkan Nilai Baru!" << endl;
					if(salah_opsi >= 6){
						system("cls");
						cout << "Program keluar.\nTerlalu Banyak Kesalahan Dalam Memasukkan Opsi menu!!!\n";
						return 0;
					}
				}

			} while (no_opsi < 0 || no_opsi > 3);
		
		system ("cls");
		
		if(no_opsi==1){
		 	
			cout << setfill('-') << setw(62) << "-" << endl; //batas atas tabel
			cout << setfill(' ') << "| " << setw(25) << left << "Judul"
				<< "| " << setw(25) << left << "Penulis"
				<< "| " << setw(5) << left << "Stok" << "|\n";
			cout << setfill('-') << setw(62) << "-" << endl;
	
			for (int i = 0; i < banyak_buku; i++) {
				cout << setfill(' ') << "| " << setw(25) << left << judul[i]
				<< "| " << setw(25) << left << penulis[i]
				<< "| " << setw(5) << left << stok[i] << "|\n";
			}
			cout << setfill('-') << setw(62) << "-" << endl;
			
			cout << endl;
			cout << "Lanjut ke Menu (Y/N): ";
			cin >> next;
			cin.ignore();
			
		system ("cls");	
		}
		
		else if (no_opsi==2){
			
			cout << "Banyak Data Buku Baru Yang Hendak Diinput: ";
			cin >> tambahan_buku;
			
			cin.ignore();
			cout << endl;
			
			for (tambahan_buku; tambahan_buku  > 0; tambahan_buku--) {
				cout << "Data Buku Ke-" << banyak_buku + 1 << endl;
				cout << "Input Judul Buku\t: ";
				getline(cin, judul[banyak_buku]);
				cout << "Input Penulis Buku\t: ";
				getline(cin, penulis[banyak_buku]);
				cout << "Input Stok Buku\t\t: ";
				cin >> stok[banyak_buku];
				cin.ignore();
				cout << endl;
				
				banyak_buku = banyak_buku + 1;
			}
			cout << endl;
			cout << "Lanjut ke Menu (Y/N): ";
			cin >> next;
			
			cin.ignore();
			
		system("cls");
		}
		
		else if (no_opsi == 3) {
				cout << setfill('=') << setw(5) << "="
					 << " Cek Stok Buku " 
					 << setfill('=') << setw(5) << "=" << endl;
					 cout << "Input Judul Buku\t: ";
					 cin.ignore();
					 getline(cin, cek_buku);

					 ditemukan = false;

					for (int i = 0; i < banyak_buku; i++) {
						if (cek_buku == judul[i]) {
							ditemukan = true;
						if (stok[i] > 0) {
							cout << "Buku \"" << judul[i] << "\" tersedia. Stok saat ini: " << stok[i] << " buku." << endl;
						} 
						else {
							cout << "Tidak ada copy dari buku \"" << judul[i] << "\" yang tersedia." << endl;
						}
						break;
					}
				}
					if (!ditemukan) {
						cout << "Buku \"" << cek_buku << "\" tidak tersedia dalam database." << endl;
					}
				cout << endl;
				cout << "Lanjut ke Menu (Y/N): ";
				cin >> next;
				system("cls");
		}
		
		else if (no_opsi == 0){
			cout << "Anda Telah Logout" ;
			return 0;
		}
		
		} while (next == "Y" || next == "y");
	}
    else {
        cout << "Kesempatan Habis, Login Gagal!" << endl;
    }
	
    return 0;
}


