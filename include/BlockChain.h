#ifndef TESTCHAIN_BLOCKCHAIN_H 
#define TESTCHAIN_BLOCKCHAIN_H 

#include <vector>
#include ".\Block.h"

class Blockchain {
public:
    Blockchain();

    void AddBlock(Block bNew);

private:
    uint32_t m_nDifficulty;
    std::vector<Block> m_vChain;

    Block _GetLastBlock() const;
};

#endif // TESTCHAIN_BLOCKCHAIN_H 

