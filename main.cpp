#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Ogrenci {
    string ad;
    string soyad;
    string sinif;
    string dogum_tarihi;
    string veli_telefon;
};

class AnaOkulu {
public:
    Ogrenci* ogrenciler;
    int ogrenciSayisi;
public:
    AnaOkulu() {
        ogrenciler = nullptr;
        ogrenciSayisi = 0;
    }

    void ekle(string ad, string soyad, string sinif, string dogum_tarihi, string veli_telefon) {
        Ogrenci* yeni_ogrenci = new Ogrenci();
        yeni_ogrenci->ad = ad;
        yeni_ogrenci->soyad = soyad;
        yeni_ogrenci->sinif = sinif;
        yeni_ogrenci->dogum_tarihi = dogum_tarihi;
        yeni_ogrenci->veli_telefon = veli_telefon;

        Ogrenci* temp = new Ogrenci[ogrenciSayisi + 1];
        for (int i = 0; i < ogrenciSayisi; i++) {
            temp[i] = ogrenciler[i];
        }
        temp[ogrenciSayisi] = *yeni_ogrenci;

        delete[] ogrenciler;
        ogrenciler = temp;
        ogrenciSayisi++;

        cout << "Ogrenci basariyla eklendi." << endl;
    }

    void tumliste() {
        if (ogrenciSayisi == 0) {
            cout << "Liste bos." << endl;
            return;
        }
        for (int i = 0; i < ogrenciSayisi; i++) {
            Ogrenci* ogrenci = &ogrenciler[i];
            cout << "------------------------------" << endl;
            cout << "Ad: " << ogrenci->ad << endl;
            cout << "Soyad: " << ogrenci->soyad << endl;
            cout << "Sinif: " << ogrenci->sinif << endl;
            cout << "Dogum Tarihi: " << ogrenci->dogum_tarihi << endl;
            cout << "Veli Telefon: " << ogrenci->veli_telefon << endl;
            cout << "------------------------------" << endl;
        }
    }

    void sinifilistele(string sinif) {
        bool bulundu = false;
        for (int i = 0; i < ogrenciSayisi; i++) {
            Ogrenci* ogrenci = &ogrenciler[i];
            if (ogrenci->sinif == sinif) {
                cout << "------------------------------" << endl;
                cout << "Ad: " << ogrenci->ad << endl;
                cout << "Soyad: " << ogrenci->soyad << endl;
                cout << "Sinif: " << ogrenci->sinif << endl;
                cout << "Dogum Tarihi: " << ogrenci->dogum_tarihi << endl;
                cout << "Veli Telefon: " << ogrenci->veli_telefon << endl;
                cout << "------------------------------" << endl;
                bulundu = true;
            }
        }

        if (!bulundu) {
            cout << "Belirtilen sinifta ogrenci bulunamadi." << endl;
        }
    }

    void listeyeaktar() {
        ifstream dosya;
        dosya.open("ogrenciler.dat", ios::binary);

        if (!dosya) {
            cout << "Dosya acma hatasi." << endl;
            return;
        }

        dosya.seekg(0, ios::end);
        int fileSize = dosya.tellg();
        dosya.seekg(0, ios::beg);

        int ogrenciSayisi = fileSize / sizeof(Ogrenci);
        Ogrenci* temp = new Ogrenci[ogrenciSayisi];

        dosya.read(reinterpret_cast<char*>(temp), fileSize);

        dosya.close();

        delete[] ogrenciler;
        ogrenciler = temp;
        this->ogrenciSayisi = ogrenciSayisi;

        cout << "Ogrenci kayitlari basariyla aktarildi." << endl;
    }

    void kaydet() {
        ofstream dosya;
        dosya.open("ogrenciler.dat", ios::binary);

        if (!dosya) {
            cout << "Dosya acma hatasi." << endl;
            return;
        }

        dosya.write(reinterpret_cast<char*>(ogrenciler), ogrenciSayisi * sizeof(Ogrenci));

        dosya.close();

        cout << "Kayitlar disk dosyasina basariyla kaydedildi." << endl;
    }

    ~AnaOkulu() {
        delete[] ogrenciler;
    }
};

void menu() {
    cout << "Ana Okulu Ogrenci Kayit Programi" << endl;
    cout << "1. Yeni Ogrenci Ekle" << endl;
    cout << "2. Tum Ogrencileri Listele" << endl;
    cout << "3. Sinifa Gore Ogrencileri Listele" << endl;
    cout << "0. Cikis" << endl;
    cout << "Seciminizi yapin: ";
}

int main() {
    system("echo off");
    system("cls");
    system("color a");
    AnaOkulu okul;

    okul.listeyeaktar();

    int secim;
    while (true) {
        menu();
        cin >> secim;

        if (secim == 1) {
            string ad, soyad, sinif, dogum_tarihi, veli_telefon;
            cout << "Ad: ";
            cin.ignore();
            getline(cin, ad);
            cout << "Soyad: ";
            getline(cin, soyad);
            cout << "Sinif: ";
            getline(cin, sinif);
            cout << "Dogum Tarihi: ";
            getline(cin, dogum_tarihi);
            cout << "Veli Telefon: ";
            getline(cin, veli_telefon);
            okul.ekle(ad, soyad, sinif, dogum_tarihi, veli_telefon);
        } else if (secim == 2) {
            okul.tumliste();
        } else if (secim == 3) {
            string sinif;
            cout << "Sinif: ";
            cin.ignore();
            getline(cin, sinif);
            okul.sinifilistele(sinif);
        } else if (secim == 0) {
            okul.kaydet();
            break;
        } else {
            cout << "Gecersiz secim." << endl;
        }
    }

    return 0;
}
