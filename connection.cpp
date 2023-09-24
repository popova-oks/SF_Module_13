#include "connection.h"
#include <iostream>
#include <queue>

#define SIZE 10

Connection::Connection() {
    friends.resize(SIZE);
    for (int i = 0; i < friends.size(); i++) {
        friends[i].resize(SIZE);
    }
}

void Connection::addHuman(std::string& name) {
    for (Human* curr : people) {
        if (curr->_name == name) {
            std::cout << "This person is already in the list" << std::endl;
            return;
        } else {
            Human* human = new Human(name);
            people.push_back(human);
        }
    }
}

void Connection::deleteHuman(std::string & name) {
    Human* current = isFindByName(name);
    for (int i = 0; i < 10; i++) {
        friends[current->_ID][i] = 0;
        friends[i][current->_ID] = 0;
    }
    people.remove(current);
    delete current;
}

void Connection::addFriend(std::string& name, std::string& nameFriend) {
    Human* current = isFindByName(name);
    Human* friend_current = isFindByName(nameFriend);
    if (current == nullptr) {
        current = new Human(name);
        people.push_back(current);
    }
    if (friend_current == nullptr) {
        friend_current = new Human(nameFriend);
        people.push_back(friend_current);
    }
    friends[current->_ID][friend_current->_ID] = 1;
    friends[friend_current->_ID][current->_ID] = 1;
}

Connection::Human* Connection::isFindByName(std::string& name) {
    for (Human* curr : people) {
        if (curr->_name == name) {
            return curr;
        }
    }
    return nullptr;
}

void Connection::showThreeHandshakes() {
    Floyd floyd;
    size_t size = SIZE;
    floyd.create_matrix(friends);
    floyd.findMinDistancesFloyd(size);
    for (int i = 0; i < SIZE; i++) {        
        if (findByID(i) != nullptr) {
            std::cout << findByID(i)->_name << " : " << std::endl;
            for (int j = 0; j < SIZE; j++) {
                if (i == j) {
                    continue;
                }
                else if (findByID(j) != nullptr && floyd.weights[i][j] <= 3) {
                    std::cout << "\t" << findByID(j)->_name << " ;" << std::endl;
                }
            }
        }
    }
}


void Connection::addInQueue(Connection::Human* human,
                            std::queue<Connection::Human*>& queue,
                            std::vector<bool>& visited) {
    
    
        for (int i = 0; i < people.size(); i++) {
            if (friends[human->_ID][i] == 1 && visited[i] == false) {
                queue.push(findByID(i));
                visited[i] = true;
            }
        }
    
}

Connection::Human* Connection::findByID(int id) {
    for (Human* curr : people) {
        if (curr->_ID == id) {
            return curr;
        }
    }
    return nullptr;
}

void Connection::showIsFriend() {
    std::cout << "\nFriends: \n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (friends[i][j] == 1) {
                std::cout << findByID(i)->_name << " is friend " << findByID(j)->_name << "\n";
            }
        }
    }    
}

void Connection::showPeople() {
    std::cout << "\nList of the people: ";
    for (auto p : people) {
        std::cout << "\t" << p->_name;
    }
}

void Connection::Floyd::create_matrix(std::vector<std::vector<int>>& matrix) {
    weights.resize(SIZE);
    for (int i = 0; i < SIZE; i++) {
        weights[i].resize(SIZE);
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == j) {
                weights [i][j] = 0;
            }
            else if (matrix[i][j] == 1) {
                weights [i][j] = matrix [i][j];
                weights [j][i] = matrix [i][j];
            }
            else {
                weights[i][j] = 1000'000'000;
                weights[j][i] = 1000'000'000;
            }
        }
    }
    size_t size = SIZE;
    print_weights(size);
}

void Connection::Floyd::findMinDistancesFloyd (size_t size) {
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            if (i == k) {
                continue;
            }
            for (int j = 0; j < size; j++) {
                if (j == k) {
                    continue;
                }
                if (weights[i][j] > weights [i][k] + weights[k][j]) {
                    weights[i][j] = weights [i][k] + weights[k][j];
                    weights[j][i] = weights [i][k] + weights[k][j];
                }
            }
        }
    }
    print_weights(size);
}

void Connection::Floyd::print_weights(size_t size) {
    std::cout << "\nWeights: \n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (weights[i][j] < 20) {
                std::cout << weights[i][j] << "\t";
            }
        }
        std::cout << "\n";
    }  
}














int Connection::ID = 0;