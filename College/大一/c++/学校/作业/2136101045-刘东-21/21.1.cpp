#include <iostream>

using namespace std;
class goods
{
public:
    static void average();
    static void display();
private:
    static double discount;
    static double sum;
    static int n;
};
void goods::average()
{
    sum/n;
}

void goods::display()
{
    cout<<"total:"<<sum<<endl;
    cout<<"average:"<<sum/n<<endl;

}
double goods::discount=0.98;
double goods::sum=100*21.5+12*23.56+5*23.5;
int goods::n=117;


int main()
{
  goods a;
  a.average();
  a.display();

}
