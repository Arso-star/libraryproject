#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Book {
    string title;
    string author;
    string gender;
    int publish_date;
    int publish_year;
    string publisher;
    string language;
};

vector<Book> books = {};

void add_book(){
    string title;
    string author;
    string gender;
    int publish_date;
    int publish_year;
    string publisher;
    string language;

    string confirm;

    cout << "Nome do título: " << endl;
    cin >> title;

    cout << "Nome do autor(a): " << endl;
    cin >> author;

    auto it = find_if(books.begin(), books.end(), [&author](const Book &b){return b.author == author; });

    if (it != books.end())
    {
        cerr << "O livro já existe na biblioteca! Título: " << it->title << endl;
        return;
    }

    cout << "Informe o gênero do livro: " << endl;
    cin >> gender;

    cout << "Data de publicação: " << endl;
    cin >> publish_date;

    cout << "Ano de publicação: " << endl;
    cin >> publish_year;

    cout << "Nome da editora: " << endl;
    cin >> publisher;

    cout << "Linguagem" << endl;
    cin >> language;

    cout << "Preview: " << title << ", " << author << ", " << ", " << gender << ", " << publish_date+publish_year << ", " << publisher << ", " << language;
    cout << "Deseja confirmar? (y/n)" << endl;
    cin >> confirm;
}
void list_book(){}
void update_book(){}
void delete_book(){}
void search_book(){}

void show_menu()
{
    int choice;
    cout << "=====================================" << endl;
    cout << "   BEM-VINDO A BIBLIOTECA DE ARSOS   "<< endl;
    cout << "[1] Adicionar" << endl;
    cout << "[2] Lista" << endl; 
    cout << "[3] Atualizar" << endl; 
    cout << "[4] Deletar" << endl; 
    cout << "[5] Search" << endl; 
    cout << "Escolha a opção:" << endl;
    cin >> choice;
    cout << "=====================================" << endl;
}

int main ()
{
    int choice;

    while (true)
    {
        show_menu();
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cout << "ENTRADA INVÁLIDA. POR FAVOR, TENTE NOVAMENTE." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            add_book();
            break;
        case 2:
            list_book();
            break;
        case 3:
            update_book();
        case 4:
            delete_book();
        case 5:
            search_book();
        default:
            cout << "OPÇÃO INVÁLIDA. TENTE NOVAMENTE." << endl;
            break;
        }
    }
}