#include "BaseException.h"
#include "UnknownException.h"

UnknownException::UnknownException(const std::string& msg): BaseException(msg) {}
