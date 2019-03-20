/*
Nama Program	: exercise-01
Nama			: SITTI UFAIROH AZZAHRA
NPM				: 140810180002
Deskriptif		: program ini dibuat 
Tanggal			: 20 Maret 2019
*/

#include <iostream>

using namespace std;

struct Elemtlist{
	char nama[30];
	char bidang[20];
	long int gaji;
	Elemtlist* next;
};

typedef Elemtlist* pointer;
typedef pointer List;

void createList (List& First){
	First=NULL;
}

void createElemt (pointer& pBaru){
	pBaru = new Elemtlist;
	cout<<"\nNama       : ";cin.ignore();cin.getline(pBaru->nama,30);
    cout<<"Bidang     : ";cin.getline(pBaru->bidang,20);
    cout<<"Gaji       : ";cin>>pBaru->gaji;
    pBaru->next=NULL;
}

void insertFirst (List& First, pointer pBaru){
	if(First==NULL)
        First=pBaru;
    else{
        pBaru->next= First;
        First=pBaru;
	}
}

void traversal (List First){ // untuk mengecek
	int i=1;
	pointer pBantu;
	if (First==NULL){
        cout<<" List Kosong, Silahkan isi dulu "<<endl;
	}
	else{
    pBantu=First;
    	do{
            cout<<i<<"   "<<pBantu->nama<<"    "<<pBantu->bidang<<"     "<<pBantu->gaji<<endl;
            pBantu=pBantu->next;i++;
        } 
		while (pBantu!=NULL);
    }
    cout<<endl;
}

void deleteFirst(List& First, pointer& pHapus){
	if(First==NULL){  // untuk list yang kosong
		pHapus=NULL;
		cout<<"List kosong, tidak ada yang dihapus"<<endl;
	}
	else if(First->next==NULL){
		pHapus=First;
		First=NULL;
	}
	else{
		pHapus=First;
		First=First->next;
		pHapus->next=NULL;
	}
}

void insertLast(List& First, pointer pBaru){
	pointer last;
    if(First==NULL)
        First=pBaru;
    else{
        last=First;
        while(last->next != NULL){
            last=last->next;
        }
        last->next=pBaru;
    }
}

void deleteLast(List& First, pointer& pHapus){
	pointer last,precLast;
	if (First==NULL){  // untuk list kosong
        pHapus=NULL;
        cout<<"List kosong, tidak ada yang dihapus"<<endl;
    }
    else if (First->next==NULL){ // untuk 1 elemen
        pHapus=First;
        First=NULL; 
    }
    else { // untuk elemen lebih dari 1
        last=First; 
        precLast=NULL;
        while (last->next!=NULL)
        {
            precLast=last; // preclast mencatat yg akan ditinggalkan Last
            last=last->next; // last berpindah
        }
    pHapus=last;
    precLast->next=NULL;
    }
}

int main (){
	List First;
	pointer pegawai;
	pointer pHapus;
	int n;
	int menu;
	char pilih='y';
	createList(First);
	do {
		system("cls");
		
		cout << "===============Tampilan Data==============="<<endl;
		cout << "No  Nama        Bidang         Gaji" <<endl;
		traversal(First);
		cout<<endl;
		cout <<"\n===============Tampilan Menu=============="<<endl;
		cout <<"\t1. Insert First" <<endl;
		cout <<"\t2. Insert Last" <<endl;
		cout <<"\t3. Delete First" <<endl;
		cout <<"\t4. Delete Last" <<endl;
		cout <<"Masukkan Pilihan	: "; cin >>menu;
		cout <<"==========================================="<<endl;
		
		switch(menu){
			case 1 : 
    			createElemt(pegawai);
    			insertFirst(First,pegawai); 
				cout << "\nData Berhasil Dibuat"<<endl;
				break;
    		case 2 :
    			createElemt(pegawai);
    			insertLast(First,pegawai);
				cout << "\nData Berhasil Dibuat"<<endl;
				break;
    		case 3 : 
    			deleteFirst(First,pHapus);
				cout << "\nData Berhasil Dihapus"<<endl;
				break;
			case 4 :
				deleteLast(First,pHapus);
				cout << "\nData Berhasil Dihapus"<<endl;
				break;
			default :
            	cout<<"Pilihan salah, silahkan coba lagi"<<endl; break;	
		}
		cout << "Kembali ke menu?(Y/N)"; cin>>pilih;	
	}
	while (pilih == 'y' || pilih == 'Y');
}

