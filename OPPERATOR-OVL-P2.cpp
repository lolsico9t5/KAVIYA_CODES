//Create a class Player with attributes name and score. Overload the > operator to compare two players based on their scores and determine the player with the higher score.  Class Design  Class: Player  Data Members:  string name  int score  Member Functions:  getData()  display()  operator > (Player p) 
#include <iostream>
using namespace std;

class Player {
private:
    string name;
    int score;
public:
    // Function to get data
    void getData() {
        cout << "Enter player name: ";
        cin >> name;
        cout << "Enter score: ";
        cin >> score;
    }
    // Function to display data
    void display() {
        cout << "Name: " << name << ", Score: " << score << endl;
    }
    // Overloading > operator
    bool operator > (Player p) {
        return score > p.score;
    }
};

int main() {
    Player p1, p2;
    cout << "Enter details of Player 1:\n";
    p1.getData();
    cout << "Enter details of Player 2:\n";
    p2.getData();
    
    cout << "\nPlayer Details:\n";
    p1.display();
    p2.display();
    
    // Compare players
    if (p1 > p2) {
        cout << "\nPlayer 1 has higher score.\n";
    } else if (p2 > p1) {
        cout << "\nPlayer 2 has higher score.\n";
    } else {
        cout << "\nBoth players have equal scores.\n";
    }
    return 0;
}