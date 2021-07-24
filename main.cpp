#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>

using namespace std;

class cTransaction {
	string receiver;
	string recipient;
	int amount;
};

class cBlock {
	int nIndex;
	int nPrevBlockHash;
	int nTimestamp;
	int nNonce;
	vector<cTransaction> transactions;
};

void setEnvirement() {
	CreateDirectory("chain", NULL);
}

int main() {
	ofstream blockFile("./chain/block.txt");
	blockFile<<"Genesis Block!";
	blockFile.close();
	return 0;
}