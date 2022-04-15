#include "..\include\BlockChain.h"

Blockchain::Blockchain() {
    m_vChain.emplace_back(Block(0, "Genesis Block"));
    m_nDifficulty = 6;
}

void Blockchain::AddBlock(Block bNew) 
{
    bNew.m_sPrevHash = _GetLastBlock().GetHash();
    bNew.MineBlock(m_nDifficulty);
    m_vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const {
    return m_vChain.back();
}