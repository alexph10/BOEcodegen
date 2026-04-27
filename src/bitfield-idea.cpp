#include <vector>

using namespace std;

class Group {
  pair<int, int> bitfield;
  friend class Message;
  int x;
  int y;
};

class Message {
  pair<int, int> bitfield;
  // The setter will set all the Groups bitfields too
  vector<Group> group;

public:
  void setGroup(Group g) {
    groups.push_back(g);
    g.bitfield = bitfield;
  }
};

int main() { return 0; }

