/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-24
 * File: LogUtil
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */


#include "fmt/base.h"
#include "fmt/chrono.h"
#include "fmt/color.h"

#include "LogUtil.h"

LogUtil &LogUtil::getInstance() {
    static LogUtil instance;
    return instance;
}

void LogUtil::debug(const std::string &message) {
    getInstance().log(LogLevel::DEBUG, message);
}

void LogUtil::info(const std::string &message) {
    getInstance().log(LogLevel::INFO, message);
}

void LogUtil::warning(const std::string &message) {
    getInstance().log(LogLevel::WARN, message);
}

void LogUtil::error(const std::string &message) {
    getInstance().log(LogLevel::ERROR, message);
}

void LogUtil::log(LogLevel logLevel, const std::string &message) {
    // 格式化时间，输出年-月-日 小时:分钟:秒
    auto now = std::chrono::system_clock::now();
    switch (logLevel) {
        case LogLevel::DEBUG:
            fmt::print(fmt::fg(fmt::color::blue), "[DEBUG] [{}] {}\n", now, message);
            break;
        case LogLevel::INFO:
            fmt::print("[INFO] [{}] {} \n", now, message);
            break;
        case LogLevel::WARN:
            fmt::print(fmt::fg(fmt::color::yellow), "[WARN] [{}] {}\n", now, message);
            break;
        case LogLevel::ERROR:
            fmt::print(fmt::fg(fmt::color::red), "[ERROR] [{}] {}\n", now, message);
            break;
    }
}
