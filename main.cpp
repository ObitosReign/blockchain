#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <chrono>

using namespace std;

//transaction template
class cTransaction {
	public:
		string sReceiver;
		string sRecipient;
		int nAmount;
};

//block template
class cBlock {
	public:
		int nIndex;
		int nPrevBlockHash;
		int nTimestamp;
		int nNonce;
		vector<cTransaction> transactions;
};

//write block to chain on disk
void writeToDisk(cBlock newBlock) {
	CreateDirectory("chain", NULL);
	ofstream blockFile("./chain/block.txt");
	blockFile<<newBlock.nIndex<<",";
	blockFile<<newBlock.nPrevBlockHash<<",";;
	blockFile<<newBlock.nTimestamp<<",";;
	blockFile<<newBlock.nNonce<<",";;
	blockFile<<"["<<newBlock.transactions[0].sRecipient<<","<<newBlock.transactions[0].sReceiver<<","<<newBlock.transactions[0].nAmount<<"]";
	blockFile.close();
}

//mine a new block
void mineBlock(cBlock newBlock) {
	writeToDisk(newBlock);
}}

//create a transaction
cTransaction createTransaction(std::string receiver, string recipient, int amount) {
	cTransaction newTransaction;
	newTransaction.sReceiver = receiver;
	newTransaction.sRecipient = recipient;
	newTransaction.nAmount = amount;
	return newTransaction;
}

//create the genesis block
void createGenesisBlock() {
	const auto p1 = std::chrono::system_clock::now();
	int nTimestamp = std::chrono::duration_cast<std::chrono::seconds>(p1.time_since_epoch()).count();
	cBlock genesisBlock;
	genesisBlock.nIndex = 0;
	genesisBlock.nPrevBlockHash = 10;
	genesisBlock.nTimestamp = nTimestamp;
	genesisBlock.nNonce = 100;
	genesisBlock.transactions.push_back(createTransaction("1", "0", 1));
	mineBlock(genesisBlock);
	
}

int main() {
	createGenesisBlock();
	return 0;
}