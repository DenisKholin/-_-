#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int i, j, k;
double a[5][5], b[5], x[5], xo[5], tmp, eps;
int main()
{
    setlocale(0, "");
    //Чтение матрицы из файла
    ifstream fin("e:\\fa.txt");
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++) fin >> a[i][j];
    for (j = 0; j < 5; j++) fin >> b[j];
    fin.close();
    //Приведение матрицы к нормальному виду
    for (j = 0; j < 5; j++)b[j] = b[j] / a[j][j];
    for (i = 0; i < 5; i++)
    {
        tmp = a[i][i];
        for (j = 0; j < 5; j++) a[i][j] = -a[i][j] / tmp;
        a[i][i] = 0;
    }
    //Начальное приближение
    for (i = 0; i < 5; i++)
    {
        x[i] = b[i];
        xo[i] = b[i];
    }
    //Итерационный цикл
    do {
        for (i = 0; i < 5; i++)
        {
            x[i] = 0;
            for (j = 0; j < 5; j++) x[i] = x[i] + a[i][j] * xo[j];
            x[i] = x[i] + b[i];
        }
        //Проверка сходимости по критерию
        eps = fabs(x[0] - xo[0]);
        for (i = 0; i < 5; i++)
        {
            if (fabs(x[i] - xo[i]) > eps)
                eps = fabs(x[i] - xo[i]);
            xo[i] = x[i];
        }


    } while (eps > 0.001);
    cout << "Решение" << endl;
    for (i = 0; i < 5; i++)
        cout << "x[" << i + 1 << "]=" << x[i] << endl;

    //Чтение матрицы из файла
    ifstream fin_ch("e:\\fa.txt");
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++) fin_ch >> a[i][j];
    for (j = 0; j < 5; j++) fin_ch >> b[j];
    fin_ch.close();
    cout << "&&&&&&&&" << endl;
    cout << "Проверка" << endl;
    cout << "&&&&&&&&" << endl;
    for (i = 0; i < 5; i++)
    {
        tmp = 0;
        for (j = 0; j < 5; j++)
            tmp = tmp + a[i][j] * x[j];
        cout << tmp << " ";
    }
    cout << endl;

    system("pause"); 
}