#ifndef ENGIMON_H
#define ENGIMON_H

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip> 
#include "Skill.h"
#include "Species.h"
#include "CustomException.h"
using namespace std;
        
class Engimon{
    private:
        Species* species;
        string name;
        pair<pair<string, string>, pair<string, string>> parent; 
        vector<Skill> skills;
        //string1 = nama species, string2 = nama parent
        int level; 
        int EXP; 
        int cumulativeEXP;
        bool status; // btw kalau engimon mati bakalan dihapus dari program, apa masih perlu ini? hmmm iya juga ya
        bool wild;
        const int maxCumulative = 2000;
        const int maxSkill = 4;

    public:
        // default ctor
        Engimon();

        // user defined
        // species diambil dari SpeciesFactory

        // ctor biasa
        Engimon(Species* _species, string _name, 
        pair<pair<string, string>, pair<string, string>> _parent, int _level, 
        int _EXP, int _cumulativeEXP, bool _status, bool _wild);
        
        // ctor dengan argument parent = string dan skill engimon diambil dari skill bawaan
        Engimon(Species* _species, string _name, string specParA, string nameParA, 
        string specParB, string nameParB, int _level, int _EXP, int _cumulativeEXP, 
        bool _status, bool _wild);

        // ctor dengan argument parent = string dan skill engimon diambil dari argumen _skills
        Engimon(Species* _species, string _name, string specParA, string nameParA, 
        string specParB, string nameParB, vector<Skill> _skills, int _level, int _EXP,
        int _cumulativeEXP, bool _status, bool _wild);

        // ctor untuk wild engimon
        // asumsi wild engimon tanpa nama dan parent?
        Engimon(Species* _species, int _level, int _EXP, int _cumulativeEXP, 
        bool _status, bool _wild);

        // ctor untuk wild engimon dengan skill > 1 jika mungkin (tanpa skill bawaan)
        // asumsi wild engimon tanpa nama dan parent?
        Engimon(Species* _species, vector<Skill> _skills, int _level, int _EXP, int _cumulativeEXP, 
        bool _status, bool _wild);
        
        // dtor
        ~Engimon();
        
        //operator overload
        bool operator==(const Engimon& engi);
        Engimon& operator=(const Engimon& engi);
        friend ostream& operator<<(ostream& os, const Engimon& engimon);

        // getter, seperlunya saja
        int getLevel() const;
        int getEXP() const;
        int getCumulativeEXP() const;
        pair<pair<string, string>, pair<string, string>> getParent() const;
        Species* getSpecies() const;
        string getSpeciesName() const;
        bool isWild() const;
        string getName() const;
        vector<Skill> getSkills() const;
		vector<Element> getElement() const;
        bool getStatus() const;
        float getAdvantageElement(Element _elm2) const; // adv elm player terhadap elm2
        vector<vector<float>> getAdvElementTable() const;
        
        // setter, seperlunya saja
        void printDetail();
        void setParent(string speciesA, string parentA, string speciesB, string parentB);
        void setStatus(bool _status);
		void setWild(bool _wild);	

        // fungsi lain
        void rename(string _name);
        void upLevel(int incr); // Menaikan level sebesar incr
        void downLevel(int decr); // Menurunkan level decr
        void addEXP(int exp); // Menambahkan EXP sebesar exp sekaligus mengecek :
        // 1. Apabila EXP > 100 maka naik level dan reset EXP (0/100)
        // 2. Apabila cumulativeEXP > maxCumulativeEXP maka status = false

        void addSkill(Skill skill); // Menambahkan skill engimon dengan pengecekan supaya tidak ada skill yang sama
        // Throw apabila elemen invalid
        // Throw sesuatu apabila penuh
        // Elemen skill diinisiasi di awal dan hanya bisa diakses lewat SkillsFactory dan kemungkinan urutan elemen akan selalu sama karena skill tidak pernah diubah atributnya kecuali mastery levelnya
        void dropSkill(Skill skill); // Menghapus skill engimon dengan asumsi Skill skill dimiliki engimon 
        bool checkNumOfElements() const; // kalau 1 itu true, kalau 2 false
        void printASCII();
        int getSpeciesIndex() const;
        static float countPower(Engimon& e,float adv);
        static float advantage(Engimon& e1,Engimon& e2,int n);
};

// Katalog engimon sepertinya tida diperlukan, diganti dengan SpeciesFactory

#endif