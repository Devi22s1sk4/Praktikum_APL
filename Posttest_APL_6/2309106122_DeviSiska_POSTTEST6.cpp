#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Hadiah {
    string nama;
    int jumlah;
};

void tampilkanData(const Hadiah* hadiah, int jumlahHadiah) {
    cout << "Data Hadiah Natal:\n";
    for (int i = 0; i < jumlahHadiah; i++) {
        cout << i + 1 << ". " << hadiah[i].nama << " - " << hadiah[i].jumlah << " buah\n";
    }
}

void tambahkanHadiah(Hadiah* daftarHadiah, int& jumlahHadiah) {
    if (jumlahHadiah < 100) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Masukkan Nama Hadiah: ";
        getline(cin, daftarHadiah[jumlahHadiah].nama);
        cout << "Masukkan Jumlah Hadiah: ";
        cin >> daftarHadiah[jumlahHadiah].jumlah;

        if (cin.fail()) {
            cout << "Input tidak valid. Masukkan angka.\n";
            cin.clear();
            return;
        }

        jumlahHadiah++;
        cout << "Data berhasil ditambahkan.\n";
    } else {
        cout << "Maaf, jumlah hadiah sudah mencapai batas maksimum.\n";
    }
}

void ubahHadiah(Hadiah* daftarHadiah, int jumlahHadiah) {
    int nomorHadiah;
    cout << "Masukkan nomor hadiah yang ingin diubah: ";
    cin >> nomorHadiah;
    nomorHadiah--;

    if (nomorHadiah >= 0 && nomorHadiah < jumlahHadiah) {
        cout << "Masukkan Nama Hadiah Baru: ";
        cin.ignore();
        getline(cin, daftarHadiah[nomorHadiah].nama);
        cout << "Masukkan Jumlah Hadiah Baru: ";
        cin >> daftarHadiah[nomorHadiah].jumlah;

        if (cin.fail()) {
            cout << "Input tidak valid. Masukkan angka.\n";
            cin.clear();
            return;
        }

        cout << "Data berhasil diubah.\n";
    } else {
        cout << "Nomor hadiah tidak valid.\n";
    }
}

void hapusHadiah(Hadiah* daftarHadiah, int& jumlahHadiah) {
    int nomorHadiah;
    cout << "Masukkan nomor hadiah yang ingin dihapus: ";
    cin >> nomorHadiah;
    nomorHadiah--;

    if (nomorHadiah >= 0 && nomorHadiah < jumlahHadiah) {
        for (int i = nomorHadiah; i < jumlahHadiah - 1; i++) {
            daftarHadiah[i] = daftarHadiah[i + 1];
        }
        jumlahHadiah--;
        cout << "Data berhasil dihapus.\n";
    } else {
        cout << "Nomor hadiah tidak valid.\n";
    }
}

void login(string& namaUser, int& nimUser, int attempt = 0) {
    if (attempt < 3) {
        cout << "Masukkan Nama: ";
        cin >> namaUser;
        cout << "Masukkan NIM: ";
        cin >> nimUser;

        if (namaUser == "Devi" && nimUser == 122) {
            cout << "Login berhasil!\n";
        } else {
            cout << "Login gagal. Silakan coba lagi.\n";
            login(namaUser, nimUser, attempt + 1);
        }
    } else {
        cout << "Gagal login sebanyak 3 kali. Program berhenti." << endl;
        exit(0);
    }
}

void bubbleSortDescending(Hadiah* daftarHadiah, int jumlahHadiah) {
    for (int i = 0; i < jumlahHadiah - 1; i++) {
        for (int j = 0; j < jumlahHadiah - i - 1; j++) {
            if (daftarHadiah[j].nama < daftarHadiah[j + 1].nama) {
                swap(daftarHadiah[j], daftarHadiah[j + 1]);
            }
        }
    }
}

void bubbleSortAscendingByNumber(Hadiah* daftarHadiah, int jumlahHadiah) {
    for (int i = 0; i < jumlahHadiah - 1; i++) {
        for (int j = 0; j < jumlahHadiah - i - 1; j++) {
            if (daftarHadiah[j].jumlah > daftarHadiah[j + 1].jumlah) {
                swap(daftarHadiah[j], daftarHadiah[j + 1]);
            }
        }
    }
}

int binarySearchAscending(const Hadiah* daftarHadiah, int jumlahHadiah, const string& target) {
    int low = 0;
    int high = jumlahHadiah - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (daftarHadiah[mid].nama == target) {
            return mid;
        } else if (daftarHadiah[mid].nama < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}

int binarySearchDescending(const Hadiah* daftarHadiah, int jumlahHadiah, const string& target) {
    int low = 0;
    int high = jumlahHadiah - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (daftarHadiah[mid].nama == target) {
            return mid;
        } else if (daftarHadiah[mid].nama > target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}

void menu(Hadiah* daftarHadiah, int& jumlahHadiah) {
    int pilihan;

    cout << "\nSELAMAT DATANG DI PROGRAM HADIAH NATAL INI\n";
    cout << "--------------------------------------------";
    cout << "\nSILAHKAN PILIH MENU\n";
    cout << "1. Tampilkan Hadiah Natal\n";
    cout << "2. Tambahkan Hadiah Natal\n";
    cout << "3. Ubah Hadiah Natal\n";
    cout << "4. Hapus Hadiah Natal\n";
    cout << "5. Urutkan Hadiah Secara Descending (Nama)\n";
    cout << "6. Urutkan Hadiah Secara Ascending (Jumlah)\n";
    cout << "7. Cari Hadiah Secara Ascending\n";
    cout << "8. Cari Hadiah Secara Descending\n";
    cout << "9. Keluar\n";
    cout << "Pilih menu: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            tampilkanData(daftarHadiah, jumlahHadiah);
            break;
        case 2:
            tambahkanHadiah(daftarHadiah, jumlahHadiah);
            break;
        case 3:
            ubahHadiah(daftarHadiah, jumlahHadiah);
            break;
        case 4:
            hapusHadiah(daftarHadiah, jumlahHadiah);
            break;
        case 5:
            bubbleSortDescending(daftarHadiah, jumlahHadiah);
            cout << "Data berhasil diurutkan secara descending berdasarkan nama.\n";
            break;
        case 6:
            bubbleSortAscendingByNumber(daftarHadiah, jumlahHadiah);
            cout << "Data berhasil diurutkan secara ascending berdasarkan jumlah.\n";
            break;
        case 7: {
            string targetAsc;
            cout << "Masukkan nama hadiah yang ingin dicari secara ascending: ";
            cin.ignore();
            getline(cin, targetAsc);
            int resultAsc = binarySearchAscending(daftarHadiah, jumlahHadiah, targetAsc);
            if (resultAsc != -1) {
                cout << "Hadiah ditemukan pada indeks " << resultAsc + 1 << ": " << daftarHadiah[resultAsc].nama << " - " << daftarHadiah[resultAsc].jumlah << " buah\n";
            } else {
                cout << "Hadiah tidak ditemukan.\n";
            }
            break;
        }
        case 8: {
            string targetDesc;
            cout << "Masukkan nama hadiah yang ingin dicari secara descending: ";
            cin.ignore();
            getline(cin, targetDesc);
            int resultDesc = binarySearchDescending(daftarHadiah, jumlahHadiah, targetDesc);
            if (resultDesc != -1) {
                cout << "Hadiah ditemukan pada indeks " << resultDesc + 1 << ": " << daftarHadiah[resultDesc].nama << " - " << daftarHadiah[resultDesc].jumlah << " buah\n";
            } else {
                cout << "Hadiah tidak ditemukan.\n";
            }
            break;
        }
        case 9:
            cout << "Program berhenti, Terima kasih telah menggunakan program Hadiah Natal ini!";
            return;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
    }

    menu(daftarHadiah, jumlahHadiah);
}

int main() {
    string namaUser;
    int nimUser;

    login(namaUser, nimUser);

    Hadiah daftarHadiah[100] = {
        {"Buku", 5},
        {"Boneka", 10},
        {"Gaun Pesta", 3},
        {"Lego", 7},
        {"Sepatu heels", 4},
        {"Perhiasan", 6},
        {"Tas", 8},
        {"Gitar", 9}
    };
    int jumlahHadiah = 8;

    menu(daftarHadiah, jumlahHadiah);

    return 0;
}

