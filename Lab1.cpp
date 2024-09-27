#include <iostream>
#include <vector>

using namespace std;

struct Restaurant
{
    string name;    //name of restuarant
    string address; // address of restaurant
    string style;   // food style
    int worldRanking;   // ranking of restaurant
    double reservDifficulty; // reservation difficulty
};

Restaurant restaurant()
{
    string i;
    Restaurant res;
    cout << "name : " << endl;
    getline(cin, res.name);
    
    cout << "address : " << endl;
    getline(cin, res.address);
    
    cout << "style : " << endl;
    getline(cin, res.style);
    
    cout << "ranking : " << endl;
    getline(cin, i);
    res.worldRanking = stoi(i);
    
    cout << "reservDifficulty (1 to 10. 10 is very difficult): " << endl;
    getline(cin, i);
    res.reservDifficulty = stod(i);
    
    return res;
}

void outputs(Restaurant res)
{
    cout << "-----------------------------------------------" << endl;
    cout << "name : " << res.name << endl;
    cout << "address : " << res.address << endl;
    cout << "style : " << res.style << endl;
    cout << "world ranking : " << res.worldRanking << endl;
    cout << "reservation difficulty (1 to 10) : " << res.reservDifficulty << endl;
}

int main()
{
    vector<Restaurant> rest;

    for(int i = 0; i< 4; i++){
        cout << "Restaurant " << i+1 << ": "<< endl;
        rest.push_back(restaurant());
    }

    for(int i = 0; i< rest.size(); i++){
        outputs(rest[i]);
    }

    
    return 0;
}