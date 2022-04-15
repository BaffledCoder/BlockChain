#include "..\include\Block.h"
#include "..\include\sha256.h"
Block::Block(uint32_t indexIn, const std::string& dataIn) :m_nIndex(indexIn), m_sData(dataIn)
{
	m_nNonce = -1;
	m_tTime = time(nullptr);
}

std::string Block::GetHash()
{
	return std::string(m_sHash);
}

void Block::MineBlock(uint32_t difficulty)
{
    // number of zeros at the beginning of the hash == difficulty
    std::string str(difficulty, '0');
    do {
        m_nNonce++;
        m_sHash = _CalculateHash();
    } while (m_sHash.substr(0, difficulty) != str);

    std::cout << "Block mined: " << m_sHash << std::endl;
}

std::string Block::_CalculateHash() const
{
    std::stringstream ss;
    ss << m_nIndex << m_tTime << m_sData << m_nNonce << m_sPrevHash;

    return sha256(ss.str());
}
