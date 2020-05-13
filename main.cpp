#include <iostream>
#include <iomanip> //manipulator
#include <cstdlib>
using namespace std;

int count1 {100};

void fun1()
{
// 学习操作符 setw的使用
    int num1{1234}, num2{5678};
    cout<< setw(6)<<num1<<setw(6)<<num2<<endl;
}
void fun2()
{
    char newline{'\n'};
    cout << newline;
    cout << "\"We\'ll make our escapes in sequence\", he said.";
    cout << "\n\t The program\'s over, it\'s time to make a beep beep.\a\a";
    cout <<newline;
}
void fun3()
{
    //calculating how many rolls of wallpaper are required for a room
    double height {}, width {}, length {};
    double perimeter{}; //房间的周长

    const double rollWidth{21.0};
    const double rollLength{12.0*33.0}; //33ft

    int strips_per_roll{};  //每卷可剪裁的条数
    int strips_reqd{};  //所需要的条数
    int nrolls{};  //总共的卷数

    cout << endl
         <<"Enter the height of the room in inches: ";
    cin  >> height;

    cout << endl
         << "Now enter the length and width in inches: ";
    cin >> length >>width;

    strips_per_roll = rollWidth / height;
    perimeter = 2.0 * (length / width);
    strips_reqd = perimeter / rollLength;
    nrolls = strips_reqd / strips_per_roll;

    cout << endl
         << "For your room you need: " << nrolls <<" rolls of wallpaper."
         << endl;
}
void fun4()
{
    int count1{10}, count3{50};
    cout << "value of outer count1 is: "<< count1 <<endl;
    {
        int count1{20}, count2{30};
        cout << "Value of inner count1 is: "<<count1 << endl;
        count1 += 3;
        count3 += count2;
    }
    cout << "Value of outer count1: " << count1 <<endl;
    cout << "Value of outer count3: " << count3 << endl;
}

void fun5() //演示全局变量和局部同名变量对全局变量的隐藏
{
    int count1{10}, count3{30};
    cout << "Value of inner count1: " << count1 <<endl;
    cout << "Value of global count1: " << ::count1 << endl;
    {
        int count1{20},count2{30};
        cout <<"Value of inner count1: " << count1 << endl;
        cout <<"Value of global count1: " << ::count1 << endl;
        count1 +=3;
        count3 +=count2;
    }
    cout <<"Value of out count1: "<< count1 << endl;
    cout <<"Value of out count3: " << count3 <<endl;
}
void fun6() //c11标准枚举
{
    enum class Color: char{Red, Orange,Yellow, Green, Blue, Indigo, Violet}; //Indigo靛蓝色，Violet 紫罗兰色
    Color skycolor{Color::Blue};

    //No auto conversion to numeric type
    cout << "Sky color value: " << static_cast<long>(skycolor) << endl;
    cout << "Increamented sky color: " << static_cast<long>(skycolor) + 10L << endl;
}
void fun7()
{
    char letter{};
    cout << "Enter a letter: ";
    cin >> letter;
    if(letter >= 'A' && letter <= 'Z')
    {
        cout <<"You entered a capital letter.";
    }
    if(letter >= 'a' && letter <= 'z')
    {
        cout << "You entered a lowercase letter.";
    }
}
void fun8()
{
    long number{};
    cout << "Enter an integer number less than 2 billion: ";
    cin >> number;
    if(number % 2L){
        cout << "Your number is an odd." << endl;
    }
    else{
        cout << "Your number is an even." << endl;
    }
}
void fun9()
{
   int nCakes{1};
   cout << "We have " << nCakes << " cake" << (nCakes>1?'s':'.') << endl;
   ++nCakes;
   cout << "We have " << nCakes << " cake" << (nCakes > 1 ? 's' : '1') << endl;
}
void fun10()
{
    const int MAX{20};
    double gas[MAX];
    long miles[MAX];
    int count{};
    char indicator {'y'};

    while (('y' == indicator || 'Y' == indicator) && count < MAX)
    {
        cout << "Enter gas quantity: ";
        cin >> gas[count];
        cout << "Enter odometer reading: ";
        cin >> miles[count];

        ++count;
        cout << "Do you want to enter another (y or n)? ";
        cin >> indicator;
    }


    if(count <= 1)
    {
        cout << "Sorry - at least two reading s are necessary.";
        return;
    }

    for (int i = 0; i < count; ++i) {
        cout << setw(2) << i<< "."
        << "Gas purchased = " << gas[i] << " gallons. "
        <<"resulted in "<< (miles[i] -miles[i -1])/gas[i] << "miles per gallon"<<endl;
    }
}
void fun11()
{
    int value[5]{1,2,3};
    int junc [5];
    for (int i = 0; i < 5; ++i) {
        cout << setw(2) << value[i] << endl;
    }
    for (int j = 0; j < 5; ++j) {
        cout << setw(12) <<junc[j]<<endl;
    }
}
void fun12()
{
    const int plant_row_count{6};
    double beans[][plant_row_count]{
            {12, 15       } ,
            {0,  10,  13,  0,   11,   2},
            {8,  7,   10,  10,  13     },
            {9,  8,   11,  13,  16     }
    };
    double averages[4]{};
    for (int row{}; row < 4; ++row) {
        for (int plant{}; plant < plant_row_count; ++plant) {
            averages[row] += beans[row][plant];
        }
        averages[row] /= plant_row_count;
    }
    cout << "Average production per row is: "<< setiosflags(ios::fixed)<<setprecision(2)<<endl;
    int n{};
    for (double ave : averages) {
        cout << "Row "<< ++n <<setw(10)<<ave<<endl;
    }

}
int main() {

//      fun1();
//      fun2();
//      fun3();
//      fun4();
//      fun5();
//      fun6();
//      fun7();
//      fun8();
//      fun9();
//      fun10();
//      fun11();
        fun12();
    return 0;
}
