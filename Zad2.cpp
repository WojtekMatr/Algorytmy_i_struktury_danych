//WCY21KY1S1 WOJCIECH MATRAS
#include<iostream>
#include<fstream>                       //bedziemy dzialac na plikach

using namespace std;
typedef struct Node                     //tworzymy liste jednokierunkowa z int'em
{
	int data;
	struct Node* next;
} Node;
void sito(bool *tab, unsigned int n)
{
	for (int i=2; i*i<=n; i++)          //przeszukujemy kolejnych kandydatów na pierwsze
    {							        //wystarczy sprawdziæ do pierwiastka z n
                                        // i<=sqrt(n) - podnosz¹c do kwadratu mamy
                                        // i*i <= n
        if(tab[i] == 0)			            //jesli liczba jest pierwsza(ma wartosc 0)
		for (int j = i*i ; j<=n; j+=i)  //to wykreslamy jej wielokrotnosci
            tab[j] = 1;			        //ustawiaj¹c wartosæ na 1
    }
}
void insert(Node** pointerToHead, int x)                    //funkcja dodajaca kolejna liczbe pierwsza do kolejki
{                                                           //po wykonaniu funkcji sita w main'ie dostajemy tablice n-elementowa bool, jesli w n-elemencie tab[n]=1 znaczy to
	Node* temp=(Node*)malloc(sizeof(struct Node));          //ze w tym miejscu jest nowa liczba pierwsza
	temp->data = x;
	temp->next=*pointerToHead;
	if(*pointerToHead != NULL) temp->next=*pointerToHead;
	*pointerToHead = temp;
}
void drukuj(Node* head)                                      //funkcja drukujaca liste
{   int i =0;
    printf("\n");
	while(head != NULL)                                     //dopoki head != NULL drukujemy wartosci listy
	{
		printf("%d   ", head->data);
		i++;                                                // naliczamy i by program nie drukowal w jednej lini wszystkich wyrazow
		if (i%7==0){                                        // co 7 wyraz przechodzimy na nastepna linie
		printf("\n");
		}
		head = head->next;

}
}
void zapisdoPliku(Node *head) {                             //funkcja zapisujaca liste do Pliku.txt
fstream new_file;                                           //tworzymy Plik
new_file.open("new_file_write.txt",ios::out);               //otwieramy Plik
if(!new_file)
{
printf("\n");
cout<<"File creation failed";
}
else
{

while(head != NULL)                                         //dopoki head != NULL wypisujemy kolejne elementy do Pliku
	{
		new_file<<head->data<<" ";                          //wpisujemy do Pliku
		head = head->next;
	}
new_file.close();                                           //Zamykamy nowy Plik
}
}


int main()

{
    Node* head ;                                            //tworzymy wskaznik na glowe listy
	head=NULL;
    int n;                                                  //n to liczba do ktorej szukamy liczb pierwszych w zakresie od [2,n]

	cout<<"Podaj zakres górny przedzia³u: ";
	cin>>n;                                                 //wczytujemy n
	bool m[n+1];                                            //tworzymy tablice n elementowa bool czyli z wartosciamy 0 lub 1

	for(int i=2; i<=n; i++)                                 //zerowanie tablicy
		m[i] = 0;

	sito(m, n);                                             //wywolanie funkcji sita

	cout<<"Kolejne liczby pierwsze z przedzia³u [2.."<<n<<"]: ";

	for(int i=2;i<=n;i++){
		if(m[i]==0){                                            //jesli wartosc tablicy w dany miejscu pozostal rowny 0, wpisujemy ja do Listy
        insert(&head,i);
}
}
drukuj(head);
zapisdoPliku(head);
return 0;

}
