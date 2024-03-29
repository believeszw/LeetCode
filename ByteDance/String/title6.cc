//
// Created by believe on 2020/3/24.
// Copyright (c) 2020 believe. All rights reserved.
//

#include "util.h" // NOLINT
#include <iostream>

// 题号 6 : 简化路径
//
// 以 Unix
// 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。
//
// 在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..）
// 表示将目录切换到上一
//
// 级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux /
// Unix中的绝对路径 vs 相对路径
//
// 请注意，返回的规范路径必须始终以斜杠 /
// 开头，并且两个目录名之间必须只有一个斜杠 /。最后一个目录名（如果存在）
//
// 不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。
//

/*
示例 1:

输入 : "/home/"
输出 : "/home"
解释 : 注意，最后一个目录名后面没有斜杠。

示例 2:

输入 : "/../"
输出 : "/"
解释 : 从根目录向上一级是不可行的，因为根是你可以到达的最高级。

示例 3:

输入 : "/home//foo/"
输出 : "/home/foo"
解释 : 在规范路径中，多个连续斜杠需要用一个斜杠替换。

示例 4:

输入 : "/a/./b/../../c/"
输出 : "/c"

示例 5:

输入 : "/a/../../b/../c//.//"
输出 : "/c"

 示例 6:

输入 : "/a//b////c/d//././/.."
输出 : "/a/b/c"

 */

class Title6 {
public:
  static std::string SimplifyPath(std::string path) {
    std::stringstream is(path);
    std::vector<std::string> vector;
    std::string res = "", tmp = "";

    while (getline(is, tmp, '/')) {
      if (tmp == "" || tmp == ".")
        continue;
      else if (tmp == ".." && !vector.empty())
        vector.pop_back();
      else if (tmp != "..")
        vector.push_back(tmp);
    }

    for (std::string str : vector)
      res += "/" + str;

    if (res.empty())
      return "/";

    return res;
  }
};

TEST(Title6, base) {
  std::string ret;

  std::string str6_1 = "/home/";
  std::string str6_2 = "/home";
  ret = Title6::SimplifyPath(str6_1);
  EXPECT_EQ(str6_2, ret);

  str6_1 = "/../";
  str6_2 = "/";
  ret = Title6::SimplifyPath(str6_1);
  EXPECT_EQ(str6_2, ret);

  str6_1 = "/home//foo/";
  str6_2 = "/home/foo";
  ret = Title6::SimplifyPath(str6_1);
  EXPECT_EQ(str6_2, ret);
}

TEST(ByteStrTitle6, test) {
  std::string ret;
  std::string str6_1 = "/a/./b/../../c/";
  std::string str6_2 = "/c";

  {
    ScopedTimer timer("Title6::SimplifyPath");
    ret = Title6::SimplifyPath(str6_1);
  }
  EXPECT_EQ(str6_2, ret);

  str6_1 = "/a/../../b/../c//.//";
  str6_2 = "/c";
  {
    ScopedTimer timer("Title6::SimplifyPath");
    ret = Title6::SimplifyPath(str6_1);
  }
  EXPECT_EQ(str6_2, ret);

  str6_1 = "/a//b////c/d//././/..";
  str6_2 = "/a/b/c";
  {
    ScopedTimer timer("Title6::SimplifyPath");
    ret = Title6::SimplifyPath(str6_1);
  }
  EXPECT_EQ(str6_2, ret);
}
