#ifndef MEMORY_CHUNK_H
#define MEMORY_CHUNK_H

#include <core/common.h>


/**
 * @class Chunk
 * @author Minh Pham
 * @date 08/28/14
 * @file Chunk.h
 * @brief
 */
struct Chunk {
	unsigned char *pData;     ///< Pointer to allocated memory
	char numFreeBlocks;       ///< Number of available blocks
	char firstFreeBlock;      ///< Index of first available block

	/// Acquire a block of dynamic memory
	void init(size_t blockSize, unsigned char numBlocks);

	/// Return memory for a single block of size blockSize
	void* alloc(size_t blockSize);

	/// Take back memory for a single block at address addr
	void dealloc(void *addr, size_t blockSize);

	/// Release all memory allocated to this chunk
	void release();
};

#endif  // MEMORY_CHUNK_H
