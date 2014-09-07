#include <memory/Chunk.h>
#include <memory/FixedAllocator.h>

FixedAllocator::FixedAllocator(size_t blockSize, unsigned char numBlocks)
	: m_blockSize = blockSize,
	  m_numBlocks = numBlocks,
	  m_allocChunk = NULL,
	  m_deallocChunk = NULL
{}

void* FixedAllocator::allocate() {
	// Do we have space in the last chunk allocated from?
	if (m_allocChunk == 0 || m_allocChunk->numFreeBlocks == 0) {
		// Chunk is not free: search for an empty chunk
		Chunks::iterator i = m_chunks.begin();
		for (;; ++i) {
			if (i->numFreeBlocks > 0) {
				// Found a chunk: Update pointer
				m_allocChunk = &*i;
				break;
			}
			if (i == m_chunks.end()) {
				// Reached end of list: no empty chunk -> allocate new one
				// TODO: should we reserve(size()+1)?
				Chunk newChunk;
				newChunk.Init(m_blockSize, m_numBlocks);
				m_chunks.push_back(newChunk);  // save copy into back of chunks
				
				// Update pointer to object at back of chunks (not stack object)
				m_allocChunk   = &m_chunks.back();
				m_deallocChunk = &m_chunks.back();
				
				break;
			}
		}
		
		// Sanity checks
		ASSERT(allocChunk != NULL);             // Null pointer check
		ASSERT(allocChunk->numFreeBlocks > 0);  // Available space check
		return allocChunk->alloc(m_blockSize);
	}
	
}

void FixedAllocator::deallocate(void *addr) {
	// D
}
