#pragma once

#include <iostream>
#include <string>

class BaseException : public std::exception {
  public:
    virtual const char* what();

  protected:
    BaseException(const std::string& msg);

  private:
    const std::string m_msg;
};
