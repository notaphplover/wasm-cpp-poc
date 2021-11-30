#pragma once

#include "BaseException.h"

class UnknownException : BaseException
{
public:
  UnknownException(const std::string& msg);
};

