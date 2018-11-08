#include "pfm.h"
#include <fstream>
#include <stdio.h>

PagedFileManager* PagedFileManager::_pf_manager = 0;

PagedFileManager* PagedFileManager::instance()
{
    if(!_pf_manager)
        _pf_manager = new PagedFileManager();

    return _pf_manager;
}


PagedFileManager::PagedFileManager()
{
}


PagedFileManager::~PagedFileManager()
{
}


RC PagedFileManager::createFile(const string &fileName)
{
	fstream _file;
	_file.open(fileName, ios_base::in);
	if(_file.is_open()) {
//		cout << "Warning, file already exists" << endl;
		_file.close();
		return FAILURE;
	}else {
		_file.clear();
		_file.open(fileName, ios_base::out);
		return SUCCESS;
	}
}


RC PagedFileManager::destroyFile(const string &fileName)
{
	if(remove(fileName.c_str()) != 0)
		return FAILURE;
	else
		return SUCCESS;
}


RC PagedFileManager::openFile(const string &fileName, FileHandle &fileHandle)
{
    return -1;
}


RC PagedFileManager::closeFile(FileHandle &fileHandle)
{
    return -1;
}


FileHandle::FileHandle()
{
    readPageCounter = 0;
    writePageCounter = 0;
    appendPageCounter = 0;
}


FileHandle::~FileHandle()
{
}


RC FileHandle::readPage(PageNum pageNum, void *data)
{
    return -1;
}


RC FileHandle::writePage(PageNum pageNum, const void *data)
{
    return -1;
}


RC FileHandle::appendPage(const void *data)
{
    return -1;
}


unsigned FileHandle::getNumberOfPages()
{
    return -1;
}


RC FileHandle::collectCounterValues(unsigned &readPageCount, unsigned &writePageCount, unsigned &appendPageCount)
{
    return -1;
}
