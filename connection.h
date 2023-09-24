#pragma once
#include <list>
#include <queue>
#include <string>
#include <vector>


class Connection {
  public:
    struct Human {
        Human() = default;
        Human(std::string& name) : _name(name) { _ID = ID++; }
        ~Human(){};
        std::string _name = "";
        int _ID;
    };

    class Floyd {
      public:
        std::vector<std::vector<int>> weights;      
        Floyd() = default;
        ~Floyd() = default;
        void create_matrix(std::vector<std::vector<int>> &matrix);
        void findMinDistancesFloyd (size_t size);
        void print_weights(size_t size);
    };

  private:
    std::list<Human*> people{};
    std::vector<std::vector<int>> friends{};

  public:
    Connection();
    ~Connection() {}

    void addHuman(std::string& name);
    void deleteHuman(std::string& name);
    void addFriend(std::string& name, std::string& nameFriend);
    void showIsFriend();
    void showPeople();
    void showThreeHandshakes();
    static int ID;

  private:
    Connection::Human* isFindByName(std::string& name);
    Connection::Human* findByID(int ID);
    void addInQueue(Connection::Human* human,
                    std::queue<Connection::Human*>& queue,
                    std::vector<bool>& visited);
};
