#include <iostream>
#include <iomanip>
using namespace std;

void tampilkanMenu() {
    cout << "===== MENU KEDAI AYAM =====\n";
    cout << "1. Ayam Goreng (Rp17.000)\n";
    cout << "2. Ayam Bakar (Rp21.000)\n";
    cout << "3. Selesai dan Cetak Struk\n";
    cout << "===========================\n";
}

void hitungDanCetakStruk(int jumlah_goreng, int jumlah_bakar) {
    const int HARGA_AYAM_GORENG = 17000;
    const int HARGA_AYAM_BAKAR = 21000;
    const double BATAS_DISKON = 45000;
    const double PERSENTASE_DISKON = 0.1;

    double total_harga = (jumlah_goreng * HARGA_AYAM_GORENG) + (jumlah_bakar * HARGA_AYAM_BAKAR);
    double diskon = total_harga > BATAS_DISKON ? total_harga * PERSENTASE_DISKON : 0;
    double total_bayar = total_harga - diskon;

    cout << "\n===== STRUK PEMBAYARAN =====\n";
    cout << "Ayam Goreng\t: " << jumlah_goreng << " x Rp" << HARGA_AYAM_GORENG 
         << " = Rp" << (jumlah_goreng * HARGA_AYAM_GORENG) << endl;
    cout << "Ayam Bakar\t: " << jumlah_bakar << " x Rp" << HARGA_AYAM_BAKAR 
         << " = Rp" << (jumlah_bakar * HARGA_AYAM_BAKAR) << endl;
    cout << "Total Harga\t: Rp" << total_harga << endl;

    if (diskon > 0) {
        cout << "Diskon (10%)\t: -Rp" << fixed << setprecision(2) << diskon << endl;
    }

    cout << "Total Bayar\t: Rp" << fixed << setprecision(2) << total_bayar << endl;
    cout << "============================\n";
}

int main() {
    int jumlah_goreng = 0, jumlah_bakar = 0;
    char pilihan;

    do {
        tampilkanMenu();
        cout << "Pilih menu (1/2/3): ";
        cin >> pilihan;

        switch (pilihan) {
            case '1':
                int temp_goreng;
                cout << "Masukkan jumlah Ayam Goreng: ";
                cin >> temp_goreng;
                jumlah_goreng += temp_goreng;
                break;
            case '2':
                int temp_bakar;
                cout << "Masukkan jumlah Ayam Bakar: ";
                cin >> temp_bakar;
                jumlah_bakar += temp_bakar;
                break;
            case '3':
                hitungDanCetakStruk(jumlah_goreng, jumlah_bakar);
                return 0;
            default:
                cout << "Pilihan tidak valid! Silakan pilih lagi.\n";
        }

        cout << "\nIngin memilih menu lain? (y/t): ";
        cin >> pilihan;

    } while (pilihan == 'y');
}
