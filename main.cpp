#include "vectors.h"
using std::cout;
using std::endl;

int main(void) {
  Vector papu(1, 2, 3);
  Vector lince(2, 4, 6);

  cout << "Papu" << endl;
  papu.display();

  cout << "\nLince" << endl;
  lince.display();

  Vector papulince = papu + lince;
  cout << "\nPapuLince"<< endl;
  papulince.display();

  cout << "Locuron tronco" << endl;
}