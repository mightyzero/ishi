#include <core/Common.h>
#include <memory/Chunk.h>

void Chunk::init(size_t blockSize, unsigned char numBlocks) {
	ASSERT(blockSize > 0);
	ASSERT(numBlocks > 0);
	
	pData = new unsigned char[blockSize * numBlocks];
	firstFreeBlock = 0;
	numFreeBlocks  = numBlocks;
	
	// Write on first byte of every (unused) block: index of next block
	unsigned char* p = pData;
	for (unsigned int i = 0; i < numBlocks; p += blockSize) {
		*p = ++i;
	}
}

void* Chunk::alloc(size_t blockSize) {
	ASSERT(blockSize > 0);

	// Out of blocks? Return NULL
	if (numFreeBlocks == 0)
		return NULL;
	
	--numFreeBlocks;
	unsigned char pResult = pData + (blockSize * firstFreeBlock);
	// index of next free block: first byte of current block
	firstFreeBlock = *pResult;
	
	return pResult;	
}

void Chunk::dealloc(void* addr, size_t blockSize) {
	ASSERT(addr != NULL);
	ASSERT(addr >= pData);
	ASSERT(blockSize > 0);
	
	unsigned char *pToFree = static_cast<unsigned char*>(addr);
	ASSERT((pToFree - pData) % blockSize == 0);  // Alignment check

	firstFreeBlock = (pToFree - pData) / blockSize;
	ASSERT(firstFreeBlock == (pToFree - pData) / blockSize); // Truncation check
	
	++numFreeBlocks;	
}

void Chunk::release() {
	ASSERT(pData != NULL);

	delete[] pData;
}
