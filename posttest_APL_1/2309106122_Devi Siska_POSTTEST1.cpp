#include <iostream>
using namespace std;

int main() {
    string Nama, Nim;
    int salah = 3;
    // digunakan untuk menyimpan nilai percobaan login yang tersisa pada suatu program yang pada program ini sebanyak 3 kali

    cout << "========================================" <<endl;
    cout << "SELAMAT DATANG DI PROGRAM KONVERSI SUHU" <<endl;
    cout << "========================================" <<endl;
    cout << "" <<endl;
    cout << "SILAHKAN LOGIN TERLEBIH DAHULU " <<endl;
   
while (salah > 0) {
    // menegaskan bahwa jika percobaannya lebih besar dari 0 (login berhasil) maka akan mengeluarkan output selamat datang 
    // atau Jika nilai salahnya masih lebih besar dari 0, blok kode yang terdapat di dalam while akan dieksekusi, 
    // dan nilai salah akan dikurangi 1 setiap kali pengulangan dilakukan
	cout << "Masukkan nama: ";
    getline(cin, Nama);
    cout << "Masukkan Nim: ";
    cin >> Nim;
    cout << "" << endl;

    if (Nama == "Devi" && Nim == "122") {
        cout << "Selamat datang di program ini" << endl;
        cout << "" << endl;
        break;
    } else {
            salah--;
            cout << "Login Anda Gagal. Silahkan coba lagi." <<endl;
            cout << "Anda memiliki " << salah << " kesempatan lagi." <<endl;
        }
        cout << "" <<endl;
    }
    if (salah == 0) {
    // jika salah sama dengan 0 maka program akan dihentikan dan akan keluar output seperti di bawah ini.
        cout << "ANDA TELAH MELEBIHI BATAS PERCOBAAN. PROGRAM DIHENTIKAN!" <<endl;
        return 0;
        
    }

    cout << "" <<endl;
    int pilihan;
    double suhu;
    double hasil;
    char ulang;
do{
// digunakan untuk loop
    cout << "==================================================" <<endl;
    cout << "                  KONVERSI SUHU                   " << endl;
    cout << "==================================================" << endl;
    cout << "1. Konversi Celcius ke Reamur" << endl;
    cout << "2. Konversi Celcius ke Farenheit" << endl;
    cout << "3. Konversi Celcius ke Kelvin" << endl;
    cout << "4. Konversi Reamur ke Celcius" << endl;
    cout << "5. Konversi Reamur ke Farenheit" << endl;
    cout << "6. Konversi Reamur ke Kelvin" << endl;
    cout << "7. Konversi Farenheit ke Celcius" << endl;
    cout << "8. Konversi Farenheit ke Reamur" << endl;
    cout << "9. Konversi Farenheit ke Kelvin" << endl;
    cout << "10. Konversi Kelvin ke Celcius" << endl;
    cout << "11. Konversi Kelvin ke Reamur" << endl;
    cout << "12. Konversi Kelvin ke Farenheit" << endl;
    cout << "" <<endl;
    cout << "Silahkan Pilih Jenis Konversi yang Anda Inginkan :  ";
    cin >> pilihan;
    cout << "Masukkan suhu: ";
    cin >> suhu;
    
    switch (pilihan) {
    // penggunaan switch digunakan untuk pengambilan sebuah keputusan dalam berbagai macam kondisi yang ada. penggunaan
    // switch juga lebih cocok digunakan dengan penggunaan banyak kondisi dibandingkan penggunaan if-else
        case 1:
            hasil = (4.0 / 5.0) * suhu;
            cout << "Hasil konversi: " << hasil << " Reamur" << endl;
            break;
        case 2:
            hasil = (9.0 / 5.0) * suhu + 32.0;
            cout << "Hasil konversi: " << hasil << " Farenheit" << endl;
            break;
        case 3:
            hasil = suhu + 273.15;
            cout << "Hasil konversi: " << hasil << " Kelvin" << endl;
            break;
        case 4:
            hasil = (5.0 / 4.0) * suhu;
            cout << "Hasil konversi: " << hasil << " Celcius" << endl;
            break;
        case 5:
            hasil = (9.0 / 4.0) * suhu + 32.0;
            cout << "Hasil konversi: " << hasil << " Farenheit" << endl;
            break;
        case 6:
            hasil = (5.0 / 4.0) * suhu + 273.15;
            cout << "Hasil konversi: " << hasil << " Kelvin" << endl;
            break;
        case 7:
            hasil = (5.0 / 9.0) * (suhu - 32.0);
            cout << "Hasil konversi: " << hasil << " Celcius" << endl;
            break;
        case 8:
            hasil = (4.0 / 9.0) * (suhu - 32.0);
            cout << "Hasil konversi: " << hasil << " Reamur" << endl;
            break;
        case 9:
            hasil = (5.0 / 9.0) * (suhu - 32.0) + 273.15;
            cout << "Hasil konversi: " << hasil << " Kelvin" << endl;
            break;
        case 10:
            hasil = suhu - 273.15;
            cout << "Hasil konversi: " << hasil << " Celcius" << endl;
            break;
        case 11:
            hasil = 4.0 / 5.0 * (suhu - 273.15);
            cout << "Hasil konversi: " << hasil << " Reamur" << endl;
            break;
        case 12:
            hasil = 9.0 / 5.0 * (suhu - 459.67);
            cout << "Hasil konversi: " << hasil << " Farenheit" << endl;
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
            break;
    }
    cout << "Devi! Apakah anda ingin memilih jenis konversi yang lain? (Y/N) ";
    cin >> ulang;
}
    while (ulang == 'Y' || ulang == 'y');
    // dimaksudkan utuk dapat menggunakan char Y besar ataupun y kecil
    cout << "Terimakasih " << Nama << " telah menggunakan Program Konversi Suhu Ini ";
    return 0;
}


