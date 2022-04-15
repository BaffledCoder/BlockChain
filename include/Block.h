#ifndef TESTCHAIN_BLOCK_H
#define TESTCHAIN_BLOCK_H

#include <cstdint>
#include <sstream>
#include <iostream>

class Block {
public:
    std::string m_sPrevHash;

    Block(uint32_t indexIn, const std::string& dataIn);
    std::string GetHash();
    void MineBlock(uint32_t difficulty);

private:
    uint32_t m_nIndex;
    int64_t m_nNonce;
    std::string m_sData;
    std::string m_sHash;
    time_t m_tTime;

    std::string _CalculateHash() const;
};

#endif // TESTCHAIN_BLOCK_H