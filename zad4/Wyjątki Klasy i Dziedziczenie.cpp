#include <iostream>
#include "Sales.h"

int main()
{

    using std::cout;
    using std::cin;
    using std::endl;
    double vals[12] = { 1220,1100,1122,2212,1232,2334,
                        2874,2330,3302,2022,3002,2533 };
    double vals2[12] = { 12,11,22,21,32,34,
                         28,29,33,29,32,25 };
    Sales sales1(2011, vals, 12);
    Label_Sales sales2("Blogstar", 2012, vals2, 12);
    cout << "Pierwszy blok try\n";
    try
    {
        int i;
        cout << "Rok = " << sales1.year() << endl;
        for (i = 0; i < 12; i++)
        {
            cout << sales1[i] << " ";
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "Rok = " << sales2.year() << endl;
        cout << "Etykieta: " << sales2.label() << endl;
        for (i = 0; i <= 12; ++i)
        {
            cout << sales2[i] << " ";
            if (i % 6 == 5)
                cout << endl;
        }

        cout << "\n Koniec pierwszego blok try\n";
    }

    catch (Sales::Bad_Index & bi)
    {
        Label_Sales::Nbad_Index* nb;
        cout << bi.what() << endl;
        if (nb = dynamic_cast<Label_Sales::Nbad_Index*>(&bi))
            cout << "Firma: " << nb->label_val() << endl;
        cout << "Niepoprawny index: " << bi.bi_val() << endl;
    }
    cout << "\nKolejny blok\n";
    try
    {
        sales2[2] = 37.5;
        sales1[20] = 23345;
        cout << "Koniec drugiego bloku\n";
    }
    catch (Sales::Bad_Index & bi)
    {
        Label_Sales::Nbad_Index* nb;
        cout << bi.what() << endl;
        if (nb = dynamic_cast<Label_Sales::Nbad_Index*>(&bi))
            cout << "Firma: " << nb->label_val() << endl;
        cout << "Niepoprawny index: " << bi.bi_val() << endl;
    }

    cout  << "Koniec";
    return 0;
       
}
