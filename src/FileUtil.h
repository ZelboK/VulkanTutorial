//
// Created by Danial javady on 2023-06-13.
//

#ifndef VULK_SRC_FILEUTIL_H_
#define VULK_SRC_FILEUTIL_H_

#include <fstream>
namespace FileUtil
{
	std::vector<char> readFile(const std::string& filename);
}

#endif //VULK_SRC_FILEUTIL_H_
