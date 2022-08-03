/******************************************************************************

Ханойская башня

*******************************************************************************/

#include <iostream>
#include <array>
#include <vector>
#include <ctime>

using namespace std;

class HanoiTower
    {
        private:
            // array<int, 9> data;
        public:
            HanoiTower()
                {
                    data.fill(0);
                };
            array<int, 9> data; // временно
           
            void MyFill()// временно
                {
                    for(int i = 0; i < 9; i++)
                        data[i] = i;
                };

            void RandFill() // рандомно заполняет столбцы блоками 
                {
                    vector<int> blocks = {1,2,3}; // пул блоков.
                    while(!blocks.empty())
                        {
                            int it_blocks = (rand() % blocks.size()); // итератор блока который будет добавлен.
                            int columm = ((rand() % 3) * 3) + 2; // рандомно выбирается столбец.
                            while(data[columm]) columm--; // если нижняя позиция занята поднимаемся на 1 строку выше.
                            data[columm] = blocks[it_blocks]; // когда находим свободную позицию заполняем её.
                            blocks.erase(blocks.begin() + it_blocks); // удаляем уже вставленный блок.
                        };
                };

            // void lineshow() // временно
            //     {
            //         for(auto & it : data)
            //             cout<<it<<" ";
            //         cout<<endl;
            //     };

            void show() // вывод в виде трёх столбцов
                {
                    for(int i = 0; i < 3; i ++)
                        cout<<data[i]<<"\t"<<data[i+3]<<"\t"<<data[i+6]<<endl;
                };
    };

int main()
{
    srand(time(NULL));
    HanoiTower HT;
    // HT.MyFill();
    // HT.lineshow();
    HT.RandFill();
    HT.show();
    return 0;
}
