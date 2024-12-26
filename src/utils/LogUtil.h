/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-24
 * File: LogUtil
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_UTILS_LOGUTIL_H_
#define GRAPHICS_DEMO_SRC_UTILS_LOGUTIL_H_

#include <string>
#include <format>

enum class LogLevel {
    DEBUG,
    INFO,
    WARN,
    ERROR
};

class LogUtil {
public:
    static LogUtil& getInstance();

    LogUtil(const LogUtil&) = delete;
    LogUtil& operator=(const LogUtil&) = delete;

    static void debug(const std::string& message);
    static void info(const std::string& message);
    static void warning(const std::string& message);
    static void error(const std::string& message);


private:
    LogUtil() = default;

    void log(LogLevel logLevel, const std::string &message);
};


#endif //GRAPHICS_DEMO_SRC_UTILS_LOGUTIL_H_
