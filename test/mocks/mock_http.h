#ifndef __MOCK_HTTP_H__
#define __MOCK_HTTP_H__

#include "http/http.h"

#include "gmock/gmock.h"

class MockHTTP : public Ark::Client::IHTTP {
public:
  MOCK_METHOD1(get, std::string(const char*));
  MOCK_METHOD2(post, std::string(const char*, const char*));
};

#endif
