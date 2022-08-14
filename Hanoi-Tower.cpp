/******************************************************************************

Ханойская башня


0   3   6
1   4   7
2   5   8
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

            bool Win()
                {
                    for(int col = 0; col < 7; col += 3)
                        {
                            if(data[col] == 1)
                                {
                                    if (data[col+1] == 2)
                                        return 1;
                                };
                        };
                    return 0;
                };

            void PlayerReplace() // Ход игрока(доделать)
                {
                    int picked_Column = 0;
                    int newPlace = 0;
                    bool ok = 0;

                    cout<<"Выберите столбец с которого хотите переместить блок.\n";
                    while(!ok)
                        {
                            cin>> picked_Column;
                            if((picked_Column < 1) || (picked_Column > 3)) 
                                {
                                    cout<<"Неверное значение стобца.\nВведите номер столбца - от 1 до 3.\n";
                                    ok = 0;
                                }
                                else if(!data[(picked_Column*3)-1])
                                        {
                                            cout<<"Упс, этот столбец пуст!\nВыберите столбец в котором есть блоки.\n";
                                            ok = 0;
                                        }
                                        else ok = 1;
                        };
                    
                    ok = 0;
                    cout<<"Выберите столбец куда будет перемещён блок.\n";
                    while(!ok)
                        {
                            cin>> newPlace;
                            if((newPlace < 1) || (newPlace > 3)) 
                                {
                                    cout<<"Неверное значение стобца.\nВведите номер столбца - от 1 до 3.\n";
                                    ok = 0;
                                }
                                else if(newPlace == picked_Column)
                                        {
                                            cout<<"Блок уже находится на этом стобце.\nВыберите столбец куда будет перемещён блок.\n";
                                            ok = 0;
                                        }
                                        else // проверить что бы нижний блок был не меньше верхнего при переносе.
                                            else ok = 1;

                        };

                     // void move();
                };

            void move(int picked_Column, int newPlace) // перемещение блоков (доделать)
                {
                    block = (block - 1) * 3 ;// для того чтобы получить значение
                    newPlace = (newPlace - 1) * 3;
                    while(!data[block]) block++;

                    while(!data[newPlace + 1]) newPlace++; // неправильно перемещает если стобец полностью пуст
                    
                    box = data[newPlace];
                    data[newPlace] = data[block];
                    // data[block] = box;                    
                };
    };

int main()
{
    srand(time(NULL));
    HanoiTower HT;
    // HT.MyFill();
    // HT.lineshow();
    HT.RandFill();
    
    // HT.data = {1,2,3,0,0,0,0,0,0};
    // if(HT.Win()) cout<<"YOU WIN!\n";
    HT.show();
    
    while(!HT.Win())
        {
            HT.move();
            HT.show();
        };
    

    // HT.move();
    // HT.show();
    if(HT.Win()) cout<<"YOU WIN!\n";
    
    return 0;
}
