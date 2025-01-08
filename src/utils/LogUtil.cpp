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
    std::time_t timeNow = std::time(nullptr);
    switch (logLevel) {
        case LogLevel::DEBUG:
            fmt::print(fmt::fg(fmt::color::teal), "[DEBUG] [{:%Y-%m-%d %H:%M:%S}] {}\n", fmt::localtime(timeNow),
                       message);
            break;
        case LogLevel::INFO:
            fmt::print("[INFO] [{:%Y-%m-%d %H:%M:%S}] {} \n", fmt::localtime(timeNow), message);
            break;
        case LogLevel::WARN:
            fmt::print(fmt::fg(fmt::color::green_yellow), "[WARN] [{:%Y-%m-%d %H:%M:%S}] {}\n", fmt::localtime(timeNow),
                       message);
            break;
        case LogLevel::ERROR:
            fmt::print(fmt::fg(fmt::color::indian_red), "[ERROR] [{:%Y-%m-%d %H:%M:%S}] {}\n", fmt::localtime(timeNow),
                       message);
            break;
    }
}
