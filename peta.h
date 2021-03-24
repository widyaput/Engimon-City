#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>
#include <map>
#include "Engimon2.h"
using namespace std;

#ifndef PETA_HPP
#define PETA_HPP
// #define SIZE_ROW 14
// #define SIZE_COL 14
#define MIN_LEVEL 5
#define MAX_LEVEL 10
#define MAX_SPAWN 20

class Peta {
    private :
        int baris;
        int kolom;
        int nElmt;
        char *isiPeta;
        char *PetaTetap;
        //static int engimonId;
        vector<pair<int, Engimon> > DaftarEngimon; //vector of engimon buat nyimpan engimon apa saja yang ada pada peta
        //^terdiri dari int yang merupakan posisi dari engimon liar dalam peta dan Engimon liar
        //Engimon *DaftarEngimon; 
        //vector<int> PosisiEngimon; //ini mending dijadiin vector of point deh
        int BykEngimonLiar;

    public :
    	//ctor user defined
        Peta(int b, int k);
        
        //cctor
        Peta(const Peta& P);
        
        //dtor
        ~Peta();
        
        //operator assigment
        Peta& operator=(const Peta& P);
        
        //Get&Set
        char GetElementPeta(int b, int k);
        char GetElementPeta(int posisi);
        char GetElementPetaTetap(int b, int k);
        char GetElementPetaTetap(int posisi);
        void SetElementPeta(int b, int k, char element);
        void SetElementPeta(int index, char element);
        int GetBanyakEngimonLiar();
        Engimon GetEngimonLiar(int x, int y); //untuk dapetin engimon pada posisi (x,y)
        pair<int, Engimon> GetEngimonforDelete(int x, int y);
        //static int GetEngimonId();
        
        //Baca file dan isi element pada peta sesuai dengan isi file txt
        void BacaFile();
        
        //Print isi Peta
        void PrintPeta();
        //void PrintDaftarEngimon();
        void PrintPosisiEngimon();
        
        //Untuk masukin engimon yang telah dibuat ke daftarEngimon
        void AddEngimon(pair<int, Engimon> e);
        
        //Hapus engimon dari daftarEngimon
        void DeleteEngimon(pair<int, Engimon> e); //masih belum bisa
        int selectlevel(char engimonTerpilih);
        //void SelectEngimon(Species* *spesies, char e, Skill* *skill);
        void CreateEngimon(char e, int level, Engimon *engi);
        //spawn engimon
        //algoritma random
        /* 
		1. Cari ambil suatu titik dalam peta yang belum ditempati oleh engimon apapun
        2. Liat apakah di titik tsb grass atau sea
        3. Pilih engimon yang sesuai dengan tempat
        4. Masukin dalam array engimon yang sudah ada
        */
        void SpawnEngimon(int BanyakSpawn);
    
        void TukarPosisi(int posisi, int posisisekarang);
        //engimon bergerak
        /*
        1. Dari array of engimon yang sudah ada itu diubah lokasinya di dalam peta
        */
        void GerakinSemuaEngimon();
        
        
};

#endif
