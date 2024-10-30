#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

//========================================================

void tambahAwal(node **head);
void tambahData(node **head);
void tranverse(node *head);
void insertNode(node **head, node *pPre, node *pNew);
void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusTengah(node **head, int bil);
void hapusAkhir(node **head);
void cariData(node *head, int bil);
void jumlahData(node *head);
void jumlahkanData(node *head);

//========================================================

int main()
{
    node *head;
    char pilih;

    head = NULL;
    do{
        system("cls");
        printf("masukkan pilihan\n");
        printf("1. tambah data di awal\n");
        printf("2. tambah data di tengah list\n");
        printf("3. tambah data di akhir list\n");
        printf("4. cetak isi list\n");
        printf("5. hapus data di awal list\n");
        printf("6. hapus data di tengah list\n");
        printf("7. hapus data di akhir list\n");
        printf("8. cari data dalam list\n");
        printf("9. jumlah data dalam list\n");
        printf("10. jumlahkan data dalam list\n");
        printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
        fflush(stdin);
        scanf(" %c", &pilih);
        if (pilih == '1')
            tambahAwal(&head);
        else if (pilih == '2')
            tambahData(&head);
        else if (pilih == '3')
            tambahAkhir(&head);
        else if (pilih == '4'){
            tranverse(head);
            getch();
        }
        else if (pilih == '5')
            hapusAwal(&head);
        else if (pilih == '6'){
            int bil;
            printf("Masukkan bilangan yang ingin dihapus: ");
            scanf("%d", &bil);
            hapusTengah(&head, bil);
        }
        else if (pilih == '7')
            hapusAkhir(&head);
        else if (pilih == '8'){
            int bil;
            printf("Masukkan bilangan yang ingin dicari: ");
            scanf("%d", &bil);
            cariData(head, bil);
        }
        else if (pilih == '9')
            jumlahData(head);
        else if (pilih == '1' + '0') // fix for multi-character character constant
            jumlahkanData(head);
    } while (pilih != 'q');

    return 0;
}

//========================================================

void tambahAwal(node **head){
    int bil;
    node *pNew;

    system("cls");
    fflush(stdin);
    printf("masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL){
        pNew->data = bil;
        pNew->next = *head;
        if (*head != NULL) {
            node *pLast = *head;
            while (pLast->next != *head) {
                pLast = pLast->next;
            }
            pLast->next = pNew;
        } else {
            pNew->next = pNew;
        }
        *head = pNew;
    }
    else{
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void tambahData(node **head){
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nposisi penyisipan setelah data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nbilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = *head;
    while (pCur->next != *head && pCur->data != pos) {
        pCur = pCur->next;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pCur == NULL){
        printf("\nnode tidak ditemukan");
        getch();
    }
    else if (pNew == NULL){
        printf("\nalokasi memeori gagal");
        getch();
    }
    else{
        pNew->data = bil;
                pNew->next = pCur->next;
        pCur->next = pNew;
        if (*head == pCur) {
            *head = pNew;
        }
    }
}

//========================================================

void tranverse(node *head){
    //traverse a circular linked list
    node *pWalker;

    system("cls");
    pWalker = head;
    do {
        printf("%d\t", pWalker->data);
        pWalker = pWalker->next;
    } while (pWalker != head);
    printf("\n");
}

//========================================================

void tambahAkhir(node **head) {
    int bil;
    node *pNew, *pLast;

    system("cls");
    fflush(stdin);
    printf("masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = *head;
        if (*head == NULL) {
            pNew->next = pNew;
            *head = pNew;
        } else {
            pLast = *head;
            while (pLast->next != *head) {
                pLast = pLast->next;
            }
            pLast->next = pNew;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void hapusAwal(node **head) {
    node *pTemp, *pLast;

    if (*head != NULL) {
        pLast = *head;
        while (pLast->next != *head) {
            pLast = pLast->next;
        }
        pTemp = *head;
        *head = (*head)->next;
        pLast->next = *head;
        free(pTemp);
    } else {
        printf("List kosong");
        getch();
    }
}

//========================================================

void hapusTengah(node **head, int bil) {
    node *pCur, *pPre;

    pPre = NULL;
    pCur = *head;
    do {
        if (pCur->data == bil) {
            if (pPre == NULL) {
                *head = pCur->next;
            } else {
                pPre->next = pCur->next;
            }
            free(pCur);
            return;
        }
        pPre = pCur;
        pCur = pCur->next;
    } while (pCur != *head);
    printf("Node tidak ditemukan");
    getch();
}

//========================================================

void hapusAkhir(node **head) {
    node *pCur, *pPre;

    pPre = NULL;
    pCur = *head;
    do {
        pPre = pCur;
        pCur = pCur->next;
    } while (pCur->next != *head);
    pPre->next = pCur->next;
    free(pCur);
}

//========================================================

void cariData(node *head, int bil) {
    node *pWalker;

    pWalker = head;
    do {
        if (pWalker->data == bil) {
            printf("Data ditemukan");
            getch();
            return;
        }
        pWalker = pWalker->next;
    } while (pWalker != head);
    printf("Data tidak ditemukan");
    getch();
}

//========================================================

void jumlahData(node *head) {
    int count = 0;
    node *pWalker;

    pWalker = head;
    do {
        count++;
        pWalker = pWalker->next;
    } while (pWalker != head);
    printf("Jumlah data: %d", count);
    getch();
}

//========================================================

void jumlahkanData(node *head) {
    int sum = 0;
    node *pWalker;

    pWalker = head;
    do {
        sum += pWalker->data;
        pWalker = pWalker->next;
    } while (pWalker != head);
    printf("Jumlahkan data: %d", sum);
    getch();
}