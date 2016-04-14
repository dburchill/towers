//
//  main.cpp
//  towers
//
//  Created by Dave Burchill on 2015-11-16.
//  Copyright © 2015 burchill.ca. All rights reserved.
//

#include <iostream>


using std::cout;
using std::cin;
using std::endl;

void moveNDisksFromToWithAux(int n, char from, char to, char aux);

int getInt(std::istream&);

int main()
{
    system("clear");
    int n;
    cout<<"\n\t\t*****Tower of Hanoi*****\n";
    cout<<"\t\tEnter number of discs : ";
    n = getInt(std::cin);
    cout<<"\n\n";
    
    moveNDisksFromToWithAux(n,'A','C','B');
    
}

void moveNDisksFromToWithAux(int n,char from, char to, char aux)
{
    //
    // base case
    //
    if(n  ==  1){
        cout<<"\t\tdisc 1 from "<< from << " to " << to <<"\n";
        return;
    }
    
    //
    // recursive case
    //
    
    // move n-1 disks to "aux" tower
    moveNDisksFromToWithAux(n-1, from, aux, to);
    
    // move nth (bottom) disk to "to" tower
    cout<<"\t\tMove disc " << n << " from " << from << " to " << to << "\n";
    
    // move n-1 disks from "aux" tower to "to" tower
    moveNDisksFromToWithAux(n-1, aux, to, from);
    
    
    
}

int getInt(std::istream& is)
{
    int n;
    is >> n;
    while (cin.fail()){
        is.clear();
        is.ignore();
        is >> n;
    }
    return n;
}
