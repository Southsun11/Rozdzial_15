#include <iostream>
#include "Sales.h"

void ett()
{
    std::cout << "Nieprzechwycony wyjatek zamykam program\n";
    throw std::bad_exception();
}
int main()
{
    set_terminate(ett);
    set_unexpected(ett);
    using std::cout;
    using std::cin;
    using std::endl;
    double vals[12] = { 1220,1100,1122,2212,1232,2334,2874,23303,3302,2022,3002,2533 };
    double vals2[12] = { 12,11,22,21,32,34,28,29,33,29,32.25 };
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

    catch (Label_Sales::Nbad_Index  &bi)
    {
        cout << bi.what();
        cout << "Firma: " << bi.label_val() << endl;
        cout << "Niepoprawny index: " << bi.bi_val() << endl;
    }
    catch (Sales::Bad_Index & bi)
    {
        cout << bi.what() << endl;
        cout << "Niepoprawny index: " << bi.bi_val() << endl;
    }
    cout << "\nKolejny blok\n";
    try
    {
        sales2[2] = 37.5;
        sales1[20] = 23345;
        cout << "Koniec drugiego bloku\n";
    }
    catch (Label_Sales::Nbad_Index & bi)
    {
        cout << bi.what() << endl;
        cout << "Firma: " << bi.label_val() << endl;
        cout << "Nieporawny index: " << bi.bi_val() << endl;
    }
    catch (Sales::Bad_Index & bi)
    {
        cout << bi.what() << endl;
        cout << "Niepoprawny index: " << bi.bi_val() << endl;
    }

    catch (std::bad_exception & s)
    {
        std::cout << "Nieoczekiany lub nieprzechwycony wyjatek\n";
    }
    cout  << "Koniec";
    return 0;
       
}
