#include<iostream>
using namespace std;

const int MAX = 5;

struct stack {
    int data [MAX];
    int top;

    void initialize(){
        top = -1;
    }

    bool isEmpty(){
        return top == -1;
    }

    bool isfull(){

        return top == MAX -1;
    }

    void push(int value){
        if(isfull()){
            cout<< "stack penuh! tidak bisa menambah daya.\n";
        }else{
            data[++top] = value;
            coutt<<"elemen " << value << " berhasil ditambahkan ke stack.\n";
        }
    }

    void pop(){
        if(isEmpty()){
            cout << "stack kosong! tidak ada elemen yang bisa dihapus.\n";
        }else {
            cout << "elemen " << data[top--] << " berhasil dihapus dari datcak.\n";
        }
    }

    void stacktop(){
        if(isEmpty()){
            cout << "stack kosong! tidak ada elemen di puncak.\n";
        }else{
            cout << "elemen teratas  " << data[top] << endl;
        }
    }

    int stackcount(){
        return top + 1;
    }

    void destroy(){
        top = -1;
        cout << "stack berhasil dikosongkan.\n";
    }
};

int main(){
    stack stack;
    stack.initialize();
    int pilihan, nilai;

    do{
        cout << "\nMenu Stack :\n";
        cout << "1. Push (tambah elemen)\n";
        cout << "2. Pop (hapus elemen)\n";
        cout << "3. Top (lihat elemen teratas)\n";
        cout << "4. cek apakah kosong\n";
        cout << "5. cek apakah penuh\n";
        cout << "6. hitung jumlah elemen\n";
        cout << "7. Destroy (kosongkan stack)\n";
        cout << "8. keluar\n";
        cout << "pilih opsi : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "masukkan nilai : ";
            cin >> nilai;
            stack.push(nilai);
            break;
        
        case 2:
            stack.pop();
            break;

        case 3:
            stack.stacktop();
            break;

        case 4:
            cout << (stack.isEmpty() ? "stack kosong.\n" : "stack tidak kosong.\n");
            break;

        case 5:
            cout << (stack.isfull() ? "stack penuh.\n" : "stack tidak penuh.\n");
            break;
        
        case 6:
            cout << "jumlah elemen dalam stack : " << stack.stackcount() << endl;
            break;
        
        case 7:
            stack.destroy();
            break;
        
        case 8:
            cout << "program selesai.\n";
            break;

        default:
            cout << "pilihan tidak valid! coba lagi.\n";
        } 
    }while (pilihan != 8);

   return 0; 
}