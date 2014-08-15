#ifndef NF_FILE_H
#define NF_FILE_H

/**
Enumeration of file types operated on by File class
*/
enum FileFormatEnum
{
	UNRECOGNIZED,
	TGA,
};

// Enum to type converter
template<FileFormatEnum>
struct FileFormat {};

class File
{
private:
	// Is the file open?
	bool m_isOpen;

	// Mode with which the file is open. Invalid if m_isOpen is false;
	char m_fileMode;

public:
	File();
	bool Read();
	bool Write();
};

#endif // NF_FILE_H