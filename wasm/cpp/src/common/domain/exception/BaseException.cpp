#include <iostream>
#include <string>

#include "BaseException.h"

BaseException::BaseException(const std::string& msg)
  : m_msg(msg) {}

const char * BaseException::what() {
  return this->m_msg.data();
}