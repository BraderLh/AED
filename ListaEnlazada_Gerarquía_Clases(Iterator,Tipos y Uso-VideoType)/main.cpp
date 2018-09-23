#include <iostream>
//#include "linkedList.h"
#include "orderedLinkedList.h"
#include "videoListType.h"
#include <fstream>
using std::string;
using namespace std;

void createVideoList(ifstream& infile,videoListType& videoList){
	string title;
	string star1;
	string star2;
	string producer;
	string director;
	string productionCo;
	char ch;
	int inStock;
	videoType newVideo;
	getline(infile, title);
	while (infile){
		getline(infile, star1);
		getline(infile, star2);
		getline(infile, producer);
		getline(infile, director);
		getline(infile, productionCo);
		infile >> inStock;
		infile.get(ch);
		newVideo.setVideoInfo(title, star1, star2, producer,
		director, productionCo, inStock);
		videoList.insertFirst(newVideo);
		getline(infile, title);
	}//end while
}//end createVideoList
void displayMenu(){
    cout << "Selecciona uno de los siguientes:" << endl;
    cout << "1: Para verificar si la tienda tiene un video en particular" << endl;
    cout << "2: Para ver un video." << endl;
    cout << "3: Para verificar en un video." << endl;
    cout << "4: Para verificar si un video en particular está en stock." << endl;
    cout << "5: Para imprimir solo los títulos de todos los videos."<< endl;
    cout << "6: Para imprimir una lista de todos los videos." << endl;
    cout << "9: Salir" << endl;
} //end createVideoList
int main()
{
    unorderedLinkedList<int> list;
    unorderedLinkedList<int> copyList;
    int num;
    cin >> num;
    while (num != -999)
    {
    if (num % 5 == 0 || num % 5 == 3)
    list.insertFirst(num);
    else
    list.insertLast(num);
    cin >> num;
    }
    list.print();
    cout << endl;
    copyList = list;
    copyList.deleteNode(78);
    copyList.deleteNode(35);
    cout << "Copy List = ";
    copyList.print();
    cout << endl;
    /*
    unorderedLinkedList<int> list;
    list.insertFirst(15);
    list.insertLast(28);
    list.insertFirst(30);
    list.insertFirst(2);
    list.insertLast(45);
    list.insertFirst(38);
    list.insertLast(25);
    list.print();
    cout<<endl;
    list.deleteNode(30);
    list.insertFirst(18);
    list.deleteNode(28);
    list.deleteNode(12);
    list.print();
    /*
    videoListType videoList;
    int choice;
    char ch;
    string title;
    ifstream infile;
    //open the input file
    infile.open("videoDat.txt");
    if (!infile)
    {
        cout << "\nEl archivo ingresado no existe "<< "The programa terminara!!!" << endl;
        return 1;
    }
    //create the video list
        createVideoList(infile, videoList);
        infile.close();
        //show the menu
        displayMenu();
        cout << "Ingrese su opcion: ";cin >> choice; //get the request
        cin.get(ch);
        cout << endl;
        //process the requests
        while (choice != 9)
        {
                switch (choice)
            {
                case 1:
                    cout << "Ingrese el titulo: ";
                    getline(cin, title);
                    cout << endl;
                    if (videoList.videoSearch(title))
                        cout << "La tienda lo guardo " << title<< endl;
                    else
                    cout << "La tienda no lo guardo "<< title << endl;
                    break;
                case 2:
                    cout << "Ingrese el Titulo: ";getline(cin, title);
                    cout << endl;
                    if (videoList.videoSearch(title))
                    {
                        if (videoList.isVideoAvailable(title))
                        {
                            videoList.videoCheckOut(title);
                            cout << "Disfrute su pelicula: "<< title << endl;
                        }
                        else
                            cout << "Ahora " << title<< " está agotado." << endl;
                    }
                    else
                        cout << "The store does not carry "<< title << endl;
                    break;
                case 3:
                    cout << "Enter the title: ";getline(cin, title);
                    cout << endl;
                    if (videoList.videoSearch(title))
                    {
                        videoList.videoCheckIn(title);
                        cout << "Thanks for returning "<< title << endl;
                    }
                    else
                        cout << "The store does not carry "<< title << endl;
                    break;
                case 4:
                    cout << "Enter the title: ";getline(cin, title);
                    cout << endl;
                    if (videoList.videoSearch(title))
                    {
                        if (videoList.isVideoAvailable(title))
                            cout << title << " is currently in "<< "stock." << endl;
                        else
                            cout << title << " is currently out "<< "of stock." << endl;
                    }
                    else
                        cout << "The store does not carry "<< title << endl;
                    break;
                case 5:
                    videoList.videoPrintTitle();
                    break;
                case 6:
                    videoList.print();
                    break;
                default:
                    cout << "Seleccion Invalida." << endl;
        }//end switch
        displayMenu(); //display menu
        cout << "Escoja su opcion: ";cin >> choice; //get the next request
        cin.get(ch);
        cout << endl;
    }//end while
    return 0;
    /*
    orderedLinkedList<int> list1, list2; //Line 5
    int num; //Line 6
    cout << "Line 7: Enter numbers ending "<< "with -999." << endl; //Line 7
    cin >> num; //Line 8
    while (num != -999) //Line 9
    { //Line 10
        list1.insert(num); //Line 11
        cin >> num; //Line 12
    } //Line 13
    cout << endl; //Line 14
    cout << "Line 15: list1: "; //Line 15
    list1.print(); //Line 16
    cout << endl; //Line 17
    list2 = list1; //test the assignment operator Line 18
    cout << "Line 19: list2: "; //Line 19
    list2.print(); //Line 20
    cout << endl; //Line 21
    cout << "Line 22: Enter the number to be "<< "deleted: "; //Line 22
    cin >> num;
    cout << endl;
    list2.deleteNode(num);
    cout << "Line 26: After deleting "<< num << ", list2: " << endl; //Line 26
    list2.print();
    cout << endl;
    return 0;*/
}
