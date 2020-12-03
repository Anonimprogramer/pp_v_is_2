#include <iostream>
#include <string>
#include "administrative_division.h"
int main() {
    capital Minsk("Minsk",10000000,209600);
    cout << Minsk.imigration(10000)<<endl;
    cout << Minsk.emigration(1000)<< endl;
    cout << Minsk.start_voting_for_chaging_name(100000000,1000,100000,"Putin");
}
