#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "HuffmanTree.hpp"

#define _SIZE_ 1024
#define _FILE_NAME_SIZE_ 128

struct CodeInfo
{
	CodeInfo()
		: code()
		, cnt(0)
	{}

	friend bool operator>(const CodeInfo &left, const CodeInfo &right)
	{
		return left.cnt > right.cnt;
	}

	friend bool operator!=(const CodeInfo &left, const CodeInfo &right)
	{
		return left.cnt != right.cnt;
	}

	friend CodeInfo operator+(const CodeInfo &left, const CodeInfo &right)
	{
		CodeInfo ret;
		ret.cnt = left.cnt + right.cnt;
		return ret;
	}

	unsigned char ch;
	std::string code;	
	long long cnt;		
};


class FileCompress
{
public:
	void Compress(const std::string &FilePath);

	void UnCompress(const std::string &FilePath);

private:
	void GetFileName(const std::string &FilePath, std::string &output);

	void GetPostfixName(const std::string &FilePath, std::string &output);

	void FillInfo(FILE *src);

	void FillCode(const HuffmanTreeNode<CodeInfo> *pRoot);

	void CompressCore(FILE *src, FILE *dst, const std::string &FilePath);

	void SaveCode(FILE *dst, const std::string &FilePath);

	void GetLine(FILE *src, unsigned char *buf, int size);

	void GetHead(FILE *src, std::string &Postfix);

	void UnCompressCore(FILE *input, FILE *output, HuffmanTreeNode<CodeInfo> * pRoot);

private:
	CodeInfo info[256];
};