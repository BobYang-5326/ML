#include <iostream>
#include <iomanip>
#include <typeinfo>

using namespace std;

double& lowest(double values[], int length)
{
    int j{};
    for (int i = 0; i < length; ++i) {
        if (values[j] > values[i])
            j = i;
    }
    return values[j];
}
void fun1()
{
    double data[]{3.0, 10.0, 1.5, 15.0, 2.7,
                  23.1, 4.5, 12.0, 6.8, 13.5,
                  2.1, 14.0};
    int len{sizeof(data)/sizeof(data[0])};
    for (auto value :  data) {
        cout << setw(6) << value;
    }
    lowest(data, len) = 6.9;
    lowest(data, len) = 7.9;

    cout << endl;
    for (auto value: data) {
        cout<< setw(6)<<value;
    }
    cout << endl;
}
void record()
{
    static int count{};
    cout << endl << "This is the "<< ++count;
    if((count > 3) &&(count <2)){
        cout << "th";
    }else{
        switch (count%10) {
            case 1:cout << "st"; break;
            case 2:cout << "nd"; break;
            case 3:cout << "rd"; break;
            default: cout << "th";
        }
        cout << " time I have been called.";
    }
}
void fun2()
{
    record();
    for (int i = 0; i <= 3; ++i) {
        record(); //每次调用都会在前值上增加，不会每次初始化。
    }
    cout << endl;
}
//递归调用，2的+-N次方问题
double power(double x, int n)
{
    if (n<0){
        x = 1.0 /x;
        n = -n;
    }
    if(n > 0){
        return  x * power(x,n-1);
    } else {
        return 1.0;
    }
}
void fun3()
{
    double x {2.0};
    double result {};

    for (int index = -3; index  <= 3; ++index) {
        cout << x <<" to the power "<<index
             << " is " << power(x,index)<<endl;
    }
}
long sum(long a,long b);
long product(long a,long b);
void fun4()
{
    long (*pdo_it)(long,long){product};
    cout<< endl<<"3 * 5 = "<<pdo_it(3,5);

    pdo_it = sum;
    cout<<endl <<"3*(4+5)+6 = "<<pdo_it(product(3, pdo_it(4, 5)),6)
        <<endl;
}
long product(long a, long b)
{
    return a*b;
}
long sum(long a,long b)
{
    return a+b;
}

//函数指针作为实参，计算平方和立方
double squared(double);
double cubed(double);
double sumarray(const double data[], size_t len, double (*pfun)(double));

void fun5()
{
    double data[]{1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5};
    size_t len{sizeof(data)/sizeof(data[0])}; //一种用来记录大小的数据类型

    cout << endl << "Sum of squares = "<< sumarray(data, len, squared);
    cout << endl << "Sum of cubes = " << sumarray(data, len, cubed);
    cout << endl;
}
double squared(double x)
{
    return x*x;
}
double cubed(double x)
{
    return x*x*x;
}
double sumarray(const double data[], size_t len, double (*pfun)(double))
{
    double total {};
    for (size_t i = 0; i < len; ++i) {
        total += pfun(data[i]);
    }
    return total;
}
//省略函数实参
void showit(const char message[] = "Something is wrong.");
void fun6()
{
    const char mymess[]{"Then end of the world is nigh."};
    showit();
    showit("Something is terribly wrong!");
    showit();
    showit(mymess);
}
void showit(const char message[])
{
    cout<<endl<<message;
    return;
}
void fun7()
{
   int counts[]{34, 54, 0, 27, 0, 10, 0};
   double time{60};
   int hour{};

    for (auto count: counts) {
        try {
          cout << endl << "Hour " << ++hour;
          if(0 ==count){
              throw "Zero count - calculation not possible.";
          }
          cout<<" minutes pre item: " << time/count;
        }
        catch(const char aMassage[])
        {
            cout<<' '<<aMassage;
        }
    }//for循环的括号

}
void fun8()
{
   int height {};
   const int minHeight {9};
   const int maxHeight {100};
   const double inchesToMeters {0.0254};
   char ch {'y'};

    try {
        while('y' == ch || 'Y' ==ch){
            cout << "Enter a height in inches: ";
            cin >> height;

            try{
                if(height > maxHeight){
                    throw "Heigh exceeds maximum.";
                }
                if(height < minHeight){
                    throw height;
                }
                cout << static_cast<double>(height)*inchesToMeters
                    << " meters" <<endl;
            }//try2
            catch (const char aMessage[]) {
                cout << aMessage << endl;
            }
            cout << "Do you want to continue(y or n)?";
            cin >> ch;
        }
    }//try1
    catch (int badHeight) {
        cout << badHeight <<" inches is below minimum" << endl;
    }
}
//函数重载
int max(const int data[], const size_t len);
long max(const long data[], const size_t len);
double max(const double data[], const size_t len);
//函数模板
template<typename T> T max1(const T x[], const size_t len)
{
    T maxinum {x[0]};
    for (size_t i = 0; i < len; ++i) {
        if(maxinum < x[i]){
            maxinum = x[i];
        }
    }
    return maxinum;
}
void fun9()
{
    int small[] {1, 24, 34, 22};
    long medium[] {23, 245, 123,1, 234, 2345};
    double large[] {23.0, 1.4, 2.456, 345.5, 12.0, 21};

    const size_t lensamll {sizeof(small)/sizeof(small[0])};
    const size_t lenmedium {sizeof(medium)/sizeof(medium[0])};
    const size_t lenlarge {sizeof(large)/sizeof(large[0])};

    cout << endl << max(small,lensamll);
    cout << endl << max(medium, lenmedium);
    cout << endl << max(large, lenlarge);
    cout << endl;

    cout << endl << max1(small,lensamll);
    cout << endl << max1(medium, lenmedium);
    cout << endl << max1(large, lenlarge);
    cout << endl;
}
int max(const int x[], const size_t len)
{
    int maximum {x[0]};
    for (size_t i = 0; i < len; ++i) {
        if(maximum < x[i])
            maximum = x[i];
    }
    return maximum;
}
long max(const long x[], const size_t len)
{
    long maxinum {x[0]};
    for (size_t i = 0; i < len; ++i) {
        if(maxinum < x[i]){
            maxinum = x[i];
        }
    }
    return maxinum;
}
double max(const double x[], size_t len)
{
    double maxinum {x[0]};
    for (size_t i = 0; i < len; ++i) {
        if(maxinum < x[i]){
            maxinum = x[i];
        }
    }
    return maxinum;
}
//decltype定义函数模板
template<typename T1, typename T2> auto
product(T1 v1[],T2 v2[],const size_t count) -> decltype(v1[0]*v2[0])
{
    decltype(v1[0]*v2[0]) sum {};
    for (size_t i {}; i< count; i++) {
        sum = v1[i] *v2[i];
    }
    return sum;
}
//template<typename T1, typename T2>
//auto product(T1 v1[], T2 v2[], const size_t count) -> decltype(v1[0]*v2[0])
//{
//    decltype(v1[0] * v2[0]) sum {};
//    for (size_t i {}; i < count; i++) sum += v1[i] * v2[i];
//    return sum;
//}
void fun10()
{
    double x[] {100.5, 99.5, 88.7, 77.8};
    short y[] {3, 4, 5, 6};
    long z[] {11l, 12l, 13l, 14l};

    size_t n {sizeof(x)/sizeof(x[0])};
    cout << "Result type is "<< typeid(product(x,y,n)).name()<< endl;
    cout << "Ressult is " << product(x,y,n) << endl;
}

int main() {
//    fun1();
//    fun2();
//    fun3();
//    fun4();
//    fun5();
//    fun6();
//    fun7();
//    fun8();
//    fun9();
    fun10();
    return 0;
}

