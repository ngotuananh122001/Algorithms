#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
	int value;
};

vector<Node> dataset;

void del(Node* n) {
	n->value = 0;
}

vector<pair<string, int> > accountData = { {"anhnt", 1}, {"anhcq", 0}, {"chienlv", 1} };


int main() {

    for (int i = 0; i < accountData.size(); i++) {

        string user = accountData[i].first;
        int status = accountData[i].second;
        cout << user << " " << status << "\n";
    }
}



