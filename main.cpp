#include <iostream>
#include "connection.h"
#include <string>

int main(char* ar[], int count)
{
    Connection sn;
    std::string oleg = "Oleg";
    std::string kostya = "Kostya";
    std::string misha = "Misha";
    std::string anya = "Anya";
    std::string lesha = "Lesha";
    std::string lena = "Lena";
    std::string kira = "Kira";


    sn.addFriend(oleg, kostya);
    sn.addFriend(kostya, misha);
    sn.addFriend(misha, anya);
    sn.addFriend(anya, lesha);
    sn.addFriend(kostya, lena);
    sn.addFriend(lena, kira);
    sn.showPeople();
    sn.showIsFriend();

/*
    sn.deleteHuman(kostya);
    sn.showPeople();
    sn.showIsFriend();
*/
    sn.showThreeHandshakes();
    



    return 0;
}