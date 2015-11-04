#ifndef MEMORY_FIXEDALLOCATOR_H
#define MEMORY_FIXEDALLOCATOR_H

#include <vector>

#include <core/common.h>
#include <memory/chunk.h>

/**
 * @class FixedAllocator
 * @brief Allocate objects of a fixed size
 */
class FixedAllocator {
private:
	typedef std::vector<Chunk> Chunks;

	size_t        m_blockSize;     ///< Size of each block in chunk
	unsigned char m_numBlocks;     ///< Number of blocks per chunk

	Chunks        m_chunks;
	Chunk*        m_allocChunk;    ///< Chunk last allocated from
	Chunk*        m_deallocChunk;  ///< Chunk last deallocated from

public:
	FixedAllocator(size_t blockSize, unsigned char numBlocks);

	/// Allocate one object
	void* allocate();

	/// Deallocate one object
	void deallocate(void *addr);
};

#endif  // MEMORY_FIXEDALLOCATOR_H
